class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        vector<int> ans;
        Node* curr=root;
        while(curr!=NULL){
            //if left part not exist 
            if(curr->left==NULL){
                ans.push_back(curr->data);
                curr=curr->right;
            }else{
                Node* predecessor=curr->left;
                while(predecessor->right!=NULL && predecessor->right!=curr){
                    predecessor=predecessor->right;
                }
                if(predecessor->right==NULL){
                    predecessor->right=curr;
                    curr=curr->left;
                }else{
                    predecessor->right=NULL;
                    ans.push_back(curr->data);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};