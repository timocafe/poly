//
// bd10.cpp
//
// Created by Ewart Timothée, 4/3/2016
// Copyright (c) Ewart Timothée. All rights reserved.
//
// This file is generated automatically, do not edit!
// TAG: bd10
// Helper:
//     h = Horner, e = Estrin, b = BruteForce
//     The number indicates the order for Horner
//     e.g. h1h3 indicates a produce of polynomial with Horner order 1 and 3
//

#include "cyme/cyme.h"
namespace cyme {

    template<class T, cyme::simd O, int N>
    struct experiment_twok{
        static forceinline vec_simd<T,O,N> tk(vec_simd<T,O,N> x){
            /* calculate k,  k = (int)floor(a); p = (float)k; */
            vec_simd<int,O,N> k = floor(x); // k int
            vec_simd<T,O,N> p = twok<T,O,N>(k);
            return p;
        }
    };
} // end namespace

#ifdef __x86_64__
    typedef float v8float __attribute((vector_size(32)));
    typedef double v4double __attribute((vector_size(32)));
    typedef float v4float __attribute((vector_size(16)));
    typedef double v2double __attribute((vector_size(16)));

    v4double v4dtwok(v4double a){
        cyme::vec_simd<double,cyme::avx,1> tmp(a);
        return cyme::experiment_twok<double,cyme::avx,1>::tk(tmp).xmm;
    }

    v2double v2dtwok(v2double a){
        cyme::vec_simd<double,cyme::sse,1> tmp(a);
        return cyme::experiment_twok<double,cyme::sse,1>::tk(tmp).xmm;
    }

    v8float v8ftwok(v8float a){
        cyme::vec_simd<float,cyme::avx,1> tmp(a);
        return cyme::experiment_twok<float,cyme::avx,1>::tk(tmp).xmm;
    }

    v4float v4ftwok(v4float a){
        cyme::vec_simd<float,cyme::sse,1> tmp(a);
        return cyme::experiment_twok<float,cyme::sse,1>::tk(tmp).xmm;
    }
#endif
#ifdef __PPC64__
    typedef float v4float __attribute((vector_size(16)));
    typedef double v2double __attribute((vector_size(16)));

    v2double v2dtwok(v2double a){
        cyme::vec_simd<double,cyme::vmx,1> tmp(a);
        return cyme::experiment_twok<double,cyme::vmx,1>::tk(tmp).xmm;
    }

    v4float v4ftwok(v4float a){
        cyme::vec_simd<float,cyme::vmx,1> tmp(a);
        return cyme::experiment_twok<float,cyme::vmx,1>::tk(tmp).xmm;
    }
#endif
