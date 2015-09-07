//
// hkth1d8ed2_test.cpp
//
// Created by Ewart Timothée, 7/9/2015
// Copyright (c) Ewart Timothée. All rights reserved.
//
// This file is generated automatically, do not edit!
// TAG: hkth1d8ed2
// Helper:
//     h = Horner, e = Estrin, b = BruteForce
//     The number indicates the order for Horner
//     e.g. h1h3 indicates a produce of polynomial with Horner order 1 and 3
//

#include <random>
#include <cmath>
#define BOOST_TEST_MODULE poly
#include <boost/test/unit_test.hpp>
#include "poly/poly.h"

BOOST_AUTO_TEST_CASE(hkth1d8ed2_test){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, std::log(2));
    for (int i = 0; i < 100; ++i){
        double x = dis(gen);
        double y = poly::horner_kth<poly::coeffP8,1>(x)*poly::estrin<poly::coeffP2_5>(x);
        double ref = std::exp(x);
        BOOST_REQUIRE_CLOSE(y, ref, 0.001);
    }
}
