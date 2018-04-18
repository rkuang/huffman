#include <iostream>
#include <map>

using namespace std;

int main() {
  char ch;
  map <int, int> frequencies;
  while (cin.get(ch)) {
    frequencies[ch]++;
  }

  map <int, int> :: iterator itr;
  for (itr = frequencies.begin(); itr != frequencies.end(); itr++) {
    cout  << itr->first << '\t' << itr->second << endl;
  }

  return 0;
}
