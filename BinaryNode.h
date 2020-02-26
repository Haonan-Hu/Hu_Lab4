#ifndef BINARY_NODE_H
#define BINARY_NODE_H

#include <string>

class BinaryNode
{
public:
  BinaryNode(std::string title, double rating);

  std::string getTitle()const;
  void setTitle(std::string title);

  float getRating()const;
  void setRating(double rating);

  BinaryNode* getLeft()const;
  void setLeft(BinaryNode* left);

  BinaryNode* getRight()const;
  void setRight(BinaryNode* right);

  bool isFull();
private:
  std::string m_title;
  float m_rating;
  BinaryNode* m_left;
  BinaryNode* m_right;
};
#endif
