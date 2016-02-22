//
// cyme_bd6hkth3d4.cpp
//
// Created by Ewart Timothée, 22/2/2016
// Copyright (c) Ewart Timothée. All rights reserved.
//
// This file is generated automatically, do not edit!
// TAG: cyme_bd6hkth3d4
// Helper:
//     h = Horner, e = Estrin, b = BruteForce
//     The number indicates the order for Horner
//     e.g. h1h3 indicates a produce of polynomial with Horner order 1 and 3
//

#include "cyme/cyme.h"
namespace cyme {

    template<class T, cyme::simd O, int N>
    struct experiment_exp{
        static forceinline vec_simd<T,O,N> exp(vec_simd<T,O,N> x){
            vec_simd<T,O,N> mask0(~(fabs(x) > vec_simd<T,O,N>(exp_limits<T>::max_range())));
            vec_simd<T,O,N> mask1(x < vec_simd<T,O,N>(exp_limits<T>::max_range()));
            vec_simd<T,O,N> mask2(std::numeric_limits<T>::infinity());
            /* calculate k,  k = (int)floor(a); p = (float)k; */
            vec_simd<T,O,N> log2e(1.4426950408889634073599);
            vec_simd<T,O,N> y(x*log2e);
            vec_simd<int,O,N> k = floor(y); // k int
            vec_simd<T,O,N> p(cast<T,O>(k)); // k float
            /* x -= p * log2; */
            vec_simd<T,O,N> c1(6.93145751953125E-1);
            vec_simd<T,O,N> c2(1.42860682030941723212E-6);
#ifdef __FMA__
            x = negatemuladd(p,c1,x);
            x = negatemuladd(p,c2,x);
#else
            x -= p*c1;
            x -= p*c2; // this corection I do not know ><
#endif
            /* Compute e^x using a polynomial approximation */
            x = poly::bruteforce<T,O,N,poly::coeffP6>(x)*poly::horner_kth<T,O,N,poly::coeffP4_3,3>(x);
            /* p = 2^k; */
            p = twok<T,O,N>(k);
            /* e^x = 2^k * e^y */
            x *= p;
            x &= mask0;
            mask2 &= ~mask1;
            x |= mask2;
            return x;
        }
    };
} // end namespace

    typedef double v8float __attribute((vector_size(32)));
    typedef double v4double __attribute((vector_size(32)));
    typedef double v4float __attribute((vector_size(16)));
    typedef double v2double __attribute((vector_size(16)));

    v4double v4dexp(v4double a){
        cyme::vec_simd<double,cyme::avx,1> tmp(a);
        return cyme::experiment_exp<double,cyme::avx,1>::exp(tmp).xmm;
    }

    v2double v2dexp(v2double a){
        cyme::vec_simd<double,cyme::sse,1> tmp(a);
        return cyme::experiment_exp<double,cyme::sse,1>::exp(tmp).xmm;
    }

    v8float v8fexp(v8float a){
        cyme::vec_simd<float,cyme::avx,1> tmp(a);
        return cyme::experiment_exp<float,cyme::avx,1>::exp(tmp).xmm;
    }

    v4float v4fexp(v4float a){
        cyme::vec_simd<float,cyme::sse,1> tmp(a);
        return cyme::experiment_exp<float,cyme::sse,1>::exp(tmp).xmm;
    }
