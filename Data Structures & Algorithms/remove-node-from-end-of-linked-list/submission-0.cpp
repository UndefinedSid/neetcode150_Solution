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
        if(head==NULL)
            return head;

        stack<ListNode*> st;
        ListNode* curr=head;
        while(curr != NULL){
            st.push(curr);
            curr=curr->next;
        }
        curr=head;
        stack<ListNode*> tempSt;

        while(n > 0){
            ListNode* topNode=st.top();
            st.pop();
            n--;
            if(n > 0)
                tempSt.push(topNode);
            else{
                topNode->next=nullptr;
            }
        }

        if(st.empty())
            return tempSt.empty() ? nullptr : tempSt.top();

        if(! tempSt.empty())
            st.top()->next=tempSt.top();
        else
            st.top()->next=nullptr;

        return head;

    }
};
