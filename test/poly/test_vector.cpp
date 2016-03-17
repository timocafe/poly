#include <iostream>
#include <limits>
#include <random>
#include <cmath>
#include <algorithm>
#include <boost/math/special_functions/next.hpp>

//some type
typedef double v4double __attribute((vector_size(32)));

//declaration of the function
v4double v4dpoly(v4double a);

int main(int argc, char * argv[]){
    bool b(0);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-700,700);
    v4double v1,v2;
    double x[4];
    double ref[4];
    double ulp[4];
    double m[4];
    double max(0.);

    for(int i=0; i < 1000; ++i){
        v1[0] = x[0] = dis(gen);
        v1[1] = x[1] = dis(gen);
        v1[2] = x[2] = dis(gen);
        v1[3] = x[3] = dis(gen);

        v2 = v4dpoly(v1);

        ref[0] = std::exp(x[0]);
        ref[1] = std::exp(x[1]);
        ref[2] = std::exp(x[2]);
        ref[3] = std::exp(x[3]);

        ulp[0] = boost::math::float_distance(ref[0],v2[0]);
        ulp[1] = boost::math::float_distance(ref[1],v2[1]);
        ulp[2] = boost::math::float_distance(ref[2],v2[2]);
        ulp[3] = boost::math::float_distance(ref[3],v2[3]);

        max = std::max(max, *(std::max_element(ulp,ulp+4)));
    }

    if(max > 15)
        b = 1;

    return b;
}
