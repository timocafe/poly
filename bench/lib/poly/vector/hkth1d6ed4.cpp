//
// hkth1d6ed4.cpp
//
// Created by Ewart Timothée, 17/3/2016
// Copyright (c) Ewart Timothée. All rights reserved.
//
// This file is generated automatically, do not edit!
// TAG: hkth1d6ed4
// Helper:
//     h = Horner, e = Estrin, b = BruteForce
//     The number indicates the order for Horner
//     e.g. h1h3 indicates a produce of polynomial with Horner order 1 and 3
//

#include "cyme/cyme.h"
namespace cyme {

    template<class T, cyme::simd O, int N>
    struct experiment_poly{
        static forceinline vec_simd<T,O,N> poly(vec_simd<T,O,N> x){
            x = poly::horner_kth<T,O,N,poly::coeffP6,1>(x)*poly::estrin<T,O,N,poly::coeffP4_3>(x);
            return x;
        }
    };
} // end namespace

#ifdef __x86_64__
    typedef float v8float __attribute((vector_size(32)));
    typedef double v4double __attribute((vector_size(32)));
    typedef float v4float __attribute((vector_size(16)));
    typedef double v2double __attribute((vector_size(16)));

    v4double v4dpoly(v4double a){
        cyme::vec_simd<double,cyme::avx,1> tmp(a);
        return cyme::experiment_poly<double,cyme::avx,1>::poly(tmp).xmm;
    }

    v2double v2dpoly(v2double a){
        cyme::vec_simd<double,cyme::sse,1> tmp(a);
        return cyme::experiment_poly<double,cyme::sse,1>::poly(tmp).xmm;
    }

    v8float v8fpoly(v8float a){
        cyme::vec_simd<float,cyme::avx,1> tmp(a);
        return cyme::experiment_poly<float,cyme::avx,1>::poly(tmp).xmm;
    }

    v4float v4fpoly(v4float a){
        cyme::vec_simd<float,cyme::sse,1> tmp(a);
        return cyme::experiment_poly<float,cyme::sse,1>::poly(tmp).xmm;
    }
#endif
#ifdef __PPC64__
    typedef float v4float __attribute((vector_size(16)));
    typedef double v2double __attribute((vector_size(16)));

    v2double v2dpoly(v2double a){
        cyme::vec_simd<double,cyme::vmx,1> tmp(a);
        return cyme::experiment_poly<double,cyme::vmx,1>::poly(tmp).xmm;
    }

    v4float v4fpoly(v4float a){
        cyme::vec_simd<float,cyme::vmx,1> tmp(a);
        return cyme::experiment_poly<float,cyme::vmx,1>::poly(tmp).xmm;
    }
#endif
