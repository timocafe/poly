/*
 * Cyme - poly.h, Copyright (c), 2014,
 * Timothee Ewart - Swiss Federal Institute of technology in Lausanne,
 * timothee.ewart@epfl.ch,
 * All rights reserved.
 * This file is part of Cyme <https://github.com/BlueBrain/cyme>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.
 */

/**
 * @file cyme/core/simd_vector/math/detail/poly.h
 * Global include for the polynomial evaluation's method
 */

#ifndef poly_poly_h
#define poly_poly_h

#include "cyme/core/simd_vector/math/detail/method/coefficients/coefficients.ipp"
#include "cyme/core/simd_vector/math/detail/method/bruteforce.ipp"
#include "cyme/core/simd_vector/math/detail/method/horner.ipp"
#include "cyme/core/simd_vector/math/detail/method/estrin.ipp"

#endif
