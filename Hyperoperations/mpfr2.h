#pragma once
// C standard includes
#include <iostream>
#include <string>
// Boost includes
#define MAX 0x7fffffff/32/4 // 2147483647
namespace mpfr2 {
	class mpfr
	{
	public:
		int _a[MAX];
		int res_size;
		void setNumber(std::string);
		static int multiply(int, int[], int);
		static int multiply(mpfr&, mpfr);
		static mpfr pow(mpfr, int);
		static mpfr pow(mpfr, mpfr);
		static void pow(mpfr&, mpfr, int8_t);
		static void subfull(mpfr, mpfr);
	};
}