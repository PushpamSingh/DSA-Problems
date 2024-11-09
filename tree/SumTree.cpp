class Solution {
  public:
  pair<bool,int> isSum(Node* root){
      if(root==NULL){
          pair<bool,int> p=make_pair(true,0);
          return p;
      }
      
      if(root->left==NULL && root->right==NULL){
          pair<bool,int> p=make_pair(true,root->data);
          return p;
      }
      
      pair<bool,int> leftAns=isSum(root->left);
      pair<bool,int> rightAns=isSum(root->right);
      
      bool Left=leftAns.first;
      bool Right=rightAns.first;
      
      bool condn=root->data==leftAns.second+rightAns.second;
      
      pair<bool,int> ans;
      
      if(Left && Right && condn){
          ans.first=true;
          ans.second=root->data+leftAns.second+rightAns.second;
      }else{
          ans.first=false;
      }
      return ans;
  }
    bool isSumTree(Node* root) {
        // Your code here
        return isSum(root).first;
    }
};