#pragma once

#include <vector>

namespace poly {

    class method{
    public:
        method(std::string const& m, int i=0):n(m),it(i){}
        ~method(){};
        std::string  generate() const ;
        std::string const name() const;
        int const iteration() const;
    protected:
        std::string n;
        int it; // 1 for BF, ES, Degree-1 for horner
    };


    class produce{
    public:
        void add(method const& p);
        std::string const generate() const;
    private:
        std::vector<method> v;
    };

}

