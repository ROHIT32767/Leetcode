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
    pair<ListNode*,ListNode*> reverseLinkedList(ListNode* head,int k){
        ListNode* temp = head;
        ListNode* prev = 0;
        int size = 0;
        ListNode* new_head = 0;
        ListNode* next = 0;
        while(size<k && temp){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            new_head = temp;
            temp = next;
            size++;
        }
        return make_pair(new_head,next);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;
        while(temp){
            size++;
            temp = temp->next;
        }
        int rem = size;
        ListNode* new_head = 0;
        temp = head;
        ListNode* prev = 0;
        temp = head;
        while(rem>=k){
            pair<ListNode*,ListNode*> P = reverseLinkedList(temp,k);
            if(!prev){
                new_head = P.first;
            }
            else{
                prev->next = P.first;
            }
            prev = temp;
            temp = P.second;
            rem-=k;
        }
        if(rem>0){
            prev->next = temp;
        }
        return new_head;
    }
};