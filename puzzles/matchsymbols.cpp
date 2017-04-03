#include <iostream>
using namespace std;

/*
Using the C++ language, have the function matchSymbols(str) take the str parameter being passed
and determine if it is an acceptable sequence by either returning the string true or false. 

The str parameter will be composed of + and = symbols with several letters between them (ie. ++d+===+c++==a) and
for the string to be true each letter must be surrounded by a + symbol. So the string to the left would be false. 

The string will not be empty and will have at least one letter. 

Sample Test Cases

Input:"+d+=3=+s+"
Output:"true"

Input:"f++d+"
Output:"false"
*/

string SimpleSymbols(string str)
{
  string result = "false";

  for(size_t i = 0; i < str.length(); i++)
  {
    if(i > 0 && i <= str.length()-2)
    {
      if(
          ((str[i] >= 'a' || str[i] <= 'z' || str[i] >= 'A' || str[i] <= 'Z') && (str[i-1] == '+' && str[i+1] == '+'))
          ||
          ((str[i] >= '0' || str[i] <= '9') && (str[i-1] == '=' && str[i+1] == '='))
        )
      {
          result = "true";
      }
    }
  }
  return result;
}

int
main ()
{
  size_t tests = 12;
  string test[tests][2] = { {"+d+=+s+", "true"},
		  {"+d+","true"},
		  {"+d++","true"},
		  {"+d++s+", "true"},
		  {" a ", "false"},
		  {" ", "false"},
		  {"ab cd2123", "false"},
		  {"###3# ##", "false"},
		  {"cc", "false"},
		  {"sjafs afsf asfas", "false"},
          {"+d===+a","false"},
		  {"+d===+a+","true"}};

  string input;
  string actual;
  string expected;

  for (size_t i = 0; i < tests; i++) {
    input = test[i][0];
    actual = SimpleSymbols(input);
    expected = test[i][1];
    cout << "Case #" << i + 1 << " input: '" << input << "' expected: '" <<
    		expected << "' actual: '" << actual << "'" << endl;
    if (actual != expected) {
      cout << "Test failed!" << endl;
    }
    else {
      cout << "Test passed!" << endl;
    }
    cout << endl;
  }

  return 0;
}
