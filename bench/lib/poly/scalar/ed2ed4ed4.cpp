//
// ed2ed4ed4_test.cpp
//
// Created by Ewart Timothée, 17/3/2016
// Copyright (c) Ewart Timothée. All rights reserved.
//
// This file is generated automatically, do not edit!
// TAG: ed2ed4ed4
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
        double y = poly::estrin<poly::coeffP2_5>(x)*poly::estrin<poly::coeffP4_1>(x)*poly::estrin<poly::coeffP4_2>(x);
        return y;
    }
} //end namespace 

