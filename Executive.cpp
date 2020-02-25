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

}

executive::~executive(){}

void executive::run()
{
  // int choice;
  // for(;;)
  // {
  //   std::cout << "make a selection: \n";
  //   std::cout << "1) Add User\n";
  //   std::cout << "2) Remove User\n";
  //   std::cout << "3) Forgot Password\n";
  //   std::cout << "4) Forgot Username\n";
  //   std::cout << "5) Print Users\n";
  //   std::cout << "6) Exit\n";
  //   std::cin >> choice;
  //   std::cout << '\n';
  //   while(1)
  //   {
  //     if(std::cin.fail())
  //     {
  //       std::cin.clear();
  //       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  //       std::cout << "Wrong input!\n\n";
  //       std::cout << "..................................\n\n";
  //       std::cout << "Choose one operation from the options below: \n\n";
  //       std::cout << "make a selection: \n";
  //       std::cout << "1) Add User\n";
  //       std::cout << "2) Remove User\n";
  //       std::cout << "3) Forgot Password\n";
  //       std::cout << "4) Forgot Username\n";
  //       std::cout << "5) Print Users\n";
  //       std::cout << "6) Exit\n";
  //       std::cin >> choice;
  //       std::cout << '\n';
  //     }
  //     if(!std::cin.fail())
  //       break;
  //   }
  //   if(choice == 1)
  //   {
  //
  //   }
  //   else if(choice == 2)
  //   {
  //
  //   }
  //   else if(choice == 3)
  //   {
  //
  //   }
  //   else if(choice == 4)
  //   {
  //
  //   }
  //   else if(choice == 5)
  //   {
  //
  //   }
  //   else if(choice == 6)
  //   {
  //     std::cout << "Program execution complete!\n";
  //     break;
  //   }
  //   else
  //   {
  //     std::cout << " Wrong input!\n\n";
  //     std::cout << "..................................\n\n";
  //   }
  // }
  m_tree.addMovie("Johnwick",4.3);
  m_tree.addMovie("Johnwick1",4.4);
  m_tree.addMovie("Johnwick2",4.1);
  m_tree.addMovie("Johnwick3",4.0);
  m_tree.addMovie("Johnwick4",4.6);

}
