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
        ps << "//     H = Horner, E = Estrin, B = BruteForce\n";
        ps << "//     The number indicates the order for Horner\n";
        ps << "//     e.g. H1H3 indicates a produce of polynomial with Horner order 1 and 3\n";
        ps << "//\n";
        ps << "\n";
        ps << "#include <ostream>\n";
        ps << "#include <stdlib.h>\n";
        ps << "#include \"poly/poly.h\"\n";
        ps << "#include \"poly/iacaMarks.h\"\n";
        ps << "\n";
        ps << "int main(int argc, const char* argv []){\n";
        ps << "    double x = atof(argv[0]);\n";
        ps << "\n";
        ps << "    IACA_START\n";
        ps << "    double y = " + produce + "\n";
        ps << "    IACA_END\n";
        ps << "\n";
        ps << "    std::cout << \"y: \" << y << std::endl;\n";
        ps << "    return 0;\n";
        ps << "}\n";
        return ps;
    }

    void helper_printer(std::vector<produce> const & v){
        printer p;
        for(auto t = v.begin(); t != v.end(); ++t){
            std::string tag((*t).tag());
            std::ostringstream buf;
            p(buf,(*t).generate(),tag);
            print<poly::screen>(buf,tag); // screen or file
        }
    }
}
