#include <iostream>
#include <limits>
#include <random>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <array>
#include <boost/math/special_functions/next.hpp>

//some type
typedef double v4double __attribute((vector_size(32)));
typedef double v2double __attribute((vector_size(16)));

#ifdef __x86_64__
v4double v4dboundary(v4double a);
static const int size = 4;
#endif

#ifdef __PPC64__
v2double v2dboundary(v2double a);
static const int size = 2;
#endif

struct helper{
    const static int size = 0xffffff; 
};

int main(int argc, char * argv[]){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-700,700);
    
    #ifdef __x86_64__
    std::array<v4double,helper::size> vi;
    std::array<v4double,helper::size> vo;
    #endif

    #ifdef __PPC64__
    std::array<v2double,helper::size> vi;
    std::array<v2double,helper::size> vo;
    #endif

    auto rand = std::bind(dis, gen);
    #ifdef __x86_64__
    std::generate(vi.begin(), vi.end(), [&]{ v4double x={rand(),rand(),rand(),rand()}; return x; } );
    #endif
    #ifdef __PPC64__
    std::generate(vi.begin(), vi.end(), [&]{ v2double x={rand(),rand()}; return x; } );
    #endif

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    for(int i=0; i<helper::size; ++i){
        #if __PPC64__
        vo[i] = v2dboundary(vi[i]);
        #elif __x86_64__
        vo[i] = v4dboundary(vi[i]);
        #endif
    }

    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::nano> elapsed_seconds_poly_exp = end-start;
    std::cout << elapsed_seconds_poly_exp.count()/helper::size << std::endl;
   
    return 0;
}
