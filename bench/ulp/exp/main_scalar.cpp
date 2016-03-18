#include <iostream>
#include <limits>
#include <random>
#include <algorithm>
#include <boost/math/special_functions/next.hpp>

extern "C"{extern double  exp(double v1);}

namespace poly {
   double exp(double);
}

int main(int argc, char * argv[]){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-700,700);
    double max(0.),ulp(0.);

    for(int i=0; i < 1000; ++i){
        double x = dis(gen);
        double ref = std::exp(x);
        #ifdef EXP_VENDOR
        double myexp = exp(x);
        #else
        double myexp = poly::exp(x);
        #endif
        ulp = boost::math::float_distance(ref,myexp);
        max = std::max(ulp,max);
    }

    std::cout  << max << std::endl;
    return 0;
}
