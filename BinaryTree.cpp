#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
  m_root    = nullptr;
  m_level   = 1;
  m_nodeNum = 0;
  m_delete  = 0;
  m_check   = false;
  infor_mode= true;
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

void BinaryTree::setinfor(bool flag)
{
  infor_mode = flag;
}

bool BinaryTree::checkRating(float rating)
{
  if (rating < 0.0 || rating > 5.0)
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool BinaryTree::checkDuplicates(std::string title)
{
  return recCheck(m_root, title);
}

bool BinaryTree::recCheck(BinaryNode* curSubTree, std::string title)
{
  if(curSubTree == NULL)
  {
    return true;
  }
  if(curSubTree->getTitle() == title)
  {
    return false;
  }
   return recCheck(curSubTree->getLeft(), title) ||  recCheck(curSubTree->getRight(), title);
}

void BinaryTree::printTreeHeight()
{
  if (m_root == nullptr)
  {
    int height = 0;
    std::cout <<  height << '\n';
  }
  else
  {
    int height = getHeight(m_root) - 1;
    std::cout << height << '\n';
  }
}

int BinaryTree::getHeight(BinaryNode* curSubTree)
{
  if (curSubTree == nullptr)
  {
    return 0;
  }
  else
  {
    int left = getHeight(curSubTree->getLeft());
    int right = getHeight(curSubTree->getRight());
    if (left > right)
    {
      return left + 1;
    }
    else
    {
      return right + 1;
    }
  }
}

void BinaryTree::addMovie(std::string title, float rating)
{
  BinaryNode* temp = new BinaryNode(title, rating);
  if (checkRating(rating) && checkDuplicates(title))
  {
    m_check = false;
    recAdd(m_root, temp, 1);
  }
  else
  {
    throw(std::runtime_error("Invalid rating or title"));
  }
}

void BinaryTree::recAdd(BinaryNode* curSubTree, BinaryNode* movie, int level)
{
  if (m_nodeNum == pow(2, m_level))
  {
    m_nodeNum = 0;
    m_level++;
  }

  if (m_root == nullptr)
  {
    m_root  = movie;
  }
  else if (curSubTree->getLeft() == nullptr || curSubTree->getRight() == nullptr)
  {
    if (curSubTree->getLeft() == nullptr)
    {
      //cout << "parent: " << tree->getEntry()->getname() << " on left : " << entry->getname() << endl;
      curSubTree->setLeft(movie);
      m_nodeNum++;
      m_check = true;
    }

    else if (curSubTree->getRight() == nullptr)
    {
      //cout << "parent: " << tree->getEntry()->getname() << " on right: " << entry->getname() << endl;
      curSubTree->setRight(movie);
      m_nodeNum++;
      m_check = true;
    }
  }
  else
  {
    int temp = level + 1;
    if (temp <= m_level)
    {
      if (curSubTree->getLeft() != nullptr && !m_check)
      {
        recAdd(curSubTree->getLeft(), movie, temp);
      }
      if (curSubTree->getRight() != nullptr && !m_check)
      {
        recAdd(curSubTree->getRight(), movie, temp);
      }
    }
  }
}

bool BinaryTree::isFull()
{
  if (nodeNum() == pow(2, m_level))
  {
    return true;
  }
  return false;
}

int BinaryTree::nodeNum()
{
  if (m_root != nullptr)
  {
    return countNode(m_root, getHeight(m_root));
  }
  else
  {
    return 0;
  }
}

int BinaryTree::countNode(BinaryNode* curSubTree, int level)
{
  if (level == 2)
  {
    int num = 0;
    if (curSubTree->getLeft() != nullptr)
    {
      num++;
    }
    if (curSubTree->getRight() != nullptr)
    {
      num++;
    }
    return num;
  }
  else if (level == 1)
  {
    return 0;
  }
  else
  {
    return countNode(curSubTree->getLeft(), level - 1) + countNode(curSubTree->getRight(), level - 1);
  }
}

void BinaryTree::removeMovie()
{
  if (m_root != nullptr)
  {
    d_scussed = false;
    m_delete = 0;
    recRemove(m_root, getHeight(m_root));
  }
  else
  {
    throw(std::runtime_error("The tree is empty"));
  }
}

void BinaryTree::recRemove(BinaryNode* curSubTree,int level)
{
  if (level == 2 && !d_scussed)
  {

    if (curSubTree->getLeft() != nullptr && curSubTree->getRight() == nullptr)
    {
      BinaryNode* temp = curSubTree->getLeft();
      if (infor_mode)
      {
        std::cout << "The last movie with title " << temp->getTitle() << " and rating " << temp->getRating()
             << " has been deleted" << '\n';
      }
      curSubTree->setLeft(nullptr);
      delete temp; //mark
      m_nodeNum--;
      d_scussed = true;
    }
    else if (curSubTree->getLeft() != nullptr && curSubTree->getRight() != nullptr)
    {
      m_delete += 2;
      if (m_delete == m_nodeNum)
      {
        BinaryNode* temp = curSubTree->getRight();
        if (infor_mode)
        {
          std::cout << "The last movie with title " << temp->getTitle() << " and rating " << temp->getRating()
               << " has been deleted" << '\n';
        }
        curSubTree->setRight(nullptr);
        delete temp;
        m_nodeNum--;
        d_scussed = true;
      }
    }
  }
  else if (m_root == curSubTree && m_root->getLeft() == nullptr)
  {
    if (infor_mode)
    {
      std::cout << "The last movie with title " << m_root->getTitle() << " and rating " << m_root->getRating()
           << " has been deleted" << '\n';
    }
    delete m_root;
    m_root = nullptr;
    m_nodeNum--;
    d_scussed = true;
  }
  if (m_nodeNum == 0)
  {
    m_level = getHeight(m_root) - 1;
    m_nodeNum = nodeNum();
  }
  if (!d_scussed && level > 1)
  {
    recRemove(curSubTree->getLeft(), level - 1);
    recRemove(curSubTree->getRight(), level - 1);
  }
}

void BinaryTree::Preorder()
{
    recPreorder(m_root);
}

void BinaryTree::recPreorder(BinaryNode* curSubTree)
{
  if (curSubTree == NULL)
  {
    return;
  }
  std::cout << curSubTree->getRating() << " ";
  recPreorder(curSubTree->getLeft());
  recPreorder(curSubTree->getRight());
}

void BinaryTree::Postorder()
{
    recPostorder(m_root);
}

void BinaryTree::recPostorder(BinaryNode* curSubTree)
{
  if (curSubTree == NULL)
  {
    return;
  }
  recPostorder(curSubTree->getLeft());
  recPostorder(curSubTree->getRight());
  std::cout << curSubTree->getRating() << " ";
}

void BinaryTree::Inorder()
{
    recInorder(m_root);
}

void BinaryTree::recInorder(BinaryNode* curSubTree)
{
  if (curSubTree == NULL)
  {
    return;
  }
  recInorder(curSubTree->getLeft());
  std::cout << curSubTree->getRating() << " ";
  recInorder(curSubTree->getRight());
}


void BinaryTree::Levelorder()
{
    // start from level 1 -- till height of the tree
    int level = 1;

    // run till printLevel() returns false
    while (recLevelorder(m_root, level))
    {
      level++;
    }
}

bool BinaryTree::recLevelorder(BinaryNode* curSubTree, int level)
{
    if (curSubTree == nullptr)
    {
      return false;
    }

    if (level == 1)
    {
        std::cout << curSubTree->getTitle() << " ";
        return true;
    }

    bool left = recLevelorder(curSubTree->getLeft(), level - 1);
    bool right = recLevelorder(curSubTree->getRight(), level - 1);

    return left || right;
}

bool BinaryTree::leaf(std::string title)
{
  bool leaf = false;
  if(searching(m_root,title))
  {
    leaf = true;
  }
  return leaf;
}

bool BinaryTree::searching(BinaryNode* curSubTree, std::string title)
{

  if(curSubTree != nullptr)
  {
    if(curSubTree->getTitle() == title)
    {
      if(curSubTree->getLeft() == nullptr && curSubTree->getRight() == nullptr)
      {
        return true;
      }
    }
    return searching(curSubTree->getLeft(), title) || searching(curSubTree->getRight(),title);
  }
  return false;
}

std::string BinaryTree::printLeaves()
{
  output = "";
  for(int i = 1; i <= getHeight(m_root); i++)
  {
    recLeaves(m_root,i);
  }
  if(m_root != nullptr && output.size() != 0)
  {
    output.resize(output.size() - 1);
  }
  else
  {
    output = "The Tree is empty\n";
  }
  return output;
}

void BinaryTree::recLeaves(BinaryNode* curSubTree, int level)
{
  if(curSubTree != nullptr)
  {
    if(level==1)
    {
      if(curSubTree->getLeft() == nullptr && curSubTree->getRight() == nullptr)
      {
        output = output + curSubTree->getTitle() + ",";
      }
    }
    else if(level > 1)
    {
      recLeaves(curSubTree->getLeft(),level - 1);
      recLeaves(curSubTree->getRight(),level - 1);
    }
  }
}
