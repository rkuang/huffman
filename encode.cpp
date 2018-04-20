#include <iostream>
#include <fstream>
#include <map>
#include <bitset>

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
  char c;
  bitset<8> my_char;
  int head = 0;
  while (cin.get(c)) {
    code = codewords[to_string((int)c)];
    for (int i=0; i<code.length(); i++) {
      // cout << code[i];
      my_char.set(7 - head, code[i] - 48);
      head = (head + 1) % 8;
      if (head == 0) {
        // cout << my_char;
        cout << (char)my_char.to_ulong();
      }
    }
  }
  if (head != 0) {
    for (int j = head; j < 8; j++) {
      my_char.set(7 - j, 1);
    }
    // cout << my_char;
    cout << (char)my_char.to_ulong();
  }

  return 0;
}
