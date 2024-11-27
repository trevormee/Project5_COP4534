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
    //std::string s1 = "AGGTAB";
    //std::string s2 = "GXTXAYB";
    std::string s1 = "A";
    std::string s2 = "G";
    std::cout << lcs.FindLCSLength(s1, s2) << std::endl;

    // Testing DetermineSimilarity()
    int s1Length = s1.length();
    int s2Length = s2.length();
    int shorter = std::min(s1Length, s2Length);
    std::cout << shorter << std::endl;


    return 0;
}