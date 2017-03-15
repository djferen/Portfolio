#include <iostream>
#include <string>

/*
 *
 * This program demonstrates a function that converts an integer between 1 and 3999 to a Roman numeral number.
 *
 * This program follows the "standard" Roman numeral conventions.
 *
 1 = I
 5 = V
 10 = X
 50 = L
 100 = C
 500 = D
 1000 = M

Output Examples:

I = 1
VI = 6
XVI = 16
LXVI = 66
CLXVII = 167
DCLXVIII = 668
MDCLXVIII = 1668

*/

std::string ConvertIntRomanNumeral(int from)
{
  std::string result;
  int remainder;
  int place = 0;

  std::string numeral_mapping [4][10]=
  {{"", "I", "II", "III", "IV", "V", "VI" , "VII", "VIII", "IX"},
   {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
   {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
   {"", "M", "MM", "MMM",   "",  "",   "",    "",     "",   ""}};

  while(from)
  {
	  remainder = from % 10;
	  result = numeral_mapping[place][remainder] + result;
	  place++;
	  from /= 10;
  }
  
  return result;
}


int main()
{
  for(int i = 0; i <= 4000; i++)
  {
     std::cout << "Value " << i << " has value " << ConvertIntRomanNumeral(i) << std::endl;
  }

  return 0;
}
