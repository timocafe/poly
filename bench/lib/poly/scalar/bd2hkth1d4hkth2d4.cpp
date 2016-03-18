//
// bd2hkth1d4hkth2d4_test.cpp
//
// Created by Ewart Timothée, 17/3/2016
// Copyright (c) Ewart Timothée. All rights reserved.
//
// This file is generated automatically, do not edit!
// TAG: bd2hkth1d4hkth2d4
// Helper:
//     h = Horner, e = Estrin, b = BruteForce
//     The number indicates the order for Horner
//     e.g. h1h3 indicates a produce of polynomial with Horner order 1 and 3
//
#include <limits>
#include <string.h>
#include <cmath>
#include <iostream>
#include "poly/poly.h"

namespace poly {
    double poly(double x){
        double y = poly::bruteforce<poly::coeffP2_5>(x)*poly::horner_kth<poly::coeffP4_1,1>(x)*poly::horner_kth<poly::coeffP4_2,2>(x);
        return y;
    }
} //end namespace 

