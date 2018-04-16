#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  if (argc != 2) {
    cerr << "Program failed to run.\n";
    cerr << "Usage: ./decode codewords.txt\n";
  }

  // Parse codewords.txt
  // Put character-codeword pairs into map
  // Key = Codeword, Value = Character

  // Read stdin
  // Read character by character, appending to a current code variable
  // While reading, check map. If key is found, decode to value.

  return 0;
}
