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
  //add empty tree
  m_root = recAdd(m_root,temp);
}

BinaryNode* BinaryTree::recAdd(BinaryNode* curSubTree, BinaryNode* movie)
{
    if(curSubTree == nullptr)
    {
      return movie;
    }

    BinaryNode* l_child = curSubTree->getLeft();
    BinaryNode* r_child = curSubTree->getRight();

    //left child of curSubTree is nullptr
    if(l_child == nullptr)
    {
      curSubTree->setLeft(movie);
      return curSubTree;
    }
    //right child of curSubTree is nullptr
    if(r_child == nullptr)
    {
      curSubTree->setRight(movie);
      return curSubTree;
    }

    //left child of curSubTree only have left leaf
    if(l_child->getLeft() == nullptr)
    {
      l_child->setLeft(movie);
      curSubTree->setLeft(l_child);
      return curSubTree;
    }
    //left child of curSubTree only have left leaf
    if(l_child->getRight() == nullptr && l_child->getLeft() != nullptr)
    {
      l_child->setRight(movie);
      curSubTree->setLeft(l_child);
      return curSubTree;
    }
    //left child of curSubTree have both leaves, then check r_child
    if(l_child->getLeft() != nullptr && l_child->getRight() != nullptr)
    {
      //right child of curSubTree only have left leaf
      if(r_child->getLeft() == nullptr)
      {
        r_child->setLeft(movie);
        curSubTree->setRight(r_child);
        return curSubTree;
      }
      //right child of curSubTree only have left leaf
      if(r_child->getLeft() != nullptr && r_child->getRight() == nullptr)
      {
        r_child->setRight(movie);
        curSubTree->setRight(r_child);
        return curSubTree;
      }
      //right child of curSubTree have both leaves, then check next level
      if(l_child->getLeft() != nullptr && l_child->getRight() != nullptr)
      {
        recAdd(l_child,movie);
        recAdd(r_child,movie);
      }
    }
    return curSubTree;
}

BinaryNode* BinaryTree::getRoot()
{
  return m_root;
}
