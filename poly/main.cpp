//
//  main.cpp
//  poly
//
//  Created by Ewart Timothée on 18/08/15.
//  Copyright (c) 2015 Ewart Timothée. All rights reserved.
//

#include <iostream>
#include <iomanip>

#include "poly/poly.h"

int main(int argc, const char * argv[]) {


    double a = atof(argv[1]);
    double t(0);
    
    t = horner_kth<1>(a);
    std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1) <<  t << std::endl;

    t = horner_kth<2>(a);
    std::cout << t << std::endl;

    t = horner_kth<3>(a);
    std::cout << t << std::endl;

    t = horner_kth<4>(a);
    std::cout << t << std::endl;

    t = horner_kth<5>(a);
    std::cout << t << std::endl;

    t = horner_kth<6>(a);
    std::cout << t << std::endl;

    t = horner_kth<7>(a);
    std::cout << t << std::endl;

    t = horner_kth<8>(a);
    std::cout << t << std::endl;

    t = horner_kth<9>(a);
    std::cout << t << std::endl;

    t = horner_kth<10>(a);
    std::cout << t << std::endl;

    t = horner_kth<11>(a);
    std::cout << t << std::endl;

    return 0;
}

