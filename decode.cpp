#include <iostream>
#include <fstream>
#include <map>
#include <bitset>

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

  // map <string, string> :: iterator itr;
  // for (itr = codewords.begin(); itr != codewords.end(); itr++) {
  //   cout  << itr->first << '\t' << itr->second << endl;
  // }

  // Read stdin
  // Read character by character, appending to a current code variable
  // While reading, check map. If key is found, decode to value.
  char c;
  string bits;
  code = "";
  // while (cin.get(c)) {
  //   bits = bitset<8>(c).to_string();   // 11010000
  //   for (int i=0; i<8; i++) {
  //     code += bits[i];
  //     if (codewords.find(code) != codewords.end()) {
  //       cout << (char)stoi(codewords[code]);
  //       code = "";
  //     }
  //   }
  // }

  char buf1, buf2, buf3;
  cin.get(buf1);
  cin.get(buf2);
  while (cin.get(buf3)) {
    bits = bitset<8>(buf1).to_string();
    for (int i=0; i<8; i++) {
      code += bits[i];
      if (codewords.find(code) != codewords.end()) {
        cout << (char)stoi(codewords[code]);
        code = "";
      }
    }
    buf1 = buf2;
    buf2 = buf3;
  }
  bits = bitset<8>(buf1).to_string();
  int padding = bitset<8>(buf2).to_ulong();
  for (int i=0; i < padding; i++) {
    code += bits[i];
    if (codewords.find(code) != codewords.end()) {
      cout << (char)stoi(codewords[code]);
      code = "";
    }
  }

  return 0;
}
