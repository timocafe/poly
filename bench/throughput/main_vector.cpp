#include <iostream>
#include <limits>
#include <random>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <boost/math/special_functions/next.hpp>

//some type
typedef double v4double __attribute((vector_size(32)));

//declaration of the function
v4double v4dexp(v4double a);

int main(int argc, char * argv[]){
    int n = atoi(argv[1]);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-700,700);
    double max(0.),ulp(0.);

    std::vector<v4double> vi(n);
    std::vector<v4double> vo(n);

    auto rand = std::bind(dis, gen);
    std::generate(vi.begin(), vi.end(), [&]{ v4double x={rand(),rand(),rand(),rand()}; return x; } );

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();
    for(int i=0; i<n; ++i)
        vo[i] = v4dexp(vi[i]);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::nano> elapsed_seconds_poly_exp = end-start;
    std::cout << elapsed_seconds_poly_exp.count()/n << std::endl;

    return 0;
}
