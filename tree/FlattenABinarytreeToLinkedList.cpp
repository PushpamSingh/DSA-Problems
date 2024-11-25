class Solution
{
    public:
    void flatten(Node *root)
    {
        Node* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                curr=curr->right;
            }
            else{
                Node* prev=curr->left;
                while(prev->right!=NULL){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr->right;
                    curr->right=curr->left;
                    curr->left=NULL;
                    curr=curr->right;
                }
            }
        }
    }
};