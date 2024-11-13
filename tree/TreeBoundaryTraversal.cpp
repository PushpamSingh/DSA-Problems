class Solution {
public:
    void leftNode(Node* root,vector<int> &ans){
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return;
        }
       
        ans.push_back(root->data);
        if(root->left){
            leftNode(root->left,ans);
        }else{
            leftNode(root->right,ans);
        }
        
}

void leafNode(Node* root,vector<int>& ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    if(root->left){
        leafNode(root->left,ans);
    }
    if(root->right){
        leafNode(root->right,ans);
    }
}

void rightNode(Node* root,vector<int>& ans){
    if(root==NULL ||(root->left==NULL && root->right==NULL)){
        return;
    }
    
    if(root->right){
        rightNode(root->right,ans);
    }
    else{
        rightNode(root->left,ans);
    }
    ans.push_back(root->data);
}
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        //left Node
        leftNode(root->left,ans);
        //leaf Node
          //1.for leftSubtree
          leafNode(root->left,ans);
          //2.for rightSubtree
          leafNode(root->right,ans);
        //right Node
        rightNode(root->right,ans);
        
        return ans;
    }
};