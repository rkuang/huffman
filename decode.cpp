#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

  if (argc != 2) {
    cerr << "Program failed to run.\n";
    cerr << "Usage: ./decode codewords.txt\n";
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
  // Key = Codeword, Value = Character
  string ch, code;
  map <string, string> codewords;
  while (codewords_txt >> ch >> code) {
    codewords[code] = ch;
  }

  // Read stdin
  // Read character by character, appending to a current code variable
  // While reading, check map. If key is found, decode to value.
  string line;
  while (getline(cin, line)) {
    code = "";
    for (int i=0; i<line.length(); i++) {
      // cout << line[i] << endl;
      code += line[i];
      // cout << code << endl;
      if (codewords.find(code) != codewords.end()) {
        cout << (char)stoi(codewords[code]);
        code = "";
      }
    }
  }

  return 0;
}
