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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2){
            return nullptr;
        }
        
        ListNode *nh = new ListNode(INT_MAX);
        
        ListNode *trav = nh;
        while(list1 != nullptr || list2 != nullptr){
            ListNode *next;
            if(list1 && list2){
                if(list1->val > list2->val){
                    next = new ListNode(list2->val);
                    list2 = list2->next;
                }
                else{
                    next = new ListNode(list1->val);
                    list1 = list1->next;
                }
            }
            else if(list1){
                next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else{
                next = new ListNode(list2->val);
                list2 = list2->next;
            }
            trav->next = next;
            trav = trav->next;
        }
        
        return nh->next;
    }
};