//
//  coefficients.hpp
//  poly
//
//  Created by Ewart Timothée on 18/08/15.
//  Copyright (c) 2015 Ewart Timothée. All rights reserved.
//

#ifndef poly_coefficients_h
#define poly_coefficients_h

#include "poly/method/coefficients/P2.hpp"
#include "poly/method/coefficients/P4.hpp"
#include "poly/method/coefficients/P6.hpp"
#include "poly/method/coefficients/P8.hpp"
#include "poly/method/coefficients/P10.hpp"

namespace poly{

    template< template<int> class C>
    struct poly_order;

    /* P2 family */
    template<>
    struct poly_order<coeffP2_1>
    {
        static const std::size_t value=2;
    };

    template<>
    struct poly_order<coeffP2_2>
    {
        static const std::size_t value=2;
    };

    template<>
    struct poly_order<coeffP2_3>
    {
        static const std::size_t value=2;
    };

    template<>
    struct poly_order<coeffP2_4>
    {
        static const std::size_t value=2;
    };

    template<>
    struct poly_order<coeffP2_5>
    {
        static const std::size_t value=2;
    };

    /*P4 family */
    template<>
    struct poly_order<coeffP4_1>
    {
        static const std::size_t value=4;
    };

    template<>
    struct poly_order<coeffP4_2>
    {
        static const std::size_t value=4;
    };

    template<>
    struct poly_order<coeffP4_3>
    {
        static const std::size_t value=4;
    };

    /*P6 */
    template<>
    struct poly_order<coeffP6>
    {
        static const std::size_t value=6;
    };

    /*P8 */
    template<>
    struct poly_order<coeffP8>
    {
        static const std::size_t value=8;
    };

    /* P10 */
    template<>
    struct poly_order<coeffP10>
    {
        static const std::size_t value=10;
    };
}

#endif
