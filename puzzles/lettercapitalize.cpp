#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector < string > GetWords (string s, char delim)
{
	vector < string > words;
	stringstream ss (s);
	string word;
	while (getline (ss, word, delim)) {
		if(word.compare("") != 0)
		{
			if(word[0] >= 'a' && word[word.length()-1] <= 'z')
				word[0] = word[0]-32;
		}
		words.push_back(word);
	}
	return words;
}

string LetterCapitalize(string str)
{
  vector<string> words = GetWords(str, ' ');
  string result;

  for(vector<string>::const_iterator iter = words.begin(); iter != words.end(); iter++)
  {
	  result += iter->c_str();

	  if((iter+1) != words.end())
		  result += " ";
  }

  return result;
}

int
main ()
{
  size_t tests = 7;
  string test[tests][2] = { {"", ""},
  {"A", "A"},
  {"A aB c ", "A AB C"},
  {"abcd2123", "Abcd2123"},
  {"###3###", "###3###"},
  {"cc", "Cc"},
  {"sjafs afsf asfas", "Sjafs Afsf Asfas"}
  };
  string input;
  string actual;
  string expected;

  for (size_t i = 0; i < tests; i++) {
    input = test[i][0];
    actual = LetterCapitalize (input);
    expected = test[i][1];
    cout << "Case #" << i +
      1 << " input: '" << input << "' expected: '" << expected <<
      "' actual: '" << actual << "'" << endl;
    if (actual != expected) {
      cout << actual << " did not match " << expected << "; Test failed!" <<
	endl;
    }
    else {
      cout << actual << " did match " << expected << ": Test passed!" << endl;
    }
    cout << endl;
  }

  return 0;
}














