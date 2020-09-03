#include <iostream>
#include <vector>

// 5. Write a recursive function to compute the Fibonacci sequence. 
//    How does the performance of the recursive function compare to 
//    that of an iterative version?


// Return the first n Fibonacci numbers: 0 1 1 2 3 5 8 13 21 34...
int fib(int n)
{
    // Base cases: if n<=1 print n (So this covers 0, 1));
    if (n <= 1)
    {
        return(n);
    }
    else
    {
        return(fib(n - 2) + fib(n - 1)); // Return the sum of the previous fib number and the one before that;
    }
}




int main()
{
    for (int i = 0; i < 10; ++i)
    {
        std::cout << fib(i) << " ";
    }
    std::cout << std::endl;

    return(0);
}