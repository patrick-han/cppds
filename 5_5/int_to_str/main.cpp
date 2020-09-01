#include <iostream>
#include <string>

/*
 * Converts an integer of any base to its string equivalent. Recursively
 * does continuous integer division and uses the remainder which will happen
 * to be the ones digit for each division.
 * 
 */

std::string intToStr(int num, int base) 
{
	std::string convertStr = "0123456789ABCDE"; // Lookup string for digits
	if (num < base) // Recursive base case
	{ 
		return(std::string(1, convertStr[num]));
	}
	else 
	{
		return(intToStr(num / base, base) + convertStr[num % base]);
	}	
}




int main() {
	std::cout << intToStr(769,10) << std::endl;	
	std::cout << intToStr(10,16) << std::endl;

	return(0);
}
