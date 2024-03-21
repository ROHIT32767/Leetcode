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
        int num=0;
        ListNode* temp = head;
        if(!head)
        {
            return head;
        }
        while(temp)
        {
            num++;
            temp=temp->next;
        }
        int A[num];
        temp=head;
        for(int i=0;i<num;i++)
        {
            A[i]=temp->val;
            temp=temp->next;
        }
        temp=head;
        for(int i=0;i<num;i++)
        {
            temp->val=A[num-i-1];
            temp=temp->next;
        }
        return head;
    }
};