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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res;
        vector<int> criticalpoints;

        ListNode* temp = head;
        int prev = temp -> val;
        temp = temp -> next;
        int count = 2;
        while(temp -> next != nullptr){
            if(temp -> val > prev && temp -> val > temp -> next -> val){
                criticalpoints.push_back(count);
            }

            if(temp -> val < prev && temp -> val < temp -> next -> val){
                criticalpoints.push_back(count);
            }

            count++;
            prev = temp -> val;
            temp = temp -> next;
        }

        if(criticalpoints.size() < 2){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }

        int min = INT_MAX;

        for(int i = 0; i < criticalpoints.size() - 1; i++){
            if(criticalpoints[i+1] - criticalpoints[i] < min){
                min = criticalpoints[i + 1] - criticalpoints[i];
            }
        }

        res.push_back(min);
        res.push_back(criticalpoints[criticalpoints.size() - 1] - criticalpoints[0]);

        return res;
    }
};