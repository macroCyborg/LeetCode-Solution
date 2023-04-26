/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
  int candy(vector<int> &ratings) {
    int size = ratings.size();
    if (size < 2) {
      return size;
    }
    vector<int> num(size, 1);
    for (int i = 1; i < size; ++i) {
      if (ratings[i] > ratings[i - 1]) {
        num[i] = num[i - 1] + 1;
      }
    }
    for (int i = size - 1; i > 0; --i) {
      if (ratings[i] < ratings[i - 1]) {
        num[i - 1] = max(num[i - 1], num[i] + 1);
      }
    }
    // std::accumulate 可以很方便地求和
    return accumulate(num.begin(), num.end(), 0);
  }
};
// @lc code=end
