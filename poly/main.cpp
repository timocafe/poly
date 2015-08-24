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

    std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1) <<  std::endl;

    t = poly::horner_kth<1>(a);
    std::cout << " Horner order 1 " << t << std::endl;

    t = poly::horner_kth<2>(a);
    std::cout << " Horner order 2 " << t << std::endl;

    t = poly::horner_kth<3>(a);
    std::cout << " Horner order 3 " << t << std::endl;

    t = poly::horner_kth<4>(a);
    std::cout << " Horner order 4 " << t << std::endl;

    t = poly::horner_kth<5>(a);
    std::cout << " Horner order 5 " << t << std::endl;

    t = poly::horner_kth<6>(a);
    std::cout << " Horner order 6 " << t << std::endl;

    t = poly::horner_kth<7>(a);
    std::cout << " Horner order 7 " << t << std::endl;

    t = poly::horner_kth<8>(a);
    std::cout << " Horner order 8 " << t << std::endl;

    t = poly::horner_kth<9>(a);
    std::cout << " Horner order 9 " << t << std::endl;

    t = poly::horner_kth<10>(a);
    std::cout << " Horner order 10 " << t << std::endl;
    
    t = poly::estrin(a);
    std::cout << " Estrin " << t << std::endl;

    t = poly::factorization(a);
    std::cout << " factorization " << t << std::endl;

    t = poly::bruteforce(a);
    std::cout << " bruteforce " << t << std::endl;

    return 0;
}

