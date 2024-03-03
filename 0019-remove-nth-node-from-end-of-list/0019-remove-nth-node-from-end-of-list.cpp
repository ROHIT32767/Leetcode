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
        struct ListNode* P=head;
        long long int count=0;
        while(P)
        {
            count++;
            P=P->next;
        }
        struct ListNode* Q=head;
        if(count==n)
        {
            return head->next;
        }
        for(int i=0;i<count-n-1;i++)
        {
            Q=Q->next;
        }
        if(Q && Q->next)
        {
            struct ListNode* R=Q->next;
            Q->next=R->next;
        }
        return head;
    }
};