#include <iostream>
#include "leetcode/editor/en/[63]Unique Paths II.cpp"

using namespace std;

int main()
{
    vector<vector<int>> vec{{0, 0},
                            {1, 1},
                            {0, 0}};
    //Test
    cout << Solution::uniquePathsWithObstacles(vec);
    return 0;
}
