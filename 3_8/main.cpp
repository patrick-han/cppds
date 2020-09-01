#include <iostream>
#include <stack>
#include <string>


std::string baseConverter(int decNumber, int base) { // Convert up to base 16
    std::string digits[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"}; // array of strings

    std::stack<int> remstack;

    while(decNumber > 0) {
        int rem = decNumber % base;
        remstack.push(rem);
        decNumber = decNumber / base;
    }

    std::string output = "";
    while(!(remstack.empty())) {
        output.append(digits[remstack.top()]);
        remstack.pop();
    }

    return(output);
}


int main() {
    std::cout << baseConverter(233, 2) << std::endl;
    std::cout << baseConverter(233, 16) << std::endl;
    return(0);
}