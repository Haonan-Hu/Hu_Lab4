#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "BinaryNode.h"
#include <iostream>

class BinaryTree
{
public:
  BinaryTree();
  ~BinaryTree();

  bool isFull()const;
  void addMovie(std::string title, double rating);
  void removeMovie();
  bool leaf(std::string title);

  void printLeaves();
  void printTreeHeight();

  void Preorder();
  void Postorder();
  void Inorder();
  void Levelorder();

  void clear();
  BinaryNode* getRoot();
private:
  BinaryNode* m_root;
  int m_height;
  void recClear(BinaryNode* curSubTree);
  void recAdd(BinaryNode* curSubTree, BinaryNode* movie);
  void PreorderTreversal(BinaryNode* curSubTree);
};
#endif
