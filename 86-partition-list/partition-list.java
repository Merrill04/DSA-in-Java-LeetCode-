/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        if(head == null || head.next == null){
            return head;
        }
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode prev = dummy;
        
        while(prev.next != null && prev.next.val < x){
            prev = prev.next;
        }

        ListNode temp = prev;

        while(temp.next != null){
            if(temp.next.val < x){
                ListNode t = temp.next;
                temp.next = temp.next.next;
                t.next = prev.next;
                prev.next = t;
                prev = t;
            }else{
                temp = temp.next;
            }
        }

        return dummy.next;
    }
}