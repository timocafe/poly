#include <iostream>
#include <limits>
#include <random>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <boost/math/special_functions/next.hpp>

namespace poly {
   double exp(double);
}

int main(int argc, char * argv[]){
    int n = atoi(argv[1]);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-700,700);
    double max(0.),ulp(0.);

    std::vector<double> vi(n,0);
    std::vector<double> vo(n,0);

    auto rand = std::bind(dis, gen);
    std::generate(vi.begin(), vi.end(), rand);

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();
    for(int i=0; i<n; ++i)
        vo[i] = poly::exp(vi[i]);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::nano> elapsed_seconds_poly_exp = end-start;
    std::cout << elapsed_seconds_poly_exp.count()/n << std::endl;

    return 0;
}
