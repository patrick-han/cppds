#include <iostream>
#include <stack>
#include <string>

/*
 * An algorithm to convert any decimal number to any other base up to base-16
 * 
 * Uses the "divide-by-base algorithm" in which we continously integer divide the input
 * decimal number by the desired base. We push each remainder to a stack before popping off
 * all the digits which are conveniently in order by nature of a stack's FIFO principle.
 * 
 */


std::string baseConverter(int decNumber, int base) // Convert up to base 16
{
    std::string digits[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

    std::stack<int> remstack;

    while(decNumber > 0) 
    {
        int rem = decNumber % base;
        remstack.push(rem);
        decNumber = decNumber / base;
    }

    std::string output = "";
    while(!(remstack.empty())) 
    {
        output.append(digits[remstack.top()]);
        remstack.pop();
    }

    return(output);
}


int main() 
{
    std::cout << baseConverter(233, 2) << std::endl;
    std::cout << baseConverter(233, 16) << std::endl;
    return(0);
}