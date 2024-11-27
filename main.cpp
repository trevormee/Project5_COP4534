/***************************************************************
  Student Name: Trevor Mee
  File Name: main.hpp
  Project 5

  @brief 
***************************************************************/

#include "LCS.hpp"

int main()
{
    LCS lcs;
    //lcs.RunPart1();
    //lcs.ReadMultiStrings("multiStrings.txt");
    
    // Testing FindLCSLength()
    std::string s1 = "AGGTAB";
    std::string s2 = "GXTXAYB";
    std::cout << lcs.FindLCSLength(s1, s2) << std::endl;


    return 0;
}