/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> M;
        Node* temp = head;
        Node* new_head = 0;
        Node* prev = 0;
        while(temp){
            Node* new_node = new Node(temp->val);
            M[temp] = new_node;
            if(prev){
                prev->next = new_node;
            }
            else{
                new_head = new_node;
            }
            prev = new_node;
            temp = temp->next;
        }
        temp = head;
        while(temp){
            Node* copy_node = M[temp];
            copy_node->random = M[temp->random];
            temp = temp->next;
        }
        return new_head;
    }
};