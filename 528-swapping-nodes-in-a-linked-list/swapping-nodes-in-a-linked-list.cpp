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
    ListNode* swapNodes(ListNode* head, int k) {
        int size = 0;

        ListNode* curr = head;

        while(curr != nullptr){
            curr = curr -> next;
            size++;
        }

        ListNode* first = head;
        ListNode* second = head;

        int f = k;
        int s = size - k + 1;

        while(f > 1){
            first = first -> next;
            f--;
        }

        while(s > 1){
           second = second -> next;
            s--;
        }

        int t = first -> val;
        first -> val = second -> val;
        second -> val = t;

        return head;
    }
};