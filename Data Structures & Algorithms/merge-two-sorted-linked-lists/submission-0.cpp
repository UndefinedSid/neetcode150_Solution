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
        ListNode* i=list1;
        ListNode* j=list2;
        ListNode dummy(0);
        ListNode* ans=&dummy;
        
        while(i !=NULL && j != NULL){
           
            if(i->val >= j->val){
                ans->next=j;
                j=j->next;

            }else{
                ans->next=i;
                i=i->next;
            }
            ans=ans->next;
        }
        if(i != nullptr)
            ans->next=i;
        else
            ans->next=j;

        return dummy.next;
    }
};
