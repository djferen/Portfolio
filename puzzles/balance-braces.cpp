#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool is_balanced(string expression)
{
  stack<char> s;
  bool pushed = false;

  for(auto c : expression)
  {
     if(c == '[')
         s.push(']');
     else if(c == '{')
    	 s.push('}');
     else if(c == '(')
	  	 s.push(')');
     else
     {
    	 if(!s.empty() && s.top() == c)
             s.pop();
     }
     if(!s.empty())
     {
    	 pushed = true;
     }
  }

  return s.empty() && (pushed && expression.length() > 0);
}

int main()
{
	ifstream inf("./test/bb-test", ifstream::in);
	ifstream einf("./test/bb-exp", ifstream::in);

    int n;
    inf >> n;

	string input,expected;

    for(int i = 0; i < n; i++)
    {
    	inf >> input;
    	einf >> expected;
    	string actual = (is_balanced(input) ? "YES" : "NO");

    	if(actual != expected)
    	{
    		cout << "Actual != expected for " << n << endl << input << endl;
    	}
    }

    inf.close();
    einf.close();

    return 0;
}


