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
    std::ifstream fileRead(fileName);
    std::getline(fileRead, x);
    std::getline(fileRead, y);
    fileRead.close();
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
            if(x.at(i - 1) == y.at(j - 1))  // match
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
                    cArray[i][j] = cArray[i][j-1]; // left
                }
            }
        }
    }

    /*
    std::cout << "cArray after population:" << std::endl;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            std::cout << cArray[i][j] << " ";
        }
        std::cout << std::endl; 
    }
    */

    return cArray;
}

/*
    @brief Finds and returns the lcs from the c array

    @return the LCS string
*/
std::string LCS::PrintLCS()
{
    std::string lcs = "";
    int i = x.length();
    int j = y.length();

    std::stack<char> s;

    while(i > 0 && j > 0)
    {
        if(x.at(i-1) == y.at(j-1))  // match
        {
            s.push(x.at(i-1));
            i = i - 1;
            j = j - 1;
        }
        else if(cArray[i - 1][j] >= cArray[i][j-1]) // go up
        {
            i = i - 1;
        }
        else    // move left
        {
            j = j - 1;
        }
    }

    while(!s.empty())
    {
        lcs += s.top();
        s.pop();
    }

    return lcs;
}

/*
    @brief Solves Part 1 of the project and prints 
           out the lcs from two strings

    @return N/A
*/
void LCS::RunPart1()
{
    //ReadTwoStrings("SimpleTwoStrings.txt");
    ReadTwoStrings("twoStrings.txt");
    PopulateCArray();
    std::string lcs = PrintLCS();
    std::cout << "LCS = " << lcs << std::endl;
}