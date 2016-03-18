//
// hkth1d4ed2ed2ed2_test.cpp
//
// Created by Ewart Timothée, 17/3/2016
// Copyright (c) Ewart Timothée. All rights reserved.
//
// This file is generated automatically, do not edit!
// TAG: hkth1d4ed2ed2ed2
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
        double y = poly::horner_kth<poly::coeffP4_1,1>(x)*poly::estrin<poly::coeffP2_3>(x)*poly::estrin<poly::coeffP2_4>(x)*poly::estrin<poly::coeffP2_5>(x);
        return y;
    }
} //end namespace 

