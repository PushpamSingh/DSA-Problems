class Solution
{
public:
 void inorder(Node* root,vector<Node*>& arr){
        if(root==NULL){
            return;
        }
        
        inorder(root->left,arr);
        arr.push_back(root);
        inorder(root->right,arr);
    }
    
    Node *flattenBST(Node *root)
    {
        // code here
         vector<Node*> arr;
    inorder(root,arr);
    int i=0;
    while(i<arr.size()-1){
        arr[i]->right=arr[i+1];
        arr[i]->left=NULL;
        i++;
    }
    arr[i]->right=NULL;
    arr[i]->left=NULL;

    return arr[0];
    }
};