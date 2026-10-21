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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* res = head;
        ListNode* start = head;

        while(start != nullptr){
            ListNode* curr = start -> next;

            while(curr != nullptr && curr -> val != 0){
                start -> val += curr -> val;
                curr = curr -> next;
            }

            start -> next = curr -> next;
            start = curr -> next;
        }

        return res;
    }
};