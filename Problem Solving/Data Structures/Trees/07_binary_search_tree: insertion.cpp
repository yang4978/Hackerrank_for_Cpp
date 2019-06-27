//https://www.hackerrank.com/challenges/binary-search-tree-insertion/problem

#include <bits/stdc++.h>

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
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
Node is defined as 

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

    Node * insert(Node * root, int data) {
        Node* new_node = new Node(data);
        if(root){
            Node* current_node = root;
            while(1){
                if(data<current_node->data){
                    if(current_node->left){
                        current_node = current_node->left;
                    }
                    else{
                        current_node->left = new_node;
                        break;
                    }
                }
                else{
                    if(current_node->right){
                        current_node = current_node->right;
                    }
                    else{
                        current_node->right = new_node;
                        break;
                    }
                }
            }
        }
        else{
            root = new_node;
        }

        return root;
    }

};

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
  	
    myTree.preOrder(root);
  
    return 0;
}
