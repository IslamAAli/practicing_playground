

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
    Node *lca(Node *root, int v1,int v2) {
        
        int small = v1;
        int large = v2;

        if (v1 > v2)
        {
            small = v2 ;
            large = v1 ;
        }
		// Write your code here.
        Node* res = NULL; 
        bool LCAFound = false; 
        Node* currentNode = root;

        while (!LCAFound)
        {
            if (small <= currentNode->data && large >= currentNode->data)
            {
                res=  currentNode;
                LCAFound = true;
            }
            else if (small < currentNode->data && large < currentNode->data)
            {
                currentNode = currentNode->left;
            }
            else
            {
                currentNode = currentNode->right;
            }
        }
        return res;
    }
    
