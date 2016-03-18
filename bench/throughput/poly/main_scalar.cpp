#include <iostream>
#include <limits>
#include <random>
#include <algorithm>
#include <chrono>
#include <boost/math/special_functions/next.hpp>

namespace poly {
   double poly(double);
}

struct helper{
    const static int size = 0xffffff; 
};

int main(int argc, char * argv[]){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0,std::log(2));

    std::array<double,helper::size> vi;
    std::array<double,helper::size> vo;

    auto rand = std::bind(dis, gen);
    std::generate(vi.begin(), vi.end(), rand);

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    for(int i=0; i<helper::size; ++i){
        vo[i] = poly::poly(vi[i]);
    }

    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::nano> elapsed_seconds_poly_exp = end-start;
    std::cout << elapsed_seconds_poly_exp.count()/helper::size << std::endl;
    double res = std::accumulate(vo.begin(),vo.end(),0.);
    std::cerr << res; //else compiler optimnize and remove the call to exp

    return 0;
}
