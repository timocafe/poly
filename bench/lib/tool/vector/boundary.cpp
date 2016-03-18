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
    struct experiment_boundary{
        static forceinline vec_simd<T,O,N> boundary(vec_simd<T,O,N> x){
            vec_simd<T,O,N> mask0(~(fabs(x) > vec_simd<T,O,N>(exp_limits<T>::max_range())));
            vec_simd<T,O,N> mask1(x < vec_simd<T,O,N>(exp_limits<T>::max_range()));
            vec_simd<T,O,N> mask2(std::numeric_limits<T>::infinity());
            x &= mask0;
            mask2 &= ~mask1;
            x |= mask2;
            return x;
        }
    };
} // end namespace

#ifdef __x86_64__
    typedef float v8float __attribute((vector_size(32)));
    typedef double v4double __attribute((vector_size(32)));
    typedef float v4float __attribute((vector_size(16)));
    typedef double v2double __attribute((vector_size(16)));

    v4double v4dboundary(v4double a){
        cyme::vec_simd<double,cyme::avx,1> tmp(a);
        return cyme::experiment_boundary<double,cyme::avx,1>::boundary(tmp).xmm;
    }

    v2double v2dboundary(v2double a){
        cyme::vec_simd<double,cyme::sse,1> tmp(a);
        return cyme::experiment_boundary<double,cyme::sse,1>::boundary(tmp).xmm;
    }

    v8float v8fboundary(v8float a){
        cyme::vec_simd<float,cyme::avx,1> tmp(a);
        return cyme::experiment_boundary<float,cyme::avx,1>::boundary(tmp).xmm;
    }

    v4float v4fboundary(v4float a){
        cyme::vec_simd<float,cyme::sse,1> tmp(a);
        return cyme::experiment_boundary<float,cyme::sse,1>::boundary(tmp).xmm;
    }
#endif
#ifdef __PPC64__
    typedef float v4float __attribute((vector_size(16)));
    typedef double v2double __attribute((vector_size(16)));

    v2double v2dboundary(v2double a){
        cyme::vec_simd<double,cyme::vmx,1> tmp(a);
        return cyme::experiment_boundary<double,cyme::vmx,1>::boundary(tmp).xmm;
    }

    v4float v4fboundary(v4float a){
        cyme::vec_simd<float,cyme::vmx,1> tmp(a);
        return cyme::experiment_boundary<float,cyme::vmx,1>::boundary(tmp).xmm;
    }
#endif
