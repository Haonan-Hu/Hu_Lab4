#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "BinaryNode.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdexcept>

class BinaryTree
{
public:
  BinaryTree();//Done
  ~BinaryTree();//Done

  bool isFull();    //Done
  void addMovie(std::string title, float rating);//Done
  void removeMovie();//Done
  bool leaf(std::string title); //Done

  std::string printLeaves();
  void printTreeHeight(); //Done

  void Preorder();//Done
  void Postorder(); //Done
  void Inorder(); //Done
  void Levelorder();//Done

  void clear(); //Done
  BinaryNode* getRoot();  //Done
  int nodeNum();  //Done
  bool checkRating(float rating);  //Done
  bool checkDuplicates(std::string title);
  void setinfor(bool flag); //Done
private:
  BinaryNode* m_root;
  int m_level;
  int m_nodeNum;
  bool m_check;
  bool d_scussed;
  bool infor_mode;
  int m_delete;
  std::string output;

  void recClear(BinaryNode* curSubTree);//Done
  void recAdd(BinaryNode* curSubTree, BinaryNode* movie, int level); //done
  void recRemove(BinaryNode* curSubTree,int level);// Done
  int countNode(BinaryNode* curSubTree, int nodeNumber);//Done
  int getHeight(BinaryNode* curSubTree);//Done
  bool searching(BinaryNode* curSubTree, std::string title); //Done



  void recPreorder(BinaryNode* curSubTree);//Done
  void recPostorder(BinaryNode* curSubTree);//Done
  void recInorder(BinaryNode* curSubTree);//Done
  bool recLevelorder(BinaryNode* curSubTree, int level);//Done
  void recLeaves(BinaryNode* curSubTree, int level);
  bool recCheck(BinaryNode* curSubTree, std::string title);
};
#endif
