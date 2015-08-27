
#include <string>
#include "poly/polynomial.h"

namespace poly {

    std::string const bf::generate(int d, int o) const {
        return std::string(n)+"<"+std::to_string(d)+","+std::to_string(o)+">(x)";
    }
}
