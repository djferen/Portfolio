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

  for(auto c : expression)
  {
     if(c == '[')
         s.push(']');
     else if(c == '{')
    	 s.push('}');
     else if(c == '[')
	  	 s.push(']');
     else
     {
    	 if(s.top() == c)
    		 s.pop();
    	 // pop until you close the eqivalent of c
         //pop when find closing
     }
  }

  return s.empty();
}

int main(){

    vector<string> inputs = {"{[()]}", "{[(])}", "{{[[(())]]}}"};
    vector<string> expected_outputs = {"Yes", "No", "Yes"};

    for(auto input : inputs)
    {
    	cout << (is_balanced(input) ? "Yes" : "No") << endl;
    }

    return 0;
}


