bool search(Node* root, int x) {
    // Your code here
    bool ans;
    if(root==NULL){
        return root;
    }
    
    if(root->data==x){
         return true;
    }
    else if(x>root->data){
        ans=search(root->right,x);
    }else{
        ans=search(root->left,x);
    }
    return ans;
    
    
}