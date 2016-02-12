//
// hkth7d10_test.cpp
//
// Created by Ewart Timothée, 12/2/2016
// Copyright (c) Ewart Timothée. All rights reserved.
//
// This file is generated automatically, do not edit!
// TAG: hkth7d10
// Helper:
//     h = Horner, e = Estrin, b = BruteForce
//     The number indicates the order for Horner
//     e.g. h1h3 indicates a produce of polynomial with Horner order 1 and 3
//

#include <iostream>
#include <limits>
#include <random>
#include <cmath>
#define BOOST_TEST_MODULE poly
#include <boost/test/unit_test.hpp>
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

BOOST_AUTO_TEST_CASE(hkth7d10_test){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-700,700);
    for (int i = 0; i < 100; ++i){
        double x = dis(gen);
        double ref = std::exp(x);
        uint64_t mask1 = (fabs(x) > 709.089565713);
        mask1 = (mask1-1);
        uint64_t mask2 = (x < 709.089565713);
        mask2 = ~(mask2-1);
        uint64_t mask3 = as_uint64(std::numeric_limits<double>::infinity());
        const long long int tmp((long long int)sse_floor(1.4426950408889634 * x));
        const long long int twok = (1023+tmp) << 52;
        x -= ((double)(tmp))*0.6931471805599453;
        double y = poly::horner_kth<poly::coeffP10,7>(x)* (*(double *)(&twok));
        uint64_t n = as_uint64(y);
        n &= mask1;
        mask3 &= ~mask2;
        n |= mask3;
        y = as_double(n);
        BOOST_REQUIRE_CLOSE(y, ref, 0.001);
        error = std::abs(y-ref)/ref;
        rms += error * error;
    }
    rms/=100;
    std::cout << "hkth7d10" << " rms :"  << std::sqrt(rms) <<  std::endl;
}
