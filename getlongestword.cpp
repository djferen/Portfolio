#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector < string > GetWords (string s, char delim)
{
  vector < string > words;
  if (s.find (delim) == string::npos) {
    words.push_back (s);
    return words;
  }
  else {
    stringstream ss (s);
    string word;
    while (getline (ss, word, delim)) {
      words.push_back (word);
    }

    return words;
  }
}

string
LongestWord (string sen)
{
  if (sen == "")
    return "";

  if (sen[0] == ' ')
    sen = sen.substr (1);

  if (sen[sen.length () - 1] == ' ')
    sen = sen.substr (0, sen.length () - 1);

  vector < string > words = GetWords (sen, ' ');

  size_t index = 0;
  int longestWord = 0;
  bool found = false;

  for (int i = words.size () - 1; i >= 0; i--) {
    int length = words[i].length ();
    if (length >= longestWord) {
      longestWord = length;
      index = i;
      found = true;
    }
  }

  return (found ? words[index] : "");
}

int
main ()
{
  size_t tests = 7;
  string test[tests][2] = { {"", ""},
  {"        ", ""},
  {"A", "A"},
  {" A ", "A"},
  {"A AB", "AB"},
  {"AA AA A B", "AA"},
  {"%!#!@ ###3###", "###3###"}
  };
  string input;
  string actual;
  string expected;

  for (size_t i = 0; i < tests; i++) {
    input = test[i][0];
    actual = LongestWord (input);
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
