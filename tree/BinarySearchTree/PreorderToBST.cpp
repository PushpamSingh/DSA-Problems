class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    Node* solve(int pre[],int size,int mini,int maxi,int &i){
        if(i>=size){
            return NULL;
        }
        if(pre[i]<mini || pre[i]>maxi){
            return NULL;
        }
        
        struct Node* root=newNode(pre[i++]);
        root->left=solve(pre,size,mini,root->data,i);
        root->right=solve(pre,size,root->data,maxi,i);
        return root;
    }
    Node* Bst(int pre[], int size) {
        int mini=INT_MIN;
        int maxi=INT_MAX;
        int i=0;
        return solve(pre,size,mini,maxi,i);
    }
};