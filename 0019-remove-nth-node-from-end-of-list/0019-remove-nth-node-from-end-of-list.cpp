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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *trav = head;

        while(trav != nullptr){
            len++;
            trav = trav->next;
        }

        trav = head;
        ListNode *trail = nullptr;
        for(int i = 0; i < len-n; i++){
            trail = trav;
            trav = trav->next;
        }

        if(trav == head){
            // we haven't moved, just delete first node
            head = head->next;
        }
        else if(trav->next == nullptr){
            // we are at last node, just point trail to nothing
            trail->next = nullptr;
        }
        else{
            trail->next = trav->next;
        }

        return head;
    }
};