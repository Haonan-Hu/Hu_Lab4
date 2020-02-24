#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
  m_root = nullptr;
  m_height = 0;
}

BinaryTree::~BinaryTree()
{
  clear();
}

void BinaryTree::clear()
{
  recClear(m_root);
}

void BinaryTree::recClear(BinaryNode* curSubTree)
{
  if(curSubTree != nullptr)
  {
    recClear(curSubTree->getLeft());
    recClear(curSubTree->getRight());
    delete curSubTree;
  }
}

bool BinaryTree::isFull()const
{
  // The tree is empty
  if(m_root == nullptr)
  {
    return true;
  }

  //Tree's lhs and rhs has no child
  if( (m_root->getLeft() == nullptr) && (m_root->getRight() == nullptr) )
  {
    return true;
  }

  //Recursively treverse to each node checking for lhs and rhs
  if( (m_root->getLeft() != nullptr) && (m_root->getRight() != nullptr) )
  {
    return (m_root->getLeft() != nullptr) && (m_root->getRight() != nullptr);
  }

  return false;
}


void BinaryTree::addMovie(std::string title, double rating)
{
  BinaryNode* temp = new BinaryNode(title,rating);
  recAdd(m_root,temp);
}

void BinaryTree::recAdd(BinaryNode* curSubTree, BinaryNode* movie)
{
  
}
