#include <iostream>
#include <string>


std::string intToStr(int num, int base) {
	std::string convertStr = "0123456789ABCDE"; // Lookup string for digits
	if (num < base) { // base case
		return(std::string(1,convertStr[num]));
	}
	else {
		return(intToStr(num/base, base) + convertStr[num%base]);
	}	
}




int main() {
	std::cout << intToStr(769,10) << std::endl;	
	std::cout << intToStr(10,16) << std::endl;



	return 0;
}
