#include <iostream>
#include <random>
#include <cmath>
#include <chrono>
#include <algorithm>
#include <ctime>
#include <cstring>
#include <limits>
#include <iomanip>
#include <functional>

#include "poly/poly.h"

    inline double sse_floor(double a) {
        double b;
        asm ("roundsd $1,%1,%0 " :"=x"(b) :"x"(a));
        return b;
    }

   static inline uint64_t as_uint64(double x) {
       uint64_t i;
       memcpy(&i,&x,8);
       return i;
    }
    static inline double as_double(uint64_t i) {
        double x;
        memcpy(&x,&i,8);
        return x;
    }

    double poly_exp(double x){
        uint64_t mask1 = (fabs(x) > 700);
        mask1 = (mask1-1);
        uint64_t mask2 = (x < 700);
        mask2 = ~(mask2-1);
        uint64_t mask3 = as_uint64(std::numeric_limits<double>::infinity());
        const long long int tmp((long long int)sse_floor(1.4426950408889634 * x));
        const long long int twok = (1023 + tmp) << 52;
        x -= ((double)(tmp))*0.6931471805599453;
        double y = poly::bruteforce<poly::coeffP4_1>(x)*poly::bruteforce<poly::coeffP2_3>(x)*poly::bruteforce<poly::coeffP2_4>(x)*poly::bruteforce<poly::coeffP2_5>(x)* (*(double *)(&twok));
        uint64_t n = as_uint64(y);
        n &= mask1;
        mask3 &= ~mask2;
        n |= mask3;
        return as_double(n);
    }

 //   return poly::horner_kth<poly::coeffP10,2>(x)* (*(double *)(&twok));
//    return poly::bruteforce<poly::coeffP2_5>(x)*poly::horner_kth<poly::coeffP4_1,2>(x)*poly::horner_kth<poly::coeffP4_2,2>(x)* (*(double *)(&twok));
 // return poly::estrin<poly::coeffP10>(x)* (*(double *)(&twok));
//   return poly::bruteforce<poly::coeffP6>(x)*poly::bruteforce<poly::coeffP2_4>(x)*poly::bruteforce<poly::coeffP2_5>(x)* (*(double *)(&twok));


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

//        #pragma clang loop unroll(disable)
//        #pragma clang loop vectorize(disable)
//        #pragma clang loop vectorize_width(4) interleave_count(4)
        for(auto i=0; i < buffer.size(); ++i)
            res[i] = poly_exp(buffer[i]);

    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::nano> elapsed_seconds_poly_exp = end-start;


    std::cout << std::accumulate(res.begin(),res.end(),0) << "\n";
    std::cout << "elapsed time poly: " << elapsed_seconds_poly_exp.count() << " [nano s]\n";

    std::cout << " TROUGHPUT:  \n";
    std::cout << "poly: " << elapsed_seconds_poly_exp.count()/(size) << "\n";
}
