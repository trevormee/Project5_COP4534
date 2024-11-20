/***************************************************************
  Student Name: Trevor Mee
  File Name: LCS.cpp
  Project 5

  @brief 
***************************************************************/

#include "LCS.hpp"

/*
  @brief Default constructor to set private instance variables
         to default values
*/
LCS::LCS()
{
    x = "";
    y = "";
}

/*
  @brief Reads in text file and sets strings x and y to the 
         strings from the text file (Part 1)
  @param fileName: file to read from 

  @return N/A
*/
void LCS::ReadTwoStrings(std::string fileName)
{
    //std::cout << "x = " << x << std::endl;
    //std::cout << "y = " << y << std::endl;

    std::ifstream fileRead(fileName);
    std::getline(fileRead, x);
    std::getline(fileRead, y);
    fileRead.close();

    //std::cout << "x == " << x << std::endl;
    //std::cout << "y == " << y << std::endl;
}