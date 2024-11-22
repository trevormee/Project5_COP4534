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

/*
  @brief Populates the C Array (Part 1)

  @return the populated C Array 
*/
std::vector<std::vector<int>> LCS::PopulateCArray()
{
    int m = x.length();
    int n = y.length();

    cArray.resize(m + 1, std::vector<int>(n + 1, 0));

    for(int i = 1; i <= m; i++)
    {
        cArray[i][0] = 0;
    }

    for(int j = 0; j <= n; j++)
    {
        cArray[0][j] = 0;
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(x.at(i - 1) == y.at(j - 1))  // Match
            {
                cArray[i][j] = cArray[i-1][j-1] + 1;
            }
            else    // No match
            {
                if(cArray[i-1][j] >= cArray[i][j-1])
                {
                    cArray[i][j] = cArray[i-1][j];  // up
                }
                else
                {
                    cArray[i][j] = cArray[i][j-1]; // ;eft
                }
            }
        }
    }

    std::cout << "cArray after population:" << std::endl;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            std::cout << cArray[i][j] << " ";
        }
        std::cout << std::endl; 
    }

    return cArray;
}


void LCS::RunPart1()
{
    ReadTwoStrings("SimpleTwoStrings.txt");
    PopulateCArray();
}