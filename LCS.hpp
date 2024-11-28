/***************************************************************
  Student Name: Trevor Mee
  File Name: LCS.hpp
  Project 5

  @brief Contains the function declarations for solving the 
         longest common subsequence problems in two different
         parts. Part 1 utilizes the entire c Array to compute
         the LCS and print the original strings and LCS to the
         console. Part 2 utilizes a space optimization approach
         to constuct a similarity table for n number of strings.
***************************************************************/

#ifndef LCS_HPP
#define LCS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stack>
#include <cmath>

class LCS
{
    private:
      // Private Instance Variables
      std::vector<std::vector<int>> cArray;
      std::string x;
      std::string y;

      int numStrings;
      std::vector<std::string> multiStringsVector;
      
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

      // Reads in multiStrings.txt (Part 2)
      void ReadMultiStrings(std::string fileName);

      // Finds the LCS with optimized space approach
      int FindLCSLength(std::string& s1, std::string& s2);

      // Determines the similarity between two strings
      char DetermineSimilarity(std::string& s1, std::string& s2, int lcsLength);

      void SimilarityTable(std::vector<std::string>& multiStringsVector);

      // Runs Part 2 of the Project
      void RunPart2();    
};
#endif