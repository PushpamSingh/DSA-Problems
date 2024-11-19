class Solution {
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    int findPos(vector<int> in,int ele){
        for(int i=0;i<in.size();i++){
            if(in[i]==ele){
                return i;
            }
        }
        return -1;
    }
    Node* solve(vector<int> inorder, vector<int> postorder ,int& index,
                        int postorderStart,int postorderEnd,int n){
            
            if(index < 0 || postorderStart>postorderEnd){
                return NULL;
            }               
            
            int ele=postorder[index--];
            Node* root=new Node(ele);
            int position=findPos(inorder,ele);
            
            root->right=solve(inorder,postorder,index,position+1,postorderEnd,n);
            root->left=solve(inorder,postorder,index,postorderStart,position-1,n);
            return root;
    }
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        int size=inorder.size();
        int index=size-1;
        Node* ans=solve(inorder,postorder,index,0,size-1,size);
        return ans;
    }
};
