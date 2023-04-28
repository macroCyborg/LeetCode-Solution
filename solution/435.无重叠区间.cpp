/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {

    return interValSchedule(intervals);
  }

  int interValSchedule(vector<vector<int>> &intvs) {
    int n = intvs.size();
    if (intvs.empty()) return 0;

    // 先将内部第二层素组按End升序  题干中每个数组仅两个元素
    sort(intvs.begin(), intvs.end(),
         [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

    // 至少有一个区间不相交
    int removed = 0;
    int x_end = intvs[0][1];
    for (int[] interval : intvs) {
      int start = interval[0];
      if (start >= x_end) {
        ++removed;
        x_end = interval[1];
      }
    }
    return removed;
  }
};
// @lc code=end
