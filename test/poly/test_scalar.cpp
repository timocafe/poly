#include <iostream>
#include <limits>
#include <random>
#include <cmath>
#include <algorithm>
#include <boost/math/special_functions/next.hpp>

namespace poly {
   double poly(double);
}

int main(int argc, char * argv[]){
    int b(0);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0,std::log(2));
    double max(0.),ulp(0.);

    for(int i=0; i < 1000; ++i){
        double x = dis(gen);
        double ref = std::exp(x);
        double myexp = poly::poly(x);
        ulp = boost::math::float_distance(ref,myexp);
        max = std::max(ulp,max);
    }

    if(max > 15)
        b = 1;

    return b;
}
