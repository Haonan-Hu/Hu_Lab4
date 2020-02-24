#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
  m_root = nullptr;
  m_height = 0;
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
  
}
