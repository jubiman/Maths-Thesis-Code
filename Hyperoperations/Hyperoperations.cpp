// Hyperoperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int tetration(int, int);

int main()
{
    std::cout << "Taking input..." << std::endl;

    int a, b;
    std::cin >> a >> b;
    std::cout << a + " " + b << " = " << tetration(a, b) << std::endl;


    char c; std::cin.ignore(); std::cin >> c;
    return 0;
}

// Tetration function, only takes x^^n with n > 0
int tetration(int a, int b)
{
    int c;
    if (b <= 0) return 0;
    for (c = a; b > 1; b--) c = pow(a, c);
    return c;
}