#include <iostream>
#include <string>
#include <cctype>

/*
 * Recursively reverses a string by reversing each substring of decreasing length (by 1)
 * 
 */

std::string reverseStr(std::string str) 
{
	if (str.length() <= 1)  // Base case: A length 1 string reversed is just itself
	{
		return(str);
	}
	else 
	{
		return(str.substr(str.length() - 1,1) + reverseStr(str.substr(0, str.length() - 1)));
	}
}

// Helper function to remove spaces and caps
std::string removeSpaceCaps(std::string str) 
{
	std::string output;

	for (int i = 0; i < str.length(); ++i) 
	{
		if (str[i] == ' ')
			continue;
		output.push_back((char)std::tolower(str[i]));
	}

	return(output);

}


int main() 
{
	// Palindrome checker
	std::string word = "Live not on evil";
	word = removeSpaceCaps(word);
	if (word == reverseStr(word)) 
	{
		std::cout << word << " is a palindrome since its reverse is also: " << reverseStr(word) << std::endl;
	}

	return(0);	
}
