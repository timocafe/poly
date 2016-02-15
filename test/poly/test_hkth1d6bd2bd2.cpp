//
// test_hkth1d6bd2bd2_test.cpp
//
// Created by Ewart Timothée, 15/2/2016
// Copyright (c) Ewart Timothée. All rights reserved.
//
// This file is generated automatically, do not edit!
// TAG: test_hkth1d6bd2bd2
// Helper:
//     h = Horner, e = Estrin, b = BruteForce
//     The number indicates the order for Horner
//     e.g. h1h3 indicates a produce of polynomial with Horner order 1 and 3
//

#include <iostream>
#include <limits>
#include <random>
#include <cmath>
#include <algorithm>
#define BOOST_TEST_MODULE poly
#include <boost/test/unit_test.hpp>
#include <boost/math/special_functions/next.hpp>
#include "poly/poly.h"

double error(0), rms(0);

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
    inline double p_compute(){
    return (0.5 + std::pow(2.,53) - std::pow(2.,-53));
}

BOOST_AUTO_TEST_CASE(test_hkth1d6bd2bd2_test){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-700,700);
    double max(0.),ulp(0.);
    for (int i = 0; i < 1000; ++i){
        double x = dis(gen);
        double ref = std::exp(x);
        uint64_t mask1 = (fabs(x) > 709.089565713);
        mask1 = (mask1-1);
        uint64_t mask2 = (x < 709.089565713);
        mask2 = ~(mask2-1);
        uint64_t mask3 = as_uint64(std::numeric_limits<double>::infinity());
        const long long int tmp((long long int)sse_floor(1.4426950408889634 * x));
        const long long int twok = (1023+tmp) << 52;
        x -= ((double)(tmp))*6.93145751953125E-1;
        x -= ((double)(tmp))*1.42860682030941723212E-6;
        double y = poly::horner_kth<poly::coeffP6,1>(x)*poly::bruteforce<poly::coeffP2_4>(x)*poly::bruteforce<poly::coeffP2_5>(x)* (*(double *)(&twok));
        uint64_t n = as_uint64(y);
        n &= mask1;
        mask3 &= ~mask2;
        n |= mask3;
        y = as_double(n);
        BOOST_REQUIRE_CLOSE(y, ref, 0.001);
        ulp = boost::math::float_distance(ref,y);
        max = std::max(ulp,max);
        error = std::abs(y-ref)/ref;
        rms += error * error;
    }
    rms/=100;
    std::cout << "test_hkth1d6bd2bd2" << " rms: "  << std::sqrt(rms) << " ulp: " << max << std::endl;
}
