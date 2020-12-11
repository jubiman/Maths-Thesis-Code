#pragma once
// C standard includes
#include <string>
// Boost includes
#include <boost/multiprecision/cpp_int.hpp> // Defines cpp int backend for large numbers (int1024_t)

namespace mp = boost::multiprecision;
#define MAX 1000
namespace mpfr2 {
	class mpfr
	{
	public:
		int _a[MAX];
		int res_size;
		void setNumber(std::string);
		static int multiply(int, int[], int);
		static int multiply(mpfr, mpfr&);
		static mpfr pow(mpfr, int);
		static void pow(mpfr&, mpfr);
		static void subfull(mpfr, mpfr);
	};
}

