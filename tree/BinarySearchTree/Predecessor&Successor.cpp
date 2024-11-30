class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        Node* temp=root;
        while(temp->key!=key){
            if(temp->key>key){
                suc=temp;
                temp=temp->left;
            }
            else{
                pre=temp;
                temp=temp->right;
            }
        }
        
        Node* leftTree=temp->left;
        while(leftTree!=NULL){
            pre=leftTree;
            leftTree=leftTree->right;
        }
        
        Node* rightTree=temp->right;
        while(rightTree!= NULL){
            suc=rightTree;
            rightTree=rightTree->left;
        }
    }
};