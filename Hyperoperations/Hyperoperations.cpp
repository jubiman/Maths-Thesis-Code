// Hyperoperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <math.h>
#include <fstream>

// Boost libraries
//#include <boost/multiprecision/cpp_int.hpp>             // Defines the Backend type for cpp ints (int1024_t)
//#include <boost/multiprecision/cpp_bin_float.hpp>       // Defines the Backend type for cpp floats

// Local headers
#include "mpfr2.h" // Defines local mpfr algorithm library

// Namespaces
//namespace mp = boost::multiprecision;     // Reduce the typing a bit later...
namespace m = mpfr2;

m::mpfr tetration(m::mpfr, int);
//void rec(mp::cpp_bin_float_oct, int);
//m::mpfr pow(int, mp::int1024_t);

int main()
{

    /*m::mpfr u, res;
    u.setNumber("8175891895781"); res.setNumber("735782758972");

    int r = m::mpfr::multiply(u, res);

    for (int i = u.res_size - 1; i >= 0; i--)
        std::cout << u._a[i];



    char h; std::cin.ignore(); std::cin >> h;
    return 0;*/
    /*std::cout << "Taking input..." << std::endl;
    while (!false) {
        std::string a; int b;
        std::cin >> a >> b;
        m::mpfr t;
        t.setNumber(a); //t2.setNumber(b);
        m::mpfr res = tetration(t, b);

        std::cout << a << "^^" << b << " = " << std::flush;
        std::ofstream f("out.txt");
        for (int i = res.res_size - 1; i >= 0; i--) {
            std::cout << res._a[i];
            f << res._a[i];
        }

        
        std::cout << std::endl << std::endl;
    }*/
    // Hardcoded tests
    int x = 7;
    std::ofstream f("out.txt");
    m::mpfr t;
    for(int b=1; b<x;b++) {
        std::cout << "2^^" << b << std::endl; // Hardcoded message
        t.setNumber("2");
        m::mpfr res = tetration(t, b);
        
        for (int i = res.res_size - 1; i >= 0; i--) {
            std::cout << res._a[i];
            f << res._a[i];
        }
        f << std::endl << std::endl;
        std::cout << std::endl << std::endl;
    }

    char c; std::cin.ignore(); std::cin >> c;
    return 0;
}

/*void rec(m::mpfr a, int b) {
    if (a._a >= std::numeric_limits<mp::cpp_bin_float_oct>::max()) return;
    m::mpfr c = tetration(a, b);
    m::mpfr t = tetration(a, b);
    for(int i = 0; i<sizeof(t._a)/sizeof(*t._a); ++i)
        std::cout << t._a[i] << std::endl;
    rec(c._a, b);
}*/

// Tetration function, only takes x^^n with n > 0
m::mpfr tetration(m::mpfr a, int b)
{
    m::mpfr tmp = a;
    if (b <= 0) return m::mpfr();
    for (; b > 1; b--) tmp = m::mpfr::pow(a, tmp);
    return tmp;
}


/*m::mpfr pow(int _Xx, mp::mpz_int _Yx) {
    unsigned int _Nx;
    if (_Yx.compare(0) >= 0)
        _Nx = static_cast<unsigned int>(_Yx);
    else
        _Nx = static_cast<unsigned int>(-_Yx);

    for (int _Zx = static_cast<int>(1); ; _Xx *= _Xx)
    {
        if ((_Nx & 1) != 0)
            _Zx *= _Xx;
        if ((_Nx >>= 1) == 0)
            return (_Yx < 0 ? static_cast<int>(1) / _Zx : _Zx);
    }
}*/