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
        else if(cArray[i - 1][j] >= cArray[i][j-1]) // move up
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
    ReadTwoStrings("twoStrings.txt");
    PopulateCArray();
    std::string lcs = PrintLCS();
    std::cout << "LCS = " << lcs << std::endl;
}


/*
    @brief Reads in multiStrings.txt and extracts the 
           number of sequences and each individual
           sequence from the file
    @param fileName: file to read from

    @return N/A
*/
void LCS::ReadMultiStrings(std::string fileName)
{
    std::ifstream fileRead(fileName);

    std::string numStringsString;
    std::getline(fileRead, numStringsString);
    numStrings = std::stoi(numStringsString);
    
    multiStringsVector.resize(numStrings);
    for(int i = 0; i < numStrings; ++i)
    {
        std::getline(fileRead, multiStringsVector[i]);
    }

    fileRead.close();   

    std::cout << "Num strings -> " << numStrings << std::endl;
    /*
    for(auto s : multiStringsVector)
    {
        std::cout << s << std::endl;
    }
    */
}


/*
    @brief Determines the length of the LCS between two strings
           using a space optimization approach
    @param s1: first string to compare
           s2: second string to compare

    @return length of the LCS between two strings
*/
int LCS::FindLCSLength(std::string& s1, std::string& s2)
{
    int m = s1.length(); 
    int n = s2.length();

    std::vector<int> dp(n + 1, 0);

    for(int i = 1; i <= m; ++i)
    {
        int prev = dp[0];

        for(int j = 1; j <= n; ++j)
        {
            int curr = dp[j];

            if (s1[i - 1] == s2[j - 1])
            {
                dp[j] = 1 + prev;
            }
            else
            {
                dp[j] = std::max(dp[j - 1], dp[j]);
            }

            prev = curr;
        }
    }

    return dp[n];

}


/*
    @brief Determines the similarity between two strings based on criteria 
           from project instructions
    @param(s): s1: first string to compare
               s2: second string to compare

    @return a char (H, M, L, or D) depending on how similar two strings are
*/
char LCS::DetermineSimilarity(std::string& s1, std::string& s2, int lcsLength)
{
    int s1Length = s1.length();
    int s2Length = s2.length();
    int shorterStr = std::min(s1Length, s2Length);
    int longerStr = std::max(s1Length, s2Length);
    
    if( (shorterStr >= 0.90 * longerStr) && (lcsLength >= 0.90 * shorterStr) )
    {
        return 'H';
    }
    else if( (shorterStr >= 0.80 * longerStr) && (lcsLength >= 0.80 * shorterStr) )
    {
        return 'M';
    }
    else if ( (shorterStr >= 0.60 * longerStr) && (lcsLength >= 0.50 * shorterStr) ) 
    {
        return 'L';
    }
    else 
    {
        return 'D';
    }
} 


/*
    @brief Loops through all sequences found in multiStrings.txt and computes, populates
           and prints the similarity table

    @param multiStringsVector: vector containing strings from multiStrings.txt

    @return M/A
*/
void LCS::SimilarityTable(std::vector<std::string>& multiStringsVector)
{ 
    int tableSize = numStrings;
    char similarityTable[tableSize][tableSize];

    for(int i = 0; i < tableSize; ++i)
    {
        for(int j = i + 1; j < tableSize; ++j)
        {
            int lcsLength = FindLCSLength(multiStringsVector[i], multiStringsVector[j]);
            similarityTable[i][j] = DetermineSimilarity(multiStringsVector[i], multiStringsVector[j], lcsLength);
        }
    }

}


/*
    @brief

    @return
*/
void LCS::RunPart2()
{
    ReadMultiStrings("multiStrings.txt");
    for(auto s : multiStringsVector)
    {
        std::cout << s << std::endl;
    }

    SimilarityTable(multiStringsVector);

}