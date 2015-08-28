#pragma once

#include <vector>

namespace poly {

    class method{
    public:
        method(std::string const& n):name(n){}
        ~method(){};
        std::string const generate(int degree, int offset) const;
    protected:
        std::string name;
    };

    class polynomial{
    public:
        polynomial(method const& p, int d=0):degree(d),pm(p){};
        std::string const generate() const;
    private:
        int degree;
        int offset;        method pm;;
    };

    class produce{
    public:
        void add(method const&p, int d);
        std::string const generate() const;
    private:
        std::vector<polynomial> v;
    };

}

