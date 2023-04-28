/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.push_back(0);
    int size = flowerbed.size() -1;
    for (int i = 1; i < size; ++i) {
      if (flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0) {
        n--;
        ++i;
      }
    }
    return n <= 0;
  }
};
// @lc code=end
