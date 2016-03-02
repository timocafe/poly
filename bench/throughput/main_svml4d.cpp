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

//declaration of the function
extern "C"{v4double __svml_exp4(v4double v1);}

struct helper{
    const static int size = 0xffffff; 
};

int main(int argc, char * argv[]){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-700,700);

    std::array<v4double,helper::size> vi;
    std::array<v4double,helper::size> vo;

    auto rand = std::bind(dis, gen);
    std::generate(vi.begin(), vi.end(), [&]{ v4double x={rand(),rand(),rand(),rand()}; return x; } );
  
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    for(int i=0; i<helper::size; ++i)
       vo[i] = __svml_exp4(vi[i]);

    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::nano> elapsed_seconds_poly_exp = end-start;
    std::cout << elapsed_seconds_poly_exp.count()/helper::size << std::endl;
   
    return 0;
}
