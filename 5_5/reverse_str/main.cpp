#include <iostream>
#include <string>
#include <cctype>

std::string reverseStr(std::string str) {
	if (str.length() <= 1) { // Base case
		return(str);
	}
	else {
		return(str.substr(str.length()-1,1) + reverseStr(str.substr(0, str.length() - 1)));
	}
}

std::string removeSpacePunc(std::string str) {
	std::string output;

	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == ' ')
			continue;
		output.push_back((char)std::tolower(str[i]));
	}
	

	return(output);

}


int main() {

	// Palindrome checker
	std::string word = "Live not on evil";
	word = removeSpacePunc(word);
	if (word == reverseStr(word)) {
		std::cout << word << " is a palindrome since its reverse is also: " << reverseStr(word) << std::endl;
	}

	return(0);	
}
