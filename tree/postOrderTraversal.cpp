//Function to return a list containing the postorder traversal of the tree.
void solve(Node* node,vector<int>& ans){
    if(node==NULL){
            return;
        }
        
        solve(node->left,ans);
        solve(node->right,ans);
        ans.push_back(node->data);
}
vector <int> postOrder(Node* root)
{
  // Your code here
  vector<int> ans;
  solve(root,ans);
  return ans;
}
