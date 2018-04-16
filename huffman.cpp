#include <iostream>
#include <queue>
#include "huffman.h"

using namespace std;

int main() {

  priority_queue<TreeNode*, vector<TreeNode*>, TreeNodeComparator> min_heap;

  int ch, fr;
  while (cin >> ch >> fr) {
    min_heap.push(new TreeNode(ch, fr));
  }

  // while (!min_heap.empty()) {
  //   TreeNode *z = min_heap.top();
  //   cout << z->character << '\t' << z->frequency << endl;
  //   min_heap.pop();
  // }

  TreeNode* root;
  while (min_heap.size() > 1) {
    TreeNode* x = min_heap.top();
    min_heap.pop();
    TreeNode* y = min_heap.top();
    min_heap.pop();

    root = new TreeNode(-42, x->frequency + y->frequency);
    root->left = x;
    root->right = y;

    min_heap.push(root);
  }

  generateCodeWords(root, "");

  return 0;
}
