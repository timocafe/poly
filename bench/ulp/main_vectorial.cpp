#include <iostream>
#include <limits>
#include <random>
#include <cmath>
#include <algorithm>
#include <boost/math/special_functions/next.hpp>

//some type
typedef double v4double __attribute((vector_size(32)));

//declaration of the function
v4double v4dexp(v4double a);

int main(int argc, char * argv[]){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-700,700);
    double max(0.),ulp(0.);

    v4double v;

    for(int i=0; i < 1000; ++i){
        v[0] = dis(gen);
        v[1] = dis(gen);
        v[2] = dis(gen);
        v[3] = dis(gen);
        double ref = std::exp(x);
        double myexp = poly::exp(x);
        ulp = boost::math::float_distance(ref,myexp);
        max = std::max(ulp,max);
    }

    std::cout  << max << std::endl;

    return 0;
}
