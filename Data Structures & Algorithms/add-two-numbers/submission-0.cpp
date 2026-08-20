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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* i=l1;
        ListNode* j=l2;
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        int carry=0;

        while(i || j || carry){
            int value=carry;
           
            if(i){
                value += i->val;
                i=i->next; 
            }

            if(j){
                value += j->val;
                j=j->next;
            
            }

            carry = value / 10;
            cout << carry;
            temp->next=new ListNode(value % 10);
            temp=temp->next;
        }
       return dummy->next;
    }
};
