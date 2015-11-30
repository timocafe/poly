//
// bd8ed2_test.cpp
//
// Created by Ewart Timothée, 30/11/2015
// Copyright (c) Ewart Timothée. All rights reserved.
//
// This file is generated automatically, do not edit!
// TAG: bd8ed2
// Helper:
//     h = Horner, e = Estrin, b = BruteForce
//     The number indicates the order for Horner
//     e.g. h1h3 indicates a produce of polynomial with Horner order 1 and 3
//

#include <iostream>
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

BOOST_AUTO_TEST_CASE(bd8ed2_test){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-700,700);
    for (int i = 0; i < 100; ++i){
        double x = dis(gen);
        double ref = std::exp(x);
        const long long int tmp((long long int)sse_floor(1.4426950408889634 * x));
        const long long int twok = (1023+tmp) << 52;
        x -= ((double)(tmp))*0.6931471805599453;
        double y = poly::bruteforce<poly::coeffP8>(x)*poly::estrin<poly::coeffP2_5>(x)* (*(double *)(&twok));
        BOOST_REQUIRE_CLOSE(y, ref, 0.001);
        error = std::abs(y-ref)/ref;
        rms += error * error;
    }
    rms/=100;
    std::cout << "bd8ed2" << " rms :"  << std::sqrt(rms) <<  std::endl;
}
