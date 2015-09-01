//
//  coefficients.h
//  poly
//
//  Created by Ewart Timothée on 18/08/15.
//  Copyright (c) 2015 Ewart Timothée. All rights reserved.
//

#ifndef poly_coefficients_h
#define poly_coefficients_h

    template<int n>
    struct coeff{
        static const std::size_t order_value=10;
    };

    template<>
    struct coeff<0>{
        const static inline double coefficient() {return 1.0000000000000002114940639705245276038539149099858;}
    };

    template<>
    struct coeff<1>{
        const static inline double coefficient() {return 9.9999999999992204062922755139901673043089743845207e-1;}
    };

    template<>
    struct coeff<2>{
        const static inline double coefficient() {return 5.0000000000470407075910575853333558195136495835175e-1;}
    };

    template<>
    struct coeff<3>{
        const static inline double coefficient() {return 1.6666666655683517447526098517565535790685389986567e-1;}
    };

    template<>
    struct coeff<4>{
        const static inline double coefficient() {return 4.1666667972995034755573836934823984390148899855282e-2 ;}
    };

    template<>
    struct coeff<5>{
        const static inline double coefficient() {return 8.3333243238266834234997694128023285974769437237618e-3;}
    };

    template<>
    struct coeff<6>{
        const static inline double coefficient() {return  1.3889273989128108635846229092909917615429232247147e-3;}
    };

    template<>
    struct coeff<7>{
        const static inline double coefficient() {return 1.9830766718527367242381398724699378201454167561602e-4;}
    };

    template<>
    struct coeff<8>{
        const static inline double coefficient() {return  2.4984065458054751527321973285958377956147788917789e-5;}
    };

    template<>
    struct coeff<9>{
        const static inline double coefficient() {return 2.5615650803565837424935479251593631699833183180355e-6 ;}
    };

    template<>
    struct coeff<10>{
        const static inline double coefficient() {return 3.8874526912789884677625679351432816392776740411369e-7;}
    };

    struct poly_order {
        static const std::size_t value=10;
    };

    /*****************************************************************************************************************/

    template<int p, int n>
    struct coeff_factorization;

    /* P0 */
    template<>
    struct coeff_factorization<0,0>{
        const static inline double coefficient() {return 1.000000000000000e00;}
    };

    template<>
    struct coeff_factorization<0,1>{
        const static inline double coefficient() {return 5.863999468698624e-01;}
    };

    template<>
    struct coeff_factorization<0,2>{
        const static inline double coefficient() {return 9.111669706698734e-02;}
    };

    /* P1 */
    template<>
    struct coeff_factorization<1,0>{
        const static inline double coefficient() {return 1.000000000000000e00;}
    };

    template<>
    struct coeff_factorization<1,1>{
        const static inline double coefficient() {return 4.250022501401942e-01;}
    };

    template<>
    struct coeff_factorization<1,2>{
        const static inline double coefficient() {return 7.935993577895180e-02;}
    };

    /* P2 */
    template<>
    struct coeff_factorization<2,0>{
        const static inline double coefficient() {return 1.000000000000000e00;}
    };

    template<>
    struct coeff_factorization<2,1>{
        const static inline double coefficient() {return 1.854407635308873e-01;}
    };

    template<>
    struct coeff_factorization<2,2>{
        const static inline double coefficient() {return 6.057133407964636e-02;}
    };

    /* P3 */
    template<>
    struct coeff_factorization<3,0>{
        const static inline double coefficient() {return 1.000000000000000e00;}
    };

    template<>
    struct coeff_factorization<3,1>{
        const static inline double coefficient() {return -3.311114389316798e-02  ;}
    };

    template<>
    struct coeff_factorization<3,2>{
        const static inline double coefficient() {return 4.034499642737116e-02;}
    };

    /* P4 */
    template<>
    struct coeff_factorization<4,0>{
        const static inline double coefficient() {return 1.000000000000000e00;}
    };

    template<>
    struct coeff_factorization<4,1>{
        const static inline double coefficient() {return -1.637318166478535e-01;}
    };

    template<>
    struct coeff_factorization<4,2>{
        const static inline double coefficient() {return 2.199930801424831e-02;}
    };

#endif
