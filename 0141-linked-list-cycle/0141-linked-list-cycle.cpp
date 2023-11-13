/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while(fast != nullptr && slow != nullptr){
            fast = fast->next;
            if(fast != nullptr && fast->next != nullptr){
                // if possible, fast goes 2 at a time
                fast = fast->next;
            }
            else{  
                // this means fast eventually hits nullptr, then return false
                return false;
            }
            slow = slow->next;

            if(slow == fast){
                return true;
            }
        }

        return false;
    }
};