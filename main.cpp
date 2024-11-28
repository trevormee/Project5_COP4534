/***************************************************************
  Student Name: Trevor Mee
  File Name: main.hpp
  Project 5

  @brief Contains the main function to run the program. This file
         creates an instance of the LCS class and calls RunPart1()
         and RunPart2() to display the results to the console
***************************************************************/

#include "LCS.hpp"

int main()
{
    LCS lcs;
    std::cout << "Part 1..." << std::endl;
    lcs.RunPart1();
    std::cout << "\nPart 2..." << std::endl;
    lcs.RunPart2();
    
    return 0;
}