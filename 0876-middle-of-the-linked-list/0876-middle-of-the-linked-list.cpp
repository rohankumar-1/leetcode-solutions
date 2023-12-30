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
    ListNode* middleNode(ListNode* head) {
        // fast pointer slow pointer ?
        ListNode *fast = head;
        ListNode *slow = head;
        
        // fast goes double speed as slow, when fast reaches end, return slow
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if(fast->next){
            return slow->next;
        }
        else{
            return slow;
        }
    }
};