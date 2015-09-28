#include <iostream>
#include <random>
#include <cmath>
#include <chrono>
#include <algorithm>
#include <ctime>
#include <limits>
#include <iomanip>

#include "poly/poly.h"

double poly_exp(double x){
    long long int twok = ((1023 + ((long long int)(1.4426950408889634 * x))) << (52));
    x -= ((double)((int)(1.4426950408889634 * x)))*0.6931471805599453;
 //   return poly::horner_kth<poly::coeffP10,2>(x)* (*(double *)(&twok));
//    return poly::bruteforce<poly::coeffP2_5>(x)*poly::horner_kth<poly::coeffP4_1,2>(x)*poly::horner_kth<poly::coeffP4_2,2>(x)* (*(double *)(&twok));
   return poly::estrin<poly::coeffP10>(x)* (*(double *)(&twok));
//   return poly::bruteforce<poly::coeffP6>(x)*poly::bruteforce<poly::coeffP2_4>(x)*poly::bruteforce<poly::coeffP2_5>(x)* (*(double *)(&twok));
}


int main(int argc, char *argv[]){
    size_t size = atoi(argv[1]);
    std::vector<double> buffer(size);
    std::vector<double> res(size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-700,700);
    auto rand = std::bind(dis, gen);
    std::generate(buffer.begin(), buffer.end(), rand);

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    start = std::chrono::high_resolution_clock::now();

    double * __restrict p_0 = &res[0];
    double * __restrict p_1 = &buffer[0];

    for(int k=0; k < 1024; ++k){
        #pragma clang loop vectorize(disable )
        for(int i=0; i < size; ++i)
            res[i] = poly_exp(buffer[i]);
           //p_0[i] = exp(p_1[i]);
    } 
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::nano> elapsed_seconds_machine_exp = end-start;

    
    start = std::chrono::high_resolution_clock::now();
    for(int k=0; k < 1024; ++k){
//        #pragma clang loop vectorize_width(4) interleave_count(4)
//        #pragma clang loop unroll(disable)
        #pragma clang loop vectorize(disable)
        for(auto i=0; i < buffer.size(); ++i)
            res[i] = poly_exp(buffer[i]);
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::nano> elapsed_seconds_poly_exp = end-start;


    std::cout << std::accumulate(res.begin(),res.end(),0) << "\n";
    std::cout << "elapsed time poly: " << elapsed_seconds_poly_exp.count() << " [nano s]\n";
    std::cout << "elapsed time machine: " << elapsed_seconds_machine_exp.count() << " [nano s]\n";

    std::cout << " TROUGHPUT:  \n";
    std::cout << "poly: " << elapsed_seconds_poly_exp.count()/(size*1024) << "\n";
    std::cout << "machine: " << elapsed_seconds_machine_exp.count()/(size*1024) << "\n";
}
