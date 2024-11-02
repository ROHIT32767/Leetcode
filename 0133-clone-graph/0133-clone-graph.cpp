/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* recursion(Node* node,map<Node*,Node*>& vis){
        if(!node){
            return 0;
        }
        Node* new_node = new Node(node->val);
        vis[node] = new_node;
        vector<Node*> temp;
        for(auto temp_node:(node->neighbors)){
            if(!vis[temp_node]){
                Node* new_temp_node = recursion(temp_node,vis);
                temp.push_back(new_temp_node);
            }
            else{
                temp.push_back(vis[temp_node]);
            }
        }
        new_node->neighbors = temp;
        return new_node;
    }
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> vis;
        Node* new_node = recursion(node,vis);
        return new_node;
    }
};