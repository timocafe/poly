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
        ps << "#include \"poly/poly.h\"\n";
        ps << "\n";
        ps << "namespace poly {\n";
        ps << "    inline double sse_floor(double a) {\n";
        ps << "        double b;\n";
        ps << "        asm (\"roundsd $1,%1,%0 \" :\"=x\"(b) :\"x\"(a));\n";
        ps << "        return b;\n";
        ps << "    }\n";
        ps << "\n";
        ps << "    double exp(double x){\n";
        ps << "        long long int twok = ((1023 + ((long long int)sse_floor(1.4426950408889634 * x))) << (52));\n";
        ps << "        x -= ((double)((int)sse_floor(1.4426950408889634 * x)))*0.6931471805599453;\n";
        ps << "        double y = " + produce +  "* (*(double *)(&twok));\n";
        ps << "        return y;\n";
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
        ps << "#include <random>\n";
        ps << "#include <cmath>\n";
        ps << "#define BOOST_TEST_MODULE poly\n";
        ps << "#include <boost/test/unit_test.hpp>\n";
        ps << "#include \"poly/poly.h\"\n";
        ps << "\n";
        ps << "double error(0), rms(0);\n";
        ps << "\n";
        ps << "    inline double sse_floor(double a) {\n";
        ps << "        double b;\n";
        ps << "        asm (\"roundsd $1,%1,%0 \" :\"=x\"(b) :\"x\"(a));\n";
        ps << "        return b;\n";
        ps << "    }\n";
        ps << "\n";
        ps << "BOOST_AUTO_TEST_CASE("+tag+"_test){\n";
        ps << "    std::random_device rd;\n";
        ps << "    std::mt19937 gen(rd());\n";
        ps << "    std::uniform_real_distribution<> dis(-700,700);\n";
        ps << "    for (int i = 0; i < 100; ++i){\n";
        ps << "        double x = dis(gen);\n";
        ps << "        double ref = std::exp(x);\n";
        ps << "        long long int twok = ((1023 + ((long long int)sse_floor(1.4426950408889634 * x))) << (52));\n";
        ps << "        x -= ((double)((long long int)sse_floor(1.4426950408889634 * x)))*0.6931471805599453;\n";
        ps << "        double y = " + produce +  "* (*(double *)(&twok));\n";
        ps << "        BOOST_REQUIRE_CLOSE(y, ref, 0.001);\n";
        ps << "        error = std::abs(y-ref)/ref;\n";
        ps << "        rms += error * error;\n";
        ps << "    }\n";
        ps << "    rms/=100;\n";
        ps << "    std::cout << \""+tag+"\" << \" rms :\"  << std::sqrt(rms) <<  std::endl;\n";
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
            std::string tag((*t).tag());
            std::ostringstream buf;
           // p(buf,(*t).generate(),tag);
            p.test(buf,(*t).generate(),tag);
            print<poly::file>(buf,tag);
        }
    }
}

