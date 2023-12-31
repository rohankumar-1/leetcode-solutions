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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        ListNode *res = new ListNode(INT_MAX);
        ListNode *trav = res;
        ListNode *trail = NULL;
    
        while(1){
            int minVal = INT_MAX;
            int minIdx = INT_MAX;
            
            for(int i = 0; i < lists.size(); i++){
                if(lists[i]){
                    if(lists[i]->val < minVal){
                        minVal = lists[i]->val;
                        minIdx = i;
                    }
                }
            }
            
            // find next empty
            if(minVal == INT_MAX){
                // we did not update any value, so break out of while loop
                break;
            }
            
            // add to res, and update list that contributed minVal
            trav->val = minVal; // set new val
            lists[minIdx] = lists[minIdx]->next;    // update lists
            
            trav->next = new ListNode(INT_MAX);    // create next node
            trail = trav;
            trav = trav->next;              // move to next node
        }
        
        if(trav->val == INT_MAX){
            if(trail){
                trail->next = NULL;
            }
            else{
                return NULL;
            }
        }
        
        return res;
    }
};