//
// bd2ed4ed4_test.cpp
//
// Created by Ewart Timothée, 17/3/2016
// Copyright (c) Ewart Timothée. All rights reserved.
//
// This file is generated automatically, do not edit!
// TAG: bd2ed4ed4
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

    double boundary(double x){
        uint64_t mask1 = (fabs(x) > 700);
        mask1 = (mask1-1);
        uint64_t mask2 = (x < 700);
        mask2 = ~(mask2-1);
        uint64_t mask3 = as_uint64(std::numeric_limits<double>::infinity());
        uint64_t n = as_uint64(x);
        n &= mask1;
        mask3 &= ~mask2;
        n |= mask3;
        return as_double(n);
    }
} //end namespace 

