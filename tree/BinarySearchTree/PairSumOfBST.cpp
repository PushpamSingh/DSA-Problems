class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    void inorder(struct Node* root,vector<int>& arr){
        if(root==NULL){
            return;
        }
        
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
    
    int isPairPresent(struct Node *root, int target)
    {
    //add code here.
    vector<int> arr;
    inorder(root,arr);
    int i=0;
    int j=arr.size()-1;
    while(i<j){
        int sum=arr[i]+arr[j];
        if(sum==target){
            return 1;
        }
        else if(sum>target){
            j--;
        }
        else{
            i++;
        }
    }
    return 0;
    }
};