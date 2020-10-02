/** Provides implementation of I/O for arith_op enum */

#include <iostream>
#include <string>

#include "primitive_ops.h"

namespace arith_op {

struct name_tbl_entry { int op; const char *name; } name_tbl[]={
                                                                { arith_op::add,  "add" },
                                                                { arith_op::mul,  "mul" },
                                                                { arith_op::fma,  "fma" },
                                                                { arith_op::div,  "div" },
                                                                { arith_op::sqrt, "sqrt" },
                                                                { arith_op::exp , "exp" },
                                                                { arith_op::poly_exp , "scalar::exp" },
                                                                { arith_op::poly_poly , "scalar::poly" },
                                                                { arith_op::poly_twok , "scalar::twok" },
                                                                { arith_op::poly_boundary , "scalar::boundary" },
//                                                              { arith_op::svml4d , "svml4d" },
//                                                              { arith_op::svml2d , "svml2d" },
//                                                              { arith_op::imf , "imf" },
//                                                              { arith_op::mass , "mass" },
//                                                              { arith_op::massv , "massv" },
                                                                { arith_op::v2dexp,  "vector::exp" },
                                                                { arith_op::v4dexp,  "vector::exp" },
                                                                { arith_op::v2dpoly,  "vector::poly" },
                                                                { arith_op::v4dpoly,  "vector::poly" },
                                                                { arith_op::v2dtwok,  "vector::twok" },
                                                                { arith_op::v4dtwok,  "vector::twok" },
                                                                { arith_op::v2dboundary,  "vector::boundary" },
                                                                { arith_op::v4dboundary,  "vector::boundary" },
                                                                // terminal entry
                                                                { 0,0 }
};

const char *name(arith_op op) {
    for (auto e=name_tbl;e->name;++e) { if (e->op==op) return e->name; }
    return "unknown";
}

} // namespace arith_op

std::string to_string(arith_op::arith_op op) { return arith_op::name(op); }

std::ostream &operator<<(std::ostream &O,arith_op::arith_op op) {
    return O << arith_op::name(op);
}

