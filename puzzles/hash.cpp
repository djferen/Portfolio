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

map<string,int> getWordFreq(vector<string> words)
{
	map<string,int> freqs;
    
    for(auto word : words)
    {
        auto loc = freqs.find(word);
        if(loc != freqs.end())
        {
            freqs[word] += 1;
        }
        else
        {
            freqs.insert(pair<string,int>(word, 1));
        }
    }
    return freqs;
}

bool ransom_note(vector<string> magazine, vector<string> ransom) {
	map<string,int> magazineWordFreqs = getWordFreq(magazine);
	map<string,int> ransomWordFreqs = getWordFreq(ransom);
    size_t found_all = 0;

    for(auto ransom_word : ransom)
    {
        auto search = magazineWordFreqs.find(ransom_word);
        if(search != magazineWordFreqs.end())
        {
            search->second--;
        }
    }

    for(auto word : magazineWordFreqs)
    {
    	if(word.second < 0)
    		return false;
    }

    return true;
}

int main(){

    vector<string> magazine = {"apgo", "clm", "w", "lxkvg", "mwz", "elo", "bg", "elo", "lxkvg", "elo", "apgo", "apgo", "w", "elo", "bg"};
    vector<string> ransom = {"elo", "lxkvg", "bg", "mwz", "clm", "w"};

    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}


