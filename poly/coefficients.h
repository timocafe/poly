//
//  coefficients.h
//  poly
//
//  Created by Ewart Timothée on 18/08/15.
//  Copyright (c) 2015 Ewart Timothée. All rights reserved.
//

#ifndef poly_coefficients_h
#define poly_coefficients_h

    template<std::size_t n>
    struct coeff;

    template<>
    struct coeff<0>{
        const static inline double coefficient() {return 1.000000000000000e00;}
    };

    template<>
    struct coeff<1>{
        const static inline double coefficient() {return -1.545191899282379e-01;}
    };

    template<>
    struct coeff<2>{
        const static inline double coefficient() {return 7.423442481043292e-02;}
    };

    template<>
    struct coeff<3>{
        const static inline double coefficient() {return -9.932076439101219e-03;}
    };

    template<>
    struct coeff<4>{
        const static inline double coefficient() {return 2.002114042280210e-03 ;}
    };

    template<>
    struct coeff<5>{
        const static inline double coefficient() {return -1.632930489243257e-04;}
    };

    template<>
    struct coeff<6>{
        const static inline double coefficient() {return  1.453443972624319e-05;}
    };

    template<>
    struct coeff<7>{
        const static inline double coefficient() {return 1.2384765150e00;}
    };

    template<>
    struct coeff<8>{
        const static inline double coefficient() {return  1.154519189928239e+00;}
    };

    template<>
    struct coeff<9>{
        const static inline double coefficient() {return 6.041609451738876e-01 ;}
    };

    template<>
    struct coeff<10>{
        const static inline double coefficient() {return 1.842481349433290e-01;}
    };

    template<>
    struct coeff<11>{
        const static inline double coefficient() {return 3.475165776945915e-02 ;}
    };


    struct poly_order {
        static const std::size_t value=11;
    };

#endif
