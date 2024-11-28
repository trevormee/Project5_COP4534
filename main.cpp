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
    lcs.RunPart2();
    
    // Testing FindLCSLength()
    //std::string s1 = "AGGTAB";
    //std::string s2 = "GXTXAYB";
    /*
    std::string s1 = "AACCTGAC";
    std::string s2 = "AACCTGA";
    //std::cout << lcs.FindLCSLength(s1, s2) << std::endl;
    int lcsLen = lcs.FindLCSLength(s1, s2);

    // Testing DetermineSimilarity()
    int s1Length = s1.length();
    int s2Length = s2.length();

    char c = lcs.DetermineSimilarity(s1, s2, lcsLen);
    std::cout << lcsLen << " " << c << std::endl;
    */


    return 0;
}