#include <iostream>
#include <limits>
#include <random>
#include <algorithm>
#include <chrono>
#include <boost/math/special_functions/next.hpp>

extern "C"{extern double  exp(double v1);}

namespace poly {
   double exp(double);
}

struct helper{
    const static int size = 0xffffff; 
};

int main(int argc, char * argv[]){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-700,700);

    std::array<double,helper::size> vi;
    std::array<double,helper::size> vo;

    auto rand = std::bind(dis, gen);
    std::generate(vi.begin(), vi.end(), rand);

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    for(int i=0; i<helper::size; ++i)
        vo[i] = exp(vi[i]);

    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::nano> elapsed_seconds_poly_exp = end-start;
    std::cout << elapsed_seconds_poly_exp.count()/helper::size << std::endl;

    return 0;
}
