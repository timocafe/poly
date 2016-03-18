#include <iostream>
#include <limits>
#include <random>
#include <cmath>
#include <algorithm>
#include <boost/math/special_functions/next.hpp>

//some type
typedef double v4double __attribute((vector_size(32)));
typedef double v2double __attribute((vector_size(16)));

#ifdef __x86_64__
v4double v4dpoly(v4double a);
static const int size = 4;
#endif

#ifdef __PPC64__
v2double v2dpoly(v2double a);
static const int size = 2;
#endif



int main(int argc, char * argv[]){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0,std::log(2));
   
    #ifdef __x86_64__
    v4double v1,v2;
    #endif

    #ifdef __PPC64__
    v2double v1,v2;
    #endif

    double x[size];
    double ref[size];
    double ulp[size];
    double m[size];
    double max(0.);

    for(int i=0; i < 1000; ++i){
        for(int j=0; j < size; ++j)
            v1[j] = x[j] = dis(gen);
   
        #if __PPC64__
        v2 = v2dpoly(v1);
        #elif __x86_64__
        v2 = v4dpoly(v1);
        #endif

        for(int j=0; j < size; ++j)
            ref[j] = std::exp(x[j]); 

        for(int j=0; j < size; ++j)
            ulp[j] = boost::math::float_distance(ref[j],v2[j]);
   
        max = std::max(max, *(std::max_element(ulp,ulp+size)));
    }

    std::cout  << max << std::endl;

    return 0;
}
