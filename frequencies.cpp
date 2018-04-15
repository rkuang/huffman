#include <iostream>
#include <map>

using namespace std;

int main() {
  string line;
  map <int, int> frequencies;
  while (getline(cin, line)) {
    for (int i=0; i<line.length(); i++) {
      frequencies[line[i]]++;
    }
    frequencies['\n']++;
  }

  map <int, int> :: iterator itr;
  for (itr = frequencies.begin(); itr != frequencies.end(); itr++) {
    cout  << itr->first << '\t' << itr->second << endl;
  }

  return 0;
}
