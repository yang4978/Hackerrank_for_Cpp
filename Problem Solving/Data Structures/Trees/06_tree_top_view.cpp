//https://www.hackerrank.com/challenges/tree-top-view/problem

#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void topView(Node * root) {
        queue<tuple<Node*,int>> q;
        q.push({root,0});
        map<int, vector<int>> dict;
        while(!q.empty()){
            tuple<Node*,int> i = q.front();
            if(get<0>(i)!=NULL){
                dict[get<1>(i)].push_back(get<0>(i)->data);
                q.push({get<0>(i)->left,get<1>(i)-1});
                q.push({get<0>(i)->right,get<1>(i)+1});
            }
            q.pop();
        }

        //in cpp, map is already sorted by keys
        for(auto i:dict){
            cout<<i.second[0]<<" ";
        }
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.topView(root);
    return 0;
}
