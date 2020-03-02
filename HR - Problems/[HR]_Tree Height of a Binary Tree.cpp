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
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        if (root->left == NULL && root->right == NULL)
            return 0;
        else
        {
            int heightL = 0 ;
            int heightR = 0 ;
            
            if (root->left != NULL)
                heightL = height(root->left);
            
            if (root->right != NULL)
                heightR = height(root->right);
                
            if (heightL > heightR)
                return heightL+1;
            else
                return heightR+1;
        }
    }

}; //End of Solution