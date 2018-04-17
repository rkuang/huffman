#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

  if (argc != 2) {
    cerr << "Program failed to run.\n";
    cerr << "Usage: ./encode codewords.txt\n";
    exit(1);
  }

  string file_name = argv[1];
  ifstream codewords_txt (file_name);
  if (!codewords_txt) {
    cerr << "Program failed to load " << file_name << endl;
    exit(1);
  }

  // Parse codewords.txt
  // Put character-codeword pairs into map
  // Key = Character, Value = Codeword
  string ch, code;
  map <string, string> codewords;
  while (codewords_txt >> ch >> code) {
    codewords[ch] = code;
  }

  // map <string, string> :: iterator itr;
  // for (itr = codewords.begin(); itr != codewords.end(); itr++) {
  //   cout  << itr->first << '\t' << itr->second << endl;
  // }

  // Read stdin
  // Convert chars to ASCII values, find character in map, print code to stdout
  string line;
  while (getline(cin, line)) {
    for (int i=0; i<line.length(); i++) {
      cout << codewords[to_string((int)line[i])];
    }
    cout << codewords[to_string((int)'\n')];
  }

  return 0;
}
