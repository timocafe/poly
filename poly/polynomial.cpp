
#include <string>
#include "poly/polynomial.h"

namespace poly {

    std::string const method::generate(int degree, int offset) const {
        return name+"<"+std::to_string(degree)+","+std::to_string(offset)+">(x)";
    }

    std::string const polynomial::generate() const{
        return pm.generate(degree,offset);
    }

    std::string const produce::generate() const{
        std::string evaluation;
        for(auto it = v.begin(); it != v.end(); ++it)
            evaluation += it->generate()+"*";
        evaluation.pop_back(); // renove the last "*"
        evaluation += ";";
        return evaluation;
    }

    void produce::add(method const &p, int d){
        v.push_back(polynomial(p,d));
    }
}

