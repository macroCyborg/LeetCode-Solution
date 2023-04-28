/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    if (points.size() == 0)
      return 0;
    sort(points.begin(), points.end(),
         [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

    int removed = 1;
    int x_end = points[0][1];
    for (auto point : points) {
      int arraw = point[0];
      if(arraw> x_end){
        ++removed;
        x_end = point[1];
      }
    }
    return removed;
    }
};
// @lc code=end
