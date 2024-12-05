class Solution{
    
    public:
    // Your are required to complete this function
    // function should return root of the modified BST
     void inorder(Node* root,vector<int>& arr){
        if(root==NULL){
            return;
        }
        
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
    
    Node* isBalancedBST(int s,int e,vector<int> arr){
        if(s>e){
            return NULL;
        }
        
        int mid=(s+e)/2;
        
        Node* root=new Node(arr[mid]);
        root->left=isBalancedBST(s,mid-1,arr);
        root->right=isBalancedBST(mid+1,e,arr);
        return root;
    }
    Node* buildBalancedTree(Node* root)
    {
            vector<int> arr;
            inorder(root,arr);
            return isBalancedBST(0,arr.size()-1,arr);
    }
};
