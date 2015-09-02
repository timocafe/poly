//
//  printer.hpp
//  poly
//
//  Created by Ewart Timothée on 18/08/15.
//  Copyright (c) 2015 Ewart Timothée. All rights reserved.
//

#ifndef poly_printer_hpp
#define poly_printer_hpp

namespace poly{

    enum device {screen, file};

    template<device d>
    void print(std::ostringstream const& buf, std::string const& tag);

    template<>
    void print<device::screen>(std::ostringstream const& buf , std::string const& tag){
        std::cout << buf.str() << std::endl; // screen, tag argmuent useless here
    }

    template<>
    void print<device::file>(std::ostringstream const& buf, std::string const& tag){
        std::ofstream fout(tag+".cpp");
        fout << buf.str();
        fout.close();
    }
}
#endif
