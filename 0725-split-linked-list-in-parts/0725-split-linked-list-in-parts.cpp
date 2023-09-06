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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;
        while(temp)
        {
            temp = temp->next;
            size++;
        }
        vector<int> vect(k,0);
        for(int i=0;i<k;i++)
        {
            vect[i]+=size/k;
        }
        int rem = size%k;
        for(int i=0;i<k;i++)
        {
            if(rem==0)
            {
                break;
            }
            vect[i]+=1;
            rem--;
        }
        for(int i=0;i<k;i++)
        {
            cout << vect[i] << " ";
        }
        cout << endl;
        vector<ListNode*> res;
        temp = head;
        for(int i=0;i<k;i++)
        {
            if(temp)
            {
                ListNode* start = temp;
                ListNode* prev = 0;
                for(int j=0;j<vect[i];j++)
                {
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = 0;
                res.push_back(start);
            }
            else
            {
                res.push_back(0);
            }
        }
        return res;
    }
};