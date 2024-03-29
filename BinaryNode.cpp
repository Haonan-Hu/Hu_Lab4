#include "BinaryNode.h"

BinaryNode::BinaryNode(std::string title, double rating)
{
  m_title = title;
  m_rating = rating;
  m_left = nullptr;
  m_right = nullptr;
}

std::string BinaryNode::getTitle()const
{
  return m_title;
}

void BinaryNode::setTitle(std::string title)
{
  m_title = title;
}

float BinaryNode::getRating()const
{
  return m_rating;
}

void BinaryNode::setRating(double rating)
{
  m_rating = rating;
}

BinaryNode* BinaryNode::getLeft()const
{
  return m_left;
}

void BinaryNode::setLeft(BinaryNode* left)
{
  m_left = left;
}

BinaryNode* BinaryNode::getRight()const
{
  return m_right;
}

void BinaryNode::setRight(BinaryNode* right)
{
  m_right = right;
}

bool BinaryNode::isFull()
{
  if(m_left != nullptr && m_right != nullptr)
  {
    if(m_left->getLeft() != nullptr && m_left->getRight() != nullptr &&
       m_right->getLeft() != nullptr && m_right->getRight() != nullptr)
       {
         return true;
       }
  }
  return false;
}
