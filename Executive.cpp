/*
Author: Haonan Hu
File: Executive.cpp
Date:2/10/2020
Brief:File is cpp file
*/
#include "Executive.h"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <limits>

executive::executive(std::string fileName)
{
  std::ifstream infile;
  infile.open(fileName);
  std::string data;
  std::string title;
  std::string s_rating;
  float rating;
  int length;
  if(infile.is_open())  //  file read successful
  {
    while(std::getline(infile, data)) // make sure file input is valid
    {
      length = data.length();
      int index = data.find(',');
      for(int i = 0; i < index; i++)
      {
        title = title + data.at(i);
      }
      for(int i = index + 1; i < length; i++)
      {
        s_rating = s_rating + data.at(i);
      }
      rating = stof(s_rating);
      try
      {
          m_tree.addMovie(title,rating);
      }
      catch(std::runtime_error &rte)
      {
        std::cout << rte.what() << '\n';
      }
      title = "";
      s_rating = "";
    }
    infile.close();
    std::cout << "\e[1mFile reading done, ready for next step:\e[0m\n";
    std::cout << "..................................\n\n";
  }
  else
    std::cout << "Unable to open file\n";
}

executive::~executive(){}

void executive::run()
{
  int choice;
  for(;;)
  {
    std::cout << "Please choose one of the following commands: \n";
    std::cout << "1) isFull\n";
    std::cout << "2) Add Movie\n";
    std::cout << "3) Remove movie\n";
    std::cout << "4) Leaf\n";
    std::cout << "5) Print Leaves\n";
    std::cout << "6) Print Tree Height\n";
    std::cout << "7) Preorder\n";
    std::cout << "8) Postorder\n";
    std::cout << "9) Inorder\n";
    std::cout << "10)Levelorder\n";
    std::cout << "11)Exit\n";
    std::cin >> choice;
    std::cout << '\n';
    while(1)
    {
      if(std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong input!\n\n";
        std::cout << "..................................\n\n";
        std::cout << "Choose one operation from the options below: \n\n";
        std::cout << "Please choose one of the following commands: \n";
        std::cout << "1) isFull\n";
        std::cout << "2) Add Movie\n";
        std::cout << "3) Remove movie\n";
        std::cout << "4) Leaf\n";
        std::cout << "5) Print Leaves\n";
        std::cout << "6) Print Tree Height\n";
        std::cout << "7) Preorder\n";
        std::cout << "8) Postorder\n";
        std::cout << "9) Inorder\n";
        std::cout << "10)Levelorder\n";
        std::cout << "11)Exit\n";
        std::cin >> choice;
        std::cout << '\n';
      }
      if(!std::cin.fail())
        break;
    }
    if(choice == 1)
    {
      if(m_tree.isFull())
      {
        std::cout << "Output: True\n\n";
      }
      else
      {
        std::cout << "Output: False\n\n";
      }
      std::cout << "..................................\n\n";
    }
    else if(choice == 2)
    {
      std::string title;
      float rating;
      std::cout << "Please enter the movie title which you want to enter into the tree.\n";
      std::cin >> title;
      std::cout << "Please enter the rating of your movie.\n";
      std::cin >> rating;
      try
      {
        m_tree.addMovie(title,rating);
        std::cout << "Record has been added successfully.\n";
      }
      catch(std::runtime_error &rte)
      {
        std::cout << rte.what() << '\n';
      }
      std::cout << "..................................\n\n";
    }
    else if(choice == 3)
    {
      try
      {
        m_tree.removeMovie();
      }
      catch (std::runtime_error &rte)
      {
        std::cout << rte.what() << '\n';
      }
      std::cout << "..................................\n\n";
    }
    else if(choice == 4)
    {
      std::string in;
      std::cout << "Please enter the name of your movie which you want to test as a leaf node.\n\n";
      std::cin >> in;
      if (m_tree.leaf(in))
      {
        std::cout << "The record with movie title " << in << " is a leaf node\n\n";
      }
      else
      {
        std::cout << "The record with movie title " << in << " is not a leaf node\n\n";
      }
      std::cout << "..................................\n\n";
    }
    else if(choice == 5)
    {
      std::cout<<"Output: The leaf nodes are: " << m_tree.printLeaves() << '\n';
      std::cout << "..................................\n\n";
    }
    else if(choice == 6)
    {
      std::cout << "Output: The height of the tree is ";
      m_tree.printTreeHeight();
      std::cout << "\n\n";
      std::cout << "..................................\n\n";
    }
    else if(choice == 7)
    {
      std::cout << "Output: Printing in Preorder - ";
      m_tree.Preorder();
      std::cout << "\n\n";
      std::cout << "..................................\n\n";
    }
    else if(choice == 8)
    {
      std::cout << "Output: Printing in Postorder - ";
      m_tree.Postorder();
      std::cout << "\n\n";
      std::cout << "..................................\n\n";
    }
    else if(choice == 9)
    {
      std::cout << "Output: Printing in Inorder - ";
      m_tree.Inorder();
      std::cout << "\n\n";
      std::cout << "..................................\n\n";
    }
    else if(choice == 10)
    {
      std::cout << "Output: Printing in Levelorder - ";
      m_tree.Levelorder();
      std::cout << "\n\n";
      std::cout << "..................................\n\n";
    }
    else if(choice == 11)
    {
      std::cout << "Program execution complete!\n";
      break;
    }
    else
    {
      std::cout << " Wrong input!\n\n";
      std::cout << "..................................\n\n";
    }
  }
}
