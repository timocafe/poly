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
/*
    if(x>709.8 )
	return HUGE_VAL;
    if(x<-708.4)
	return 0;
*/
    long long int twok = ((1023 + ((long long int)(1.4426950408889634 * x))) << (52));
    x -= ((double)((int)(1.4426950408889634 * x)))*0.6931471805599453;
    return poly::bruteforce<poly::coeffP6>(x)*poly::bruteforce<poly::coeffP2_4>(x)*poly::bruteforce<poly::coeffP2_5>(x)* (*(double *)(&twok));
}


int main(int argc, char *argv[]){
    size_t size = atoi(argv[1]);
    std::vector<double> buffer(size);
    std::vector<double> res(size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-7,7);
    auto rand = std::bind(dis, gen);
    std::generate(buffer.begin(), buffer.end(), rand);

    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();
	for(auto i=0; i < buffer.size(); ++i){
		res[i] = poly_exp(buffer[i]);
        }
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds_poly_exp = end-start;

    start = std::chrono::system_clock::now();
	for(auto i=0; i < buffer.size(); ++i){
		res[i] = std::exp(buffer[i]);
        }
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds_machine_exp = end-start;

    std::cout << std::accumulate(res.begin(),res.end(),0) << "\n";
    std::cout << "elapsed time poly: " << elapsed_seconds_poly_exp.count() << "s\n";
    std::cout << "elapsed time machine: " << elapsed_seconds_machine_exp.count() << "s\n";
}
