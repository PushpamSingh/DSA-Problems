void solve(Node* root,int &count){
        if(root==nullptr){
            return;
        }
        
        solve(root->left,count);
        if(root->left==NULL and root->right==NULL){
            count++;
        }
        solve(root->right,count);
    }
int countLeaves(Node* root) {
    // Your code here
    int count=0;
    solve(root,count);
    return count;
}
