#include <iostream>

// 1. Write a recursive function to compute the factorial of a number

int factorial(int n)
{
	// Base cases: n = 0 or 1, factorial result is 1
	if (n == 0 || n == 1)
	{
		return(1);
	}
	else
	{
		return(n * factorial(n-1));
	}
}





int main()
{
	std::cout << factorial(0) << std::endl; // 1
	std::cout << factorial(1) << std::endl; // 1
	std::cout << factorial(3) << std::endl; // 6
	std::cout << factorial(5) << std::endl; // 120
	std::cout << factorial(6) << std::endl; // 720
	return(0);
}
