#include "mpfr2.h"

/*void mpfr2::mpfr::addNumber(mp::int1024_t a) {
    mp::int1024_t tmp[sizeof(_a)/sizeof(*_a)];
    mp::int1024_t carry = 0;  // Initialize carry
    for (int i = 0; i < sizeof(_a) / sizeof(*_a); i++)
    {
        mp::int1024_t prod = mpfr2::mpfr::_a[i] + a + carry;

        // Store last digit of 'prod' in res[]   
        tmp[i] = prod % 10;

        // Put rest in carry 
        carry = prod / 10;
    }
    // Put carry in res and increase result size 
    while (carry)
    {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    mpfr2::mpfr() : _a(tmp);
}*/

void mpfr2::mpfr::setNumber(std::string a) {
    for (int i = a.length() - 1, j = 0; i >= 0; ++j, --i) {
        _a[j] = a[i] - '0';
    }
    res_size = a.length();
}

int mpfr2::mpfr::multiply(int x, int res[], int res_size)
{
    int carry = 0;  // Initialize carry 

    // One by one multiply n with individual digits of res[] 
    for (int i = 0; i < res_size; i++)
    {
        int prod = res[i] * x + carry;

        // Store last digit of 'prod' in res[]   
        res[i] = prod % 10;

        // Put rest in carry 
        carry = prod / 10;
    }

    // Put carry in res and increase result size 
    while (carry)
    {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}


int mpfr2::mpfr::multiply(mpfr x, mpfr &res)
{
    int carry = 0, carry2 = 0;  // Initialize carry 
    mpfr ans = mpfr();
    // One by one multiply n with individual digits of res[] 
    for (int i = 0; i < x.res_size; ++i)
    {
        for (int j = 0; j < res.res_size; ++j) {
            ans._a[i + j] += res._a[i] * x._a[j];
        }
    }
    for (int i = 0; i < x.res_size + res.res_size; i++)
    {
        int tmp = ans._a[i] / 10;
        ans._a[i] = ans._a[i] % 10;
        ans._a[i + 1] = ans._a[i + 1] + tmp;
    }
    for (int i = x.res_size + res.res_size; i >= 0; i--)
    {
        if (ans._a[i] > 0)
            break;
    }
    return 0;
}

/*int mpfr2::mpfr::multiply(mpfr x, int res[], int res_size)
{
    int carry = 0, carry2 = 0;  // Initialize carry 
    mpfr ans;
    // One by one multiply n with individual digits of res[] 
    for (int i = 0; i < x.res_size; ++i)
    {
        for (int j = 0; j < res_size; ++i) {
            ans._a[i + j] += res[i] * x._a[i];
            int prod = res[i] * x._a[j] + carry2;

            // Store last digit of 'prod' in res[]   
            res[i] = prod % 10;

            // Put rest in carry 
            carry = prod / 10;
        }
        while (carry2)
        {
            x._a[x.res_size] = carry2 % 10;
            carry2 = carry2 / 10;
            x.res_size++;
        }
    }

    // Put carry in res and increase result size 
    while (carry)
    {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}*/

mpfr2::mpfr mpfr2::mpfr::pow(mpfr a, int b) {
    mpfr tmp = a;
    for (int i = 0; i < b; ++i) {
        a.res_size = multiply(tmp, a);
    }
    return tmp;
}

// a^b
void mpfr2::mpfr::pow(mpfr& a, mpfr b) {
    mpfr tmp = a;
    std::string bStr = "";
    for (int i = b.res_size-1; i >= 0; --i) {
        bStr += std::to_string(b._a[i]);
    }

    int i = 0;
    while(!0) {
        std::cout << bStr << "\t" << std::to_string(i) << std::endl;
        if (bStr == std::to_string(i)) break;
        a.res_size = multiply(tmp, a);
        ++i;
    }
}

void mpfr2::mpfr::subfull(mpfr a, mpfr b) {
    mpfr tmp = a;
    int biggest_size = a.res_size >= b.res_size ? a.res_size : b.res_size;
    for (int i = 0, carry = 0; i < biggest_size; ++i)
        if (carry = ((a._a[i] -= b._a[i] + carry) < 0))
            a._a[i] += 10;
}