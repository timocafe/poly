//
//  printer.h
//  poly
//
//  Created by Ewart Timothée on 18/08/15.
//  Copyright (c) 2015 Ewart Timothée. All rights reserved.
//

#ifndef poly_printer_h
#define poly_printer_h

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <poly/polynomial.h>

namespace poly{

    struct printer{
        std::ostream& operator()(std::ostream& ps, std::string const& produce, std::string const& tag) const;
        std::ostream& test(std::ostream& ps, std::string const& produce, std::string const& tag) const;
        std::ostream& lib(std::ostream& ps, std::string const& produce, std::string const& tag) const;
        std::ostream& bench_serial(std::ostream& ps, std::string const& produce, std::string const& tag) const;
        std::ostream& bench_cyme(std::ostream& ps, std::string const& produce, std::string const& tag) const;
    };
    
    void helper_printer(std::vector<produce> const & v);
}
#endif
