//
//  printer.cpp
//  poly
//
//  Created by Ewart Timothée on 18/08/15.
//  Copyright (c) 2015 Ewart Timothée. All rights reserved.
//

#include "poly/printer.h"
#include "poly/printer.hpp"

namespace poly{


    std::ostream& printer::operator()(std::ostream &ps, std::string const& produce, std::string const& tag ) const {
        time_t t = time(NULL);
        tm* timePtr = localtime(&t);
        ps << "//\n";
        ps << "// " << tag + ".cpp"  <<  "\n";
        ps << "//\n";
        ps << "// Created by Ewart Timothée, " << timePtr->tm_mday
                                               <<"/"<< timePtr->tm_mon+1
                                               <<"/"<< timePtr->tm_year+1900 <<"\n";
        ps << "// Copyright (c) Ewart Timothée. All rights reserved.\n";
        ps << "//\n";
        ps << "// This file is generated automatically, do not edit!\n";
        ps << "// TAG: " << tag << "\n";
        ps << "// Helper:\n";
        ps << "//     h = Horner, e = Estrin, b = BruteForce\n";
        ps << "//     The number indicates the order for Horner\n";
        ps << "//     e.g. h1h3 indicates a produce of polynomial with Horner order 1 and 3\n";
        ps << "//\n";
        ps << "\n";
        ps << "#include <iostream>\n";
        ps << "#include <stdlib.h>\n";
        ps << "\n";
        ps << "#include \"poly/poly.h\"\n";
        ps << "#include \"iacaMarks.h\" /** Intel specific **/\n";
        ps << "\n";
        ps << "int main(int argc, const char* argv []){\n";
        ps << "    double x = atof(argv[1]);\n";
        ps << "    IACA_START\n";
//        ps << "    long long int twok = ((1023 + ((long long int)(1.4426950408889634 * x))) << (52));\n";
//        ps << "    x -= ((double)((int)(1.4426950408889634 * x)))*0.6931471805599453;\n";
 //       ps << "    double  y = " + produce +  "* (*(double *)(&twok));\n";
        ps << "    double  y ="+produce+";\n";
        ps << "    IACA_END\n";
        ps << "\n";
        ps << "    std::cout << \"y: \" << y << std::endl;\n";
        ps << "    return 0;\n";
        ps << "}\n";
        return ps;
    }

    std::ostream& printer::lib(std::ostream &ps, std::string const& produce, std::string const& tag ) const {
        time_t t = time(NULL);
        tm* timePtr = localtime(&t);
        ps << "//\n";
        ps << "// " << tag + "_test.cpp"  <<  "\n";
        ps << "//\n";
        ps << "// Created by Ewart Timothée, " << timePtr->tm_mday
        <<"/"<< timePtr->tm_mon+1
        <<"/"<< timePtr->tm_year+1900 <<"\n";
        ps << "// Copyright (c) Ewart Timothée. All rights reserved.\n";
        ps << "//\n";
        ps << "// This file is generated automatically, do not edit!\n";
        ps << "// TAG: " << tag << "\n";
        ps << "// Helper:\n";
        ps << "//     h = Horner, e = Estrin, b = BruteForce\n";
        ps << "//     The number indicates the order for Horner\n";
        ps << "//     e.g. h1h3 indicates a produce of polynomial with Horner order 1 and 3\n";
        ps << "//\n";
        ps << "#include <limits>\n";
        ps << "#include \"poly/poly.h\"\n";
        ps << "\n";
        ps << "namespace poly {\n";
        ps << "    inline double sse_floor(double a) {\n";
        ps << "        double b;\n";
        ps << "        asm (\"roundsd $1,%1,%0 \" :\"=x\"(b) :\"x\"(a));\n";
        ps << "        return b;\n";
        ps << "    }\n";
        ps << "\n";
        ps << "   static inline uint64_t as_uint64(double x) {\n";
        ps << "       uint64_t i;\n";
        ps << "       memcpy(&i,&x,8);\n";
        ps << "       return i;\n";
        ps << "    }\n";
        ps << "    static inline double as_double(uint64_t i) {\n";
        ps << "        double x;\n";
        ps << "        memcpy(&x,&i,8);\n";
        ps << "        return x;\n";
        ps << "    }\n";
        ps << "\n";
        ps << "    double exp(double x){\n";
        ps << "        uint64_t mask1 = (fabs(x) > 700);\n";
        ps << "        mask1 = (mask1-1);\n";
        ps << "        uint64_t mask2 = (x < 700);\n";
        ps << "        mask2 = ~(mask2-1);\n";
        ps << "        uint64_t mask3 = as_uint64(std::numeric_limits<double>::infinity());\n";
        ps << "        const long long int tmp((long long int)sse_floor(1.4426950408889634 * x));\n";
        ps << "        const long long int twok = (1023 + tmp) << 52;\n";
        ps << "        x -= ((double)(tmp))*0.6931471805599453;\n";
        ps << "        double y = " + produce +  "* (*(double *)(&twok));\n";
        ps << "        uint64_t n = as_uint64(y);\n";
        ps << "        n &= mask1;\n";
        ps << "        mask3 &= ~mask2;\n";
        ps << "        n |= mask3;\n";
        ps << "        return as_double(n);\n";
        ps << "    }\n";
        ps << "} //end namespace \n";
        ps << "\n";
        return ps;
    }


    std::ostream& printer::test(std::ostream &ps, std::string const& produce, std::string const& tag ) const {
        time_t t = time(NULL);
        tm* timePtr = localtime(&t);
        ps << "//\n";
        ps << "// " << tag + "_test.cpp"  <<  "\n";
        ps << "//\n";
        ps << "// Created by Ewart Timothée, " << timePtr->tm_mday
        <<"/"<< timePtr->tm_mon+1
        <<"/"<< timePtr->tm_year+1900 <<"\n";
        ps << "// Copyright (c) Ewart Timothée. All rights reserved.\n";
        ps << "//\n";
        ps << "// This file is generated automatically, do not edit!\n";
        ps << "// TAG: " << tag << "\n";
        ps << "// Helper:\n";
        ps << "//     h = Horner, e = Estrin, b = BruteForce\n";
        ps << "//     The number indicates the order for Horner\n";
        ps << "//     e.g. h1h3 indicates a produce of polynomial with Horner order 1 and 3\n";
        ps << "//\n";
        ps << "\n";
        ps << "#include <iostream>\n";
        ps << "#include <limits>\n";
        ps << "#include <random>\n";
        ps << "#include <cmath>\n";
        ps << "#include <algorithm>\n";
        ps << "#define BOOST_TEST_MODULE poly\n";
        ps << "#include <boost/test/unit_test.hpp>\n";
        ps << "#include <boost/math/special_functions/next.hpp>\n";
        ps << "#include \"poly/poly.h\"\n";
        ps << "\n";
        ps << "double error(0), rms(0);\n";
        ps << "\n";
        ps << "    inline double sse_floor(double a) {\n";
        ps << "        double b;\n";
        ps << "        asm (\"roundsd $1,%1,%0 \" :\"=x\"(b) :\"x\"(a));\n";
        ps << "        return b;\n";
        ps << "    }\n";
        ps << "   static inline uint64_t as_uint64(double x) {\n";
        ps << "       uint64_t i;\n";
        ps << "       memcpy(&i,&x,8);\n";
        ps << "       return i;\n";
        ps << "    }\n";
        ps << "    static inline double as_double(uint64_t i) {\n";
        ps << "        double x;\n";
        ps << "        memcpy(&x,&i,8);\n";
        ps << "        return x;\n";
        ps << "    }\n";
        ps << "    inline double p_compute(){\n";
        ps << "    return (0.5 + std::pow(2.,53) - std::pow(2.,-53));\n";
        ps << "}\n";
        ps << "\n";
        ps << "BOOST_AUTO_TEST_CASE("+tag+"_test){\n";
        ps << "    std::random_device rd;\n";
        ps << "    std::mt19937 gen(rd());\n";
        ps << "    std::uniform_real_distribution<> dis(-700,700);\n";
        ps << "    double max(0.),ulp(0.);\n";
        ps << "    for (int i = 0; i < 1000; ++i){\n";
        ps << "        double x = dis(gen);\n";
        ps << "        double ref = std::exp(x);\n";
        ps << "        uint64_t mask1 = (fabs(x) > 709.089565713);\n";
        ps << "        mask1 = (mask1-1);\n";
        ps << "        uint64_t mask2 = (x < 709.089565713);\n";
        ps << "        mask2 = ~(mask2-1);\n";
        ps << "        uint64_t mask3 = as_uint64(std::numeric_limits<double>::infinity());\n";
        ps << "        const long long int tmp((long long int)sse_floor(1.4426950408889634 * x));\n";
        ps << "        const long long int twok = (1023+tmp) << 52;\n";
        ps << "        x -= ((double)(tmp))*6.93145751953125E-1;\n";
        ps << "        x -= ((double)(tmp))*1.42860682030941723212E-6;\n";
        ps << "        double y = " + produce +  "* (*(double *)(&twok));\n";
        ps << "        uint64_t n = as_uint64(y);\n";
        ps << "        n &= mask1;\n";
        ps << "        mask3 &= ~mask2;\n";
        ps << "        n |= mask3;\n";
        ps << "        y = as_double(n);\n";
        ps << "        BOOST_REQUIRE_CLOSE(y, ref, 0.001);\n";
        ps << "        ulp = boost::math::float_distance(ref,y);\n";
        ps << "        max = std::max(ulp,max);\n";
        ps << "        error = std::abs(y-ref)/ref;\n";
        ps << "        rms += error * error;\n";
        ps << "    }\n";
        ps << "    rms/=100;\n";
        ps << "    std::cout << \""+tag+"\" << \" rms: \"  << std::sqrt(rms) << \" ulp: \" << max << std::endl;\n";
        ps <<"}\n";
        return ps;
    }


    std::ostream& printer::bench_serial(std::ostream &ps, std::string const& produce, std::string const& tag ) const {
        time_t t = time(NULL);
        tm* timePtr = localtime(&t);
        ps << "//\n";
        ps << "// " << tag + "_test.cpp"  <<  "\n";
        ps << "//\n";
        ps << "// Created by Ewart Timothée, " << timePtr->tm_mday
        <<"/"<< timePtr->tm_mon+1
        <<"/"<< timePtr->tm_year+1900 <<"\n";
        ps << "// Copyright (c) Ewart Timothée. All rights reserved.\n";
        ps << "//\n";
        ps << "// This file is generated automatically, do not edit!\n";
        ps << "// TAG: " << tag << "\n";
        ps << "// Helper:\n";
        ps << "//     h = Horner, e = Estrin, b = BruteForce\n";
        ps << "//     The number indicates the order for Horner\n";
        ps << "//     e.g. h1h3 indicates a produce of polynomial with Horner order 1 and 3\n";
        ps << "//\n";
        ps << "\n";
        ps << "#include <iostream>\n";
        ps << "#include <random>\n";
        ps << "#include <cmath>\n";
        ps << "#include <chrono>\n";
        ps << "#include <algorithm>\n";
        ps << "#include <ctime>\n";
        ps << "#include <cstring>\n";
        ps << "#include <limits>\n";
        ps << "#include <iomanip>\n";
        ps << "#include <functional>\n";
        ps << "\n";
        ps << "#include \"poly/poly.h\"\n";
        ps << "\n";
        ps << "    inline double sse_floor(double a) {\n";
        ps << "        double b;\n";
        ps << "        asm (\"roundsd $1,%1,%0 \" :\"=x\"(b) :\"x\"(a));\n";
        ps << "        return b;\n";
        ps << "    }\n";
        ps << "   static inline uint64_t as_uint64(double x) {\n";
        ps << "       uint64_t i;\n";
        ps << "       memcpy(&i,&x,8);\n";
        ps << "       return i;\n";
        ps << "    }\n";
        ps << "    static inline double as_double(uint64_t i) {\n";
        ps << "        double x;\n";
        ps << "        memcpy(&x,&i,8);\n";
        ps << "        return x;\n";
        ps << "    }\n";
        ps << "    double poly_exp(double x){\n";
        ps << "        uint64_t mask1 = (fabs(x) > 700);\n";
        ps << "        mask1 = (mask1-1);\n";
        ps << "        uint64_t mask2 = (x < 700);\n";
        ps << "        mask2 = ~(mask2-1);\n";
        ps << "        uint64_t mask3 = as_uint64(std::numeric_limits<double>::infinity());\n";
        ps << "        const long long int tmp((long long int)sse_floor(1.4426950408889634 * x));\n";
        ps << "        const long long int twok = (1023 + tmp) << 52;\n";
        ps << "        x -= ((double)(tmp))*0.6931471805599453;\n";
        ps << "        double y = " + produce +  "* (*(double *)(&twok));\n";
        ps << "        uint64_t n = as_uint64(y);\n";
        ps << "        n &= mask1;\n";
        ps << "        mask3 &= ~mask2;\n";
        ps << "        n |= mask3;\n";
        ps << "        return as_double(n);\n";
        ps << "    }\n";
        ps << "\n";
        ps << "int main(int argc, char* argv[]){\n";
        ps << "        size_t size = atoi(argv[1]);\n";
        ps << "        double freq = atof(argv[2]);\n";
        ps << "        std::vector<double> buffer(size);\n";
        ps << "        std::vector<double> res(size);\n";
        ps << "        std::random_device rd;\n";
        ps << "        std::mt19937 gen(rd());\n";
        ps << "        std::uniform_real_distribution<> dis(-700,700);\n";
        ps << "        auto rand = std::bind(dis, gen);\n";
        ps << "        std::generate(buffer.begin(), buffer.end(), rand);\n";
        ps << "        double * __restrict p_0 = &res[0];\n";
        ps << "        double * __restrict p_1 = &buffer[0];\n";
        ps << "        int n = buffer.size();\n";
        ps << "        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;\n";
        ps << "        start = std::chrono::high_resolution_clock::now();\n";
        ps << "        for(auto i=0; i < n; ++i)\n";
        ps << "            p_0[i] = poly_exp(p_1[i]);\n";
        ps << "        end = std::chrono::high_resolution_clock::now();\n";
        ps << "        std::chrono::duration<double,std::nano> elapsed_seconds_poly_exp = end-start;\n";
        ps << "        std::cout << \" " <<  tag  << ", TROUGHPUT: \" <<  freq*elapsed_seconds_poly_exp.count()/n << std::endl;\n";
        ps <<"}\n";
        return ps;
    }
//    std::ostream& printer::operator()(std::ostream &ps, std::string const& produce, std::string const& tag ) const {
//
//        ps <<"  template <> \n";
//        ps <<"  struct primitive_op_default<arith_op::"+tag+">{ \n";
//        ps <<"      template <typename V>\n";
//        ps <<"     ALWAYS_INLINE static void run(V &a1, ...) {\n";
//        ps <<"        long long int twok = ((1023 + ((long long int)(1.4426950408889634 * a1))) << (52));\n";
//        ps <<"        a1 -= ((double)((int)(1.4426950408889634 * a1)))*0.6931471805599453;\n";
//        ps <<"        a1 = " + produce +  "* (*(double *)(&twok));\n";
//        ps <<"     };\n";
//        ps <<"     static constexpr bool is_specialized=false;\n";
//        ps <<"  };\n";
//        return ps;
//    }

    void helper_printer(std::vector<produce> const & v){
        printer p;
        for(auto t = v.begin(); t != v.end(); ++t){
            {
                std::string tag("benchmark_"+(*t).tag());
                std::ostringstream buf;
                p.bench_serial(buf,(*t).generate(),tag);
                print<poly::file>(buf,tag);
            }
            {
                std::string tag("test_"+(*t).tag());
                std::ostringstream buf;
                p.test(buf,(*t).generate(),tag);
                print<poly::file>(buf,tag);
            }
        }
    }
}

