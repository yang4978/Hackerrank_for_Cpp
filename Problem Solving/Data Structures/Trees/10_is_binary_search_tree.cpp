//https://www.hackerrank.com/challenges/is-binary-search-tree/problem

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
    bool check_node(Node* root, int min_value, int max_value){
        if(root!=NULL){
            if(root->data<=min_value || root->data>=max_value){
                return false;
            }
            else{
                return check_node(root->left,min_value,root->data) & check_node(root->right,root->data,max_value);
            }
        }
        else{
            return true;
        }
    }

	bool checkBST(Node* root) {
		return check_node(root,-1,10001);
	}
