#include "leetcode/editor/en/[4]Median of Two Sorted Arrays.cpp"

using namespace std;

int main()
{
    Solution solution;
    //Test
    vector<int> a,b;
    a.push_back(1);
    a.push_back(3);
    b.push_back(2);
    cout << solution.findMedianSortedArrays(a,b);
    return 0;
}
