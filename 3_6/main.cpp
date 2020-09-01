#include <iostream>
#include <string>
#include <stack>

/*
 * Algorithm that checks if an expression of parantheses, brackets, and braces
 * is properly balanced. Utilizes a stack in order to keep track of opening para/brackets/braces
 * and pops the stack when the corresponding closing element is found. Balanced if there's nothing
 * left over, i.e. all openers found a matching closer.
 * 
 * This source file has two implementations, one for parantheses only, and the other covers all 3 symbols
 * 
 */


bool parChecker(std::string symbolString) 
{
    std::stack<std::string> s;
    bool balanced = true;
    int len = symbolString.length();
    int index = 0;
    while ((index < len) && balanced)
    {
        if (symbolString[index] == '(') 
        {
            s.push("(");
        }
        else // If we encounter ')'
        { 
            if (s.empty()) // If there are no avalible "(" to balance the ")"...
            {
                balanced = false;
            }
            else 
            {
                s.pop();
            }
        }
        index = index + 1;
    }
    if (s.empty() && balanced) // Stack must be empty and balanced must remain true, would fail here for "(()"
    { 
        return(true);
    }
    else 
    {
        return(false);
    }
}

// Helper function that returns if substring substr is in string str
bool inString(std::string substr, std::string str) 
{
    if(str.find(substr) != std::string::npos) // If substring found
    { 
        return(true);
    }
    else 
    {
        return(false);
    }
}

// Helper function that returns if a given opener and closer belong to the same type
bool matches(std::string opener, std::string closer) 
{
    std::string openers = "{[(";
    std::string closers = "}])";
    if (openers.find(opener) == closers.find(closer)) 
    {
        return(true);
    }
    else 
    {
        return(false);
    }
}


// Same thing, but including {, [ and ()
bool parCheckerExt(std::string symbolString) 
{
    std::stack<std::string> s;
    std::string symbol;
    bool balanced = true;
    int len = symbolString.length();
    int index = 0;

    // Used to check for opener and closer types
    std::string openers = "{[(";
    std::string closers = "}])";


    while ((index < len) && balanced) 
    {
        symbol = symbolString[index];
        if (inString(symbol, openers)) // If we have an opener, push to the stack
        { 
            s.push(symbol);
        }
        else // If we encounter a closer...
        { 
            if (s.empty()) // If there are no avalible openers to balance a closer, than its not balanced
            { 
                balanced = false;
            }
            else 
            {
                std::string top = s.top(); // Pop the most recent opener
                s.pop();
                if (!matches(top, symbol)) 
                {
                    balanced = false;
                }
            }
        }
        index = index + 1;
    }
    if (s.empty() && balanced) // Stack must be empty and balanced must remain true, would fail here for "(()"
    { 
        return(true);
    }
    else 
    {
        return(false);
    }
}


int main() 
{
    // std::cout << parChecker("((()))") << std::endl;
    // std::cout << parChecker("(()") << std::endl;

    std::cout << parCheckerExt("{}") << std::endl;
    std::cout << parCheckerExt("[{()}]") << std::endl;
    std::cout << parCheckerExt("[{()}") << std::endl;
}