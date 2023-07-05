/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    // 存放小于 x 的链表的虚拟头结点
    ListNode* dummy1 = new ListNode(-1);
    // 存放大于等于 x 的链表的虚拟头结点
    ListNode* dummy2 = new ListNode(-1);
    // p1, p2 指针负责生成结果链表
    ListNode *p1 = dummy1, *p2 = dummy2;
    // p 负责遍历原链表，类似合并两个有序链表的逻辑
    // 这里是将一个链表分解成两个链表
    ListNode* p = head;
    while (p != nullptr) {
      if (p->val >= x) {
        p2->next = p;
        p2 = p2->next;
      } else {
        p1->next = p;
        p1 = p1->next;
      }
      // 断开原链表中的每个节点的 next 指针
      ListNode* temp = p->next;
      p->next = nullptr;
      p = temp;
    }
    // 连接两个链表
    p1->next = dummy2->next;

    return dummy1->next;
  }
};
// @lc code=end
