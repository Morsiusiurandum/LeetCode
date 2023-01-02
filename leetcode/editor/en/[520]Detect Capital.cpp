/**
We define the usage of capitals in a word to be right when one of the following 
cases holds: 

 
 All letters in this word are capitals, like "USA". 
 All letters in this word are not capitals, like "leetcode". 
 Only the first letter in this word is capital, like "Google". 
 

 Given a string word, return true if the usage of capitals in it is right. 

 
 Example 1: 
 Input: word = "USA"
Output: true
 
 Example 2: 
 Input: word = "FlaG"
Output: false
 
 
 Constraints: 

 
 1 <= word.length <= 100 
 word consists of lowercase and uppercase English letters. 
 

 Related Topics String 👍 1932 👎 386

*/
#include <vector>
#include <iostream>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        if ('A' <= word[0] && word[0] <= 'Z')
        {
            if ('A' <= word[1] && word[1] <= 'Z')
            {
                for (int i = 2; i < word.length(); ++i)
                {
                    if ('a' <= word[i] && word[i] <= 'z') return false;
                }
            } else if ('a' <= word[1] && word[1] <= 'z')
            {
                for (int i = 2; i < word.length(); ++i)
                {
                    if ('A' <= word[i] && word[i] <= 'Z') return false;
                }
            }

        } else if ('a' <= word[0] && word[0] <= 'z')
        {
            for (int i = 1; i < word.length(); ++i)
            {
                if ('A' <= word[i] && word[i] <= 'Z') return false;
            }
        } else
        {
            return false;
        }
        return true;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
