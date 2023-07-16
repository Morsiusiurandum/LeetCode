//In a project, you have a list of required skills req_skills, and a list of 
//people. The iᵗʰ person people[i] contains a list of skills that the person has. 
//
// Consider a sufficient team: a set of people such that for every required 
//skill in req_skills, there is at least one person in the team who has that skill. 
//We can represent these teams by the index of each person. 
//
// 
// For example, team = [0, 1, 3] represents the people with skills people[0], 
//people[1], and people[3]. 
// 
//
// Return any sufficient team of the smallest possible size, represented by the 
//index of each person. You may return the answer in any order. 
//
// It is guaranteed an answer exists. 
//
// 
// Example 1: 
// Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],[
//"nodejs"],["nodejs","reactjs"]]
//Output: [0,2]
// 
// Example 2: 
// Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], 
//people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java",
//"csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
//Output: [1,2]
// 
// 
// Constraints: 
//
// 
// 1 <= req_skills.length <= 16 
// 1 <= req_skills[i].length <= 16 
// req_skills[i] consists of lowercase English letters. 
// All the strings of req_skills are unique. 
// 1 <= people.length <= 60 
// 0 <= people[i].length <= 16 
// 1 <= people[i][j].length <= 16 
// people[i][j] consists of lowercase English letters. 
// All the strings of people[i] are unique. 
// Every skill in people[i] is a skill in req_skills. 
// It is guaranteed a sufficient team exists. 
// 
//
// Related Topics Array Dynamic Programming Bit Manipulation Bitmask 👍 1537 👎 
//41
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    vector<int> res;

    void helper(int i, vector<int> &people_skill, int m, int mask, vector<int> &ans, vector<vector<int>> &dp)
    {
        //Base Case
        if (i == people_skill.size())
        {
            //Check for all req_skills included
            if (mask == ((1 << m) - 1))
            {
                //Better answer then update
                if (res.empty() || (ans.size() < res.size())) res = ans;
            }

            return;
        }

        //Memoization Part
        if (dp[i][mask] != -1)
        {
            if (dp[i][mask] <= ans.size()) return;

        }
        //Non-Pick / Ignore Case
        helper(i + 1, people_skill, m, mask, ans, dp);

        // Pick Case
        ans.push_back(i);

        //Next Call
        helper(i + 1, people_skill, m, (mask | people_skill[i]), ans, dp);

        //Undo the change in Pick
        ans.pop_back();

        if (!ans.empty()) dp[i][mask] = (int) ans.size(); //if found and answer then update DP
    }


    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
    {

        auto n = people.size();
        auto m = req_skills.size();

        //for hashing skill v/s bit
        unordered_map<string, int> mpp;

        //setting ith bit, for req_skill[i] skill
        for (int i = 0; i < m; ++i) mpp[req_skills[i]] = (1 << i);

        //vector of mask for peoples
        vector<int> people_skill;

        for (const auto &it: people)
        {
            int mask = 0;
            for (const auto &j: it)
            {
                //if it[j] is a required skill then set that bit for that people's mask
                if (mpp.count(j)) mask |= mpp[j];
            }
            //store the mask
            people_skill.push_back(mask);
        }

        //n=number of people, and (1<<m) to express all value mask of size m can take
        vector<vector<int>> dp(n, vector<int>((1 << m), -1));
        vector<int> ans;

        helper(0, people_skill, (int) m, 0, ans, dp);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
