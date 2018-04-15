#include <iostream>
#include <queue>
#include "huffman.h"

using namespace std;

int main() {
  // FrequencyCell* cell = new FrequencyCell('a', 40);
  // TreeNode* root = new TreeNode(cell);

  // cout  << cell->character << '\t' << cell->frequency << endl
  //       << root->val->character << '\t'<< root->val->frequency << endl
  //       << root->left << '\t' << root->right << endl;

  priority_queue<FrequencyCell, vector<FrequencyCell>, FrequencyComparator> min_heap;

  int ch, fr;
  while (cin >> ch >> fr) {
    // cout << ch << '\t' << fr << endl;
    // FrequencyCell* cell = new FrequencyCell(ch, fr);
    min_heap.push(FrequencyCell(ch, fr));
  }

  while (min_heap.empty() == false)
    {
        FrequencyCell fc = min_heap.top();
        cout << fc.character << '\t' << fc.frequency << endl;
        min_heap.pop();
    }

  return 0;
}
