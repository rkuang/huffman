#ifndef HUFFMAN_H
#define HUFFMAN_H

class FrequencyCell {
  public:
    int character;
    int frequency;

    FrequencyCell();
    FrequencyCell(int _character, int _frequency);
};

struct FrequencyComparator {
  bool operator() (const FrequencyCell &f1, const FrequencyCell &f2) const {
    if (f1.frequency > f2.frequency) {
      return true;
    } else if (f1.frequency == f2.frequency) {
      return f1.character > f2.character;
    } else {
      return false;
    }
  };
};

class TreeNode {
  public:
    FrequencyCell val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(FrequencyCell _val);
};


FrequencyCell::FrequencyCell() {
  // required default constructor
}

FrequencyCell::FrequencyCell(int _character, int _frequency) {
  character = _character;
  frequency = _frequency;
}

TreeNode::TreeNode(FrequencyCell _val) {
  val = _val;
  left = nullptr;
  right = nullptr;
}

#endif
