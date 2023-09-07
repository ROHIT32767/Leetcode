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
    ListNode* Reverse(ListNode*head,int n)
    {
        // {1,2,3},2
        ListNode* temp = head;
        int count = 1;
        ListNode* prev = 0;
        while(temp && count<n)
        {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            count++;
        }
        ListNode* next = temp->next;
        temp->next = prev;
        head->next = next;
        return temp;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)
        {
            return head;
        }
        ListNode* temp = head;
        int count = 1;
        ListNode* prev = 0;
        while(temp)
        {
            if(count==left)
            {
                if(prev==0)
                {
                    return Reverse(temp,right-left+1);
                }
                else
                {
                   prev->next =  Reverse(temp,right-left+1);
                   return head;
                }
            }
            prev = temp;
            temp = temp->next;
            count++;
        }
        return 0;
    }
};