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

namespace poly {
    inline double sse_floor(double a) {
        double b;
        #ifdef __x86_64__
        asm ("roundsd $1,%1,%0 " :"=x"(b) :"x"(a));
        #endif
        #ifdef __PPC64__
        asm ("frim %0,%1 " :"=d"(b) :"d"(a));
        #endif
        return b;
    }

    double twok(double x){
        const long long int tmp((long long int)sse_floor(1.4426950408889634 * x));
        const long long int twok = (1023 + tmp) << 52;
        return (*(double *)(&twok));
    }
} //end namespace 

