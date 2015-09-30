//
// bd2bd2ed2ed2hkth1d2_test.cpp
//
// Created by Ewart Timothée, 30/9/2015
// Copyright (c) Ewart Timothée. All rights reserved.
//
// This file is generated automatically, do not edit!
// TAG: bd2bd2ed2ed2hkth1d2
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
BOOST_AUTO_TEST_CASE(bd2bd2ed2ed2hkth1d2_test){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-700,700);
    for (int i = 0; i < 100; ++i){
        double x = dis(gen);
        double ref = std::exp(x);
        long long int twok = ((1023 + ((long long int)(1.4426950408889634 * x))) << (52));
        x -= ((double)((int)(1.4426950408889634 * x)))*0.6931471805599453;
        double y = poly::bruteforce<poly::coeffP2_1>(x)*poly::bruteforce<poly::coeffP2_2>(x)*poly::estrin<poly::coeffP2_3>(x)*poly::estrin<poly::coeffP2_4>(x)*poly::horner_kth<poly::coeffP2_5,1>(x)* (*(double *)(&twok));
        BOOST_REQUIRE_CLOSE(y, ref, 0.001);
        error = std::abs(y-ref)/ref;
        rms += error * error;
    }
    rms/=100;
    std::cout << std::sqrt(rms) <<  std::endl;
}
