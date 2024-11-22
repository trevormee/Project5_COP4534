/***************************************************************
  Student Name: Trevor Mee
  File Name: LCS.hpp
  Project 5

  @brief 
***************************************************************/

#ifndef LCS_HPP
#define LCS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stack>

class LCS
{
    private:
      // Private Instance Variables
      std::vector<std::vector<int>> cArray;
      std::string x;
      std::string y;
      
    public:
      // Default Constructor
      LCS();

      // Reads in twoStrings.txt (Part 1)
      void ReadTwoStrings(std::string fileName);

      // Populates the C Array (Part 1)
      std::vector<std::vector<int>> PopulateCArray();

      // Reconstucts the LCS from C Array (Part 1)
      std::string PrintLCS();

      // Runs Part 1 of the Project
      void RunPart1();    
};
#endif