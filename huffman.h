#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <fstream>

using namespace std;

class TreeNode {
  public:
    int character;
    int frequency;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int _character, int _frequency);
};

struct TreeNodeComparator {
  bool operator() (const TreeNode *left_side, const TreeNode *right_side) const {
    if (left_side->frequency > right_side->frequency) {
      return true;
    } else if (left_side->frequency == right_side->frequency) {
      return left_side->character > right_side->character;
    } else {
      return false;
    }
  };
};

TreeNode::TreeNode(int _character, int _frequency) {
  character = _character;
  frequency = _frequency;
  left = nullptr;
  right = nullptr;
}

void generateCodeWords(TreeNode* root, string code) {
  if (!root->left && !root->right) {
    cout << root->character << '\t' << code << endl;
  }
  if (root->left) {
    generateCodeWords(root->left, code + "0");
  }
  if (root->right) {
    generateCodeWords(root->right, code + "1");
  }
}

#endif
