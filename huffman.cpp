#include <iostream>
#include <fstream>
#include <queue>
#include "huffman.h"

using namespace std;

void generateCodeWords(TreeNode* root) {
  int sum = 0;
  int* sum_ptr = &sum;
  ofstream codewords_txt("codewords.txt");
  ofstream* file = &codewords_txt;
  generateCodeWords(root, "", sum_ptr, file);
  cout << sum << endl;
}

void generateCodeWords(TreeNode* root, string code, int* sum_ptr, ofstream* file) {
  if (!root->left && !root->right) {
    *file << root->character << '\t' << code << endl;
    *sum_ptr += code.length()*root->frequency;
  }
  if (root->left) {
    generateCodeWords(root->left, code + "0", sum_ptr, file);
  }
  if (root->right) {
    generateCodeWords(root->right, code + "1", sum_ptr, file);
  }
}

void deleteTree(TreeNode* root)
{
  if (!root) return;

  deleteTree(root->left);
  deleteTree(root->right);

  delete root;
}

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

  generateCodeWords(root);

  deleteTree(root);

  return 0;
}
