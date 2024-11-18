class Solution {
  public:
  int findPos(vector<int>& in, int n, int ele){
        for(int i=0; i<n; i++){
            if(in[i]==ele){
                return i;
            }
        }
        return -1;
    }
Node* solve(vector<int> &in, vector<int> &pre, int &index, int inorderStart, int inorderEnd, int n){
      if(index>=n or inorderStart>inorderEnd ){
            return nullptr;
        }
        int ele= pre[index++];
        Node* root= new Node(ele);
        int pos= findPos(in, n, ele);
        root->left=solve(in, pre, index, inorderStart, pos-1, n);
        root->right= solve(in, pre, index, pos+1, inorderEnd, n );
        return root;
}
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = inorder.size();
        int preindex = 0;
        return solve(inorder, preorder, preindex, 0, n - 1, n);
    }
};