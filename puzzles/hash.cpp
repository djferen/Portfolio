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

bool isNoteInDictionary(vector<string> dictionary, vector<string> ransom) {
	map<string,int> dictionaryWordFreqs = getWordFreq(dictionary);
	map<string,int> noteWordFreqs = getWordFreq(ransom);
    size_t found_all = 0;

    for(auto ransom_word : ransom)
    {
        auto search = dictionaryWordFreqs.find(ransom_word);
        if(search != dictionaryWordFreqs.end())
        {
            search->second--;
        }
    }

    for(auto word : dictionaryWordFreqs)
    {
    	if(word.second < 0)
    		return false;
    }

    return true;
}

int main()
{
    vector<string> dictionary = {"apgo", "clm", "w", "lxkvg", "mwz", "elo", "bg", "elo", "lxkvg", "elo", "apgo", "apgo", "w", "elo", "bg"};
    vector<string> note       = {"elo", "lxkvg", "bg", "mwz", "clm", "w"};

    if(isNoteInDictionary(dictionary, note))
        cout << "Yes\n";
    else
        cout << "No\n";

    queue<int> myq;
    cout << "Front: " << myq.front() << endl;
    myq.push(1);
    myq.pop();
    cout << "Front: " << myq.front() << endl;

    return 0;
}
