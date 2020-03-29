//COMPLEX.H

#ifndef __COMPLEX_H
#define __COMPLEX_H

#include <utility>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>

class  complex {

public:
    // constructors
    complex(double __re_val, double __im_val=0);
    complex();

    // c++11 move and copy constructors
    complex(const complex &);
    complex(complex &&);

    // complex manipulations
    friend double real(complex &);   // the real part
    friend double imag(complex &);   // the imaginary part
    friend double abs(complex &);  // the module
    friend double arg(complex &);    // the angle
    friend void swap(complex &, complex &); //swap values


    //c++11 move and copy operators
    complex &operator=(const complex&);
    complex &operator=(complex&&);

    // Binary Operator Functions
    friend complex operator+(const complex &, const complex &);
    friend complex operator+(double, const complex &);
    friend complex operator+(const complex &, double);
    friend complex operator-(const complex &, const complex &);
    friend complex operator-(double, const complex &);
    friend complex operator-(const complex &, double);
    friend complex operator*(const complex &, const complex &);
    friend complex operator*(const complex &, double);
    friend complex operator*(double, const complex &);
    friend complex operator/(const complex &, const complex &);
    friend complex operator/(const complex &, double);
    friend complex operator/(double, const complex &);
    friend int operator==(const complex &, const complex &);
    friend int operator!=(const complex &, const complex &);
    friend std::ofstream &operator<<(std::ofstream &, complex&);
    friend std::stringstream &operator<<(std::stringstream &, complex&);
    complex & operator+=(const complex &);
    complex & operator+=(double);
    complex & operator-=(const complex &);
    complex & operator-=(double);
    complex & operator*=(const complex &);
    complex & operator*=(double);
    complex & operator/=(const complex &);
    complex & operator/=(double);
    complex operator+();
    complex operator-();
// Implementation
private:
        double re, im;
};


// Inline complex functions

inline complex::complex(double __re_val, double __im_val)
{
    re = __re_val;
    im = __im_val;
}

inline complex::complex() : re(0), im(0)
{
}

// move and copy constructions c++11

inline complex::complex(const complex &c)
{
    re = c.re;
    im = c.im;
}

inline complex::complex(complex &&c)
{
    re = std::move(c.re);
    im = std::move(c.im);
}


inline complex complex::operator+()
{
    return *this;
}

inline complex complex::operator-()
{
    return complex(-re, -im);
}

inline std::stringstream &operator<<(std::stringstream &out, complex &c)
{
    out << std::to_string(c.re) << "+j*" << std::to_string(c.im);
    return out;
}

// Definition of copy and move operators

inline complex &complex::operator=(const complex &c)
{
    re = c.re;
    im = c.im;
    return *this;
}

inline complex &complex::operator=(complex &&c)
{
    re = std::move(c.re);
    im = std::move(c.im);
    return *this;
}

// Definitions of compound-assignment operator member functions

inline complex & complex::operator+=(const complex & __z2)
{
    re += __z2.re;
    im += __z2.im;
    return *this;
}

inline complex & complex::operator+=(double __re_val2)
{
    re += __re_val2;
    return *this;
}

inline complex & complex::operator-=(const complex & __z2)
{
    re -= __z2.re;
    im -= __z2.im;
    return *this;
}

inline complex & complex::operator-=(double __re_val2)
{
    re -= __re_val2;
    return *this;
}

inline complex & complex::operator*=(const complex & __z2)    //ins
{
    double r = re*__z2.re - im*__z2.im;
    im = re*__z2.im + im*__z2.re;
    re = r;
    return *this;
}

inline complex & complex::operator*=(double __re_val2)
{
    re *= __re_val2;
    im *= __re_val2;
    return *this;
}

inline complex & complex::operator/=(const complex & __z2)   //ins
{
    double d=__z2.re*__z2.re + __z2.im*__z2.im;
    double r =(re*__z2.re + im*__z2.im)/d;
    im =(im*__z2.re - re*__z2.im)/d;
    re =r;
    return *this;
}

inline complex & complex::operator/=(double __re_val2)
{
    re /= __re_val2;
    im /= __re_val2;
    return *this;
}


// Definitions of non-member complex functions

inline double  real(complex & __z)
{
    return __z.re;
}

inline double imag(complex & __z)
{
    return __z.im;
}

inline double abs(complex & __z)
{
    return sqrt(__z.re*__z.re +__z.im*__z.im);
}

inline double arg(complex & __z)
{
    return atan2(__z.im, __z.re);
}


// Definitions of non-member binary operator functions

inline complex operator+(const complex & __z1, const complex & __z2)
{
    return complex(__z1.re + __z2.re, __z1.im + __z2.im);
}

inline complex operator+(double __re_val1, const complex  & __z2)
{
    return complex(__re_val1 + __z2.re, __z2.im);
}

inline complex operator+(const complex & __z1, double __re_val2)
{
    return complex(__z1.re + __re_val2, __z1.im);
}

inline complex operator-(const complex & __z1, const complex & __z2)
{
    return complex(__z1.re - __z2.re, __z1.im - __z2.im);
}

inline complex  operator-(double __re_val1, const complex & __z2)
{
    return complex(__re_val1 - __z2.re, -__z2.im);
}

inline complex  operator-(const complex  & __z1, double __re_val2)
{
    return complex(__z1.re - __re_val2, __z1.im);
}



inline complex  operator*(const complex & __z1, const complex  & __z2)  // ins
{
    return complex(__z1.re*__z2.re - __z1.im*__z2.im,
                   __z1.re*__z2.im + __z1.im*__z2.re);
}

inline complex  operator*(const complex & __z1, double __re_val2)  // ins
{
    return complex(__z1.re*__re_val2 , __z1.im*__re_val2);
}

inline complex  operator*(double __re_val1, const complex  & __z2)
{
    return complex(__z2.re*__re_val1, __z2.im*__re_val1);
}

inline complex  operator/(const complex  & __z1, const complex & __z2)  //ins
{
    double d=__z2.re*__z2.re + __z2.im*__z2.im;
    return complex((__z1.re*__z2.re +__z1.im*__z2.im)/d,
                   (__z1.im*__z2.re -__z1.re*__z2.im)/d);
}

inline complex  operator/(double __re_val1, const complex & __z2)  //ins
{
    double d=__z2.re*__z2.re + __z2.im*__z2.im;
    return complex(__re_val1*__z2.re /d, - __re_val1*__z2.im/d);
}
inline complex  operator/(const complex  & __z1, double __re_val2)
{
    return complex(__z1.re/__re_val2, __z1.im/__re_val2);
}

inline int  operator==(const complex  & __z1, const complex  & __z2)
{
    return __z1.re == __z2.re && __z1.im == __z2.im;
}

inline int  operator!=(const complex & __z1, const complex & __z2)
{
    return __z1.re != __z2.re || __z1.im != __z2.im;
}

inline std::ofstream &operator<<(std::ofstream &out, complex &c)
{
    out << c.re << "+j*" << c.im;
    return out;
}

inline void swap(complex &c1, complex &c2)
{
    double t = c1.re;
    c1.re = c2.re;
    c2.re = t;
    t = c1.im;
    c1.im = c2.im;
    c2.im = t;
}

#endif  // __COMPLEX_H
