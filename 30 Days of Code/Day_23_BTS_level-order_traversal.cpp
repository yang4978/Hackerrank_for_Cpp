//https://www.hackerrank.com/challenges/30-binary-trees/problem

#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;	
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }           
           return root;
           }
        }

	void levelOrder(Node * root){
        deque<Node*> treeQueue;
        
        if(root){
            treeQueue.push_back(root);
        }

        while(!treeQueue.empty()){
            Node* tree = treeQueue.front();
            treeQueue.pop_front();
            cout<<tree->data<<" ";
            if(tree->left){
                treeQueue.push_back(tree->left);
            }
            if(tree->right){
                treeQueue.push_back(tree->right);
            }
        }
    }

};//End of Solution
