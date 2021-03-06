#ifndef PRIMITIVE_OPS_X86_64H
#define PRIMITIVE_OPS_X86_64H

/** Implementation of primitive ops for x86_64
 *
 *  Should be included automatically from primitive_ops.h and not directly by
 *  other code.
 */

template <>
struct primitive_op<arith_op::add> {
    ALWAYS_INLINE static void run(float &a1,float a2,...) {
        asm volatile ("addss %1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    ALWAYS_INLINE static void run(double &a1,double a2,...) {
        asm volatile ("addsd %1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    ALWAYS_INLINE static void run(v4float &a1,v4float a2,...) {
        asm volatile ("addps %1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    ALWAYS_INLINE static void run(v2double &a1,v2double a2,...) {
        asm volatile ("addpd %1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    ALWAYS_INLINE static void run(v4double &a1,v4double a2,...) {
        asm volatile ("vaddpd %0,%1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    static constexpr bool is_specialized=true;
};

template <>
struct primitive_op<arith_op::sub> {
    ALWAYS_INLINE static void run(float &a1,float a2,...) {
        asm volatile ("subss %1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    ALWAYS_INLINE static void run(double &a1,double a2,...) {
        asm volatile ("subsd %1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    ALWAYS_INLINE static void run(v4float &a1,v4float a2,...) {
        asm volatile ("subps %1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    ALWAYS_INLINE static void run(v2double &a1,v2double a2,...) {
        asm volatile ("subpd %1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    ALWAYS_INLINE static void run(v4double &a1,v4double a2,...) {
        asm volatile ("vsubpd %0,%1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    static constexpr bool is_specialized=true;
};

template <>
struct primitive_op<arith_op::mul> {
    ALWAYS_INLINE static void run(float &a1,float a2,...) {
        asm volatile ("mulss %1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    ALWAYS_INLINE static void run(double &a1,double a2,...) {
        asm volatile ("mulsd %1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    ALWAYS_INLINE static void run(v4float &a1,v4float a2,...) {
        asm volatile ("mulps %1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    ALWAYS_INLINE static void run(v2double &a1,v2double a2,...) {
        asm volatile ("mulpd %1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    ALWAYS_INLINE static void run(v4double &a1,v4double a2,...) {
        asm volatile ("vmulpd %0,%1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    static constexpr bool is_specialized=true;
};

template <>
struct primitive_op<arith_op::fma> {
    ALWAYS_INLINE static void run(float &a1,float a2,float a3,...) {
        asm volatile ("vfmadd132ss %1,%2,%0\n\t" :"+x"(a1) :"x"(a2),"x"(a3));
    }
    ALWAYS_INLINE static void run(double &a1,double a2,double a3,...) {
        asm volatile ("vfmadd132sd %1,%2,%0\n\t" :"+x"(a1) :"x"(a2),"x"(a3));
    }
    ALWAYS_INLINE static void run(v4float &a1,v4float a2,v4float a3,...) {
        asm volatile ("vfmadd132ps %1,%2,%0\n\t" :"+x"(a1) :"x"(a2),"x"(a3));
    }
    ALWAYS_INLINE static void run(v2double &a1,v2double a2,v2double a3,...) {
        asm volatile ("vfmadd132pd %1,%2,%0\n\t" :"+x"(a1) :"x"(a2),"x"(a3));
    }
    ALWAYS_INLINE static void run(v4double &a1,v4double a2,v4double a3,...) {
        asm volatile ("vfmadd132pd %1,%2,%0\n\t" :"+x"(a1) :"x"(a2),"x"(a3));
    }
    static constexpr bool is_specialized=true;
};

template <>
struct primitive_op<arith_op::div> {
    ALWAYS_INLINE static void run(float &a1,float a2,...) {
        asm volatile ("divss %1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    ALWAYS_INLINE static void run(double &a1,double a2,...) {
        asm volatile ("divsd %1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    ALWAYS_INLINE static void run(v4float &a1,v4float a2,...) {
        asm volatile ("divps %1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    ALWAYS_INLINE static void run(v2double &a1,v2double a2,...) {
        asm volatile ("divpd %1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    ALWAYS_INLINE static void run(v4double &a1,v4double a2,...) {
        asm volatile ("vdivpd %1,%0\n\t" :"+x"(a1) :"x"(a2));
    }
    static constexpr bool is_specialized=true;
};

template <>
struct primitive_op<arith_op::sqrt> {
    ALWAYS_INLINE static void run(float &a1,...) {
        asm volatile ("sqrtss %1,%0\n\t" :"=x"(a1) :"0"(a1));
    }
    ALWAYS_INLINE static void run(double &a1,...) {
        asm volatile ("sqrtsd %1,%0\n\t" :"=x"(a1) :"0"(a1));
    }
    ALWAYS_INLINE static void run(v4float &a1,v4float a2,...) {
        asm volatile ("sqrtps %1,%0\n\t" :"+x"(a1) :"0"(a1));
    }
    ALWAYS_INLINE static void run(v2double &a1,v2double a2,...) {
        asm volatile ("sqrtpd %1,%0\n\t" :"+x"(a1) :"0"(a1));
    }
    ALWAYS_INLINE static void run(v4double &a1,v4double a2,...) {
        asm volatile ("vsqrtpd %1,%0\n\t" :"+x"(a1) :"0"(a1));
    }
    static constexpr bool is_specialized=true;
};

inline void consume(float v)  { asm volatile ("" ::"x"(v)); }
inline void consume(double v) { asm volatile ("" ::"x"(v)); }
inline void consume(v4float v)  { asm volatile ("" ::"x"(v)); }
inline void consume(v2double v) { asm volatile ("" ::"x"(v)); }
inline void consume(v4double v) { asm volatile ("" ::"x"(v)); }


#endif // ndef PRIMITIVE_OPS_X86_64H
