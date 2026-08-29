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
    int gcd(int dividend, int divisor){
        while(divisor != 0){
            int remainder = dividend % divisor;
            dividend = divisor;
            divisor = remainder;
        }

        return dividend;
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;

        while(temp -> next != nullptr){
            if(temp -> val > temp -> next -> val){
                int n = gcd(temp -> val, temp -> next -> val);
                ListNode* newnode = new ListNode(n);
                newnode -> next = temp -> next;
                temp -> next = newnode;
            }else if(temp -> val < temp -> next -> val){
                int n = gcd(temp -> next -> val, temp -> val);
                ListNode* newnode = new ListNode(n);
                newnode -> next = temp -> next;
                temp -> next = newnode;
            }else{
                ListNode* newnode = new ListNode(temp -> val);
                newnode -> next = temp -> next;
                temp -> next = newnode;
            }

            temp = temp -> next -> next;
        }

        return head;
    }
};