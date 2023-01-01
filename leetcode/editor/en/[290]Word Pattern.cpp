/**
Given a pattern and a string s, find if s follows the same pattern. 

 Here follow means a full match, such that there is a bijection between a 
letter in pattern and a non-empty word in s. 

 
 Example 1: 

 
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
 

 Example 2: 

 
Input: pattern = "abba", s = "dog cat cat fish"
Output: false
 

 Example 3: 

 
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 

 
 Constraints: 

 
 1 <= pattern.length <= 300 
 pattern contains only lower-case English letters. 
 1 <= s.length <= 3000 
 s contains only lowercase English letters and spaces ' '. 
 s does not contain any leading or trailing spaces. 
 All the words in s are separated by a single space. 
 

 Related Topics Hash Table String 👍 5233 👎 591

*/
#include <vector>
#include <string>
#include <regex>
#include <map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> clips;
        Split(s, " ", clips);
        if (clips.size() != pattern.length()) return false;
        map<string, string> pattern_s_map;
        map<string, string> s_pattern_map;

        for (int i = 0; i < pattern.length(); ++i)
        {
            auto b = to_string(pattern[i]);
            auto a = pattern_s_map.find(b);
            if (a != pattern_s_map.end())
            {
                if (a->second != clips[i])
                {
                    return false;
                }
            } else
            {
                pattern_s_map[b] = clips[i];
                auto c = s_pattern_map.find(clips[i]);
                if (c != s_pattern_map.end())
                {
                    if (c->second != b)
                    {
                        return false;
                    }
                } else
                {
                    s_pattern_map[clips[i]] = b;
                }

            }
        }
        return true;
    }

private:
    static void Split(const string &str, const string &split, vector<string> &res)
    {
        regex reg(split);
        sregex_token_iterator pos(str.begin(), str.end(), reg, -1);
        decltype(pos) end;
        for (; pos != end; ++pos)
        {
            res.push_back(pos->str());
        }
    }

};
//leetcode submit region end(Prohibit modification and deletion)
