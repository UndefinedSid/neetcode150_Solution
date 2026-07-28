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
    ListNode* reverseList(ListNode* head) {
        /* 
        // Iterative approach -> inplace

        ListNode* nxt=nullptr;
        ListNode* prev=nullptr;
        ListNode* curr=head;

        while(curr != nullptr){
           nxt=curr->next;
           curr->next=prev;
           prev=curr;
           curr=nxt;

        }
        return prev;

        */ 

        // Recursive approach-> O(n) space

        if(! head || head->next==nullptr)
            return head;

        ListNode* revList=reverseList(head->next);

        head->next->next=head;

        head->next=nullptr;

        return revList;
    }
};
