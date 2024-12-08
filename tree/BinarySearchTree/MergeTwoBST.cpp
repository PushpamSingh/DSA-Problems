class Solution {
  private:
    void Inorder(Node* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        
        Inorder(root->left,ans);
        ans.push_back(root->data);
        Inorder(root->right,ans);
    } 
    vector<int> mergeArrays(vector<int>&arr1,vector<int>&arr2){
        int i=0,j=0,k=0;
        vector<int> ans(arr1.size()+arr2.size());
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]<arr2[j]){
                ans[k++]=arr1[i];
                i++;
            }else{
                ans[k++]=arr2[j];
                j++;
            }
        }
        while(i<arr1.size()){
            ans[k++]=arr1[i++];
        }
        while(j<arr2.size()){
            ans[k++]=arr2[j++];
        }
        return ans;
    }
    Node* IntoBSt(int s,int e,vector<int> in){
        if(s>e){
            return NULL;
        }
        
        int mid=(s+e)/2;
        Node* root= new Node(in[mid]);
        root->left=IntoBSt(s,mid-1,in);
        root->right=IntoBSt(mid+1,e,in);
        
        return root;
    }
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // step1: store Inorder root1,root2
        vector<int> bst1,bst2;
        Inorder(root1,bst1);
        Inorder(root2,bst2);
        //step2: merge two sorted inorder bst
        
        vector<int> mergeArray=mergeArrays(bst1,bst2);
        
        // //step3: Inorder to bst
        // int s=0,e=mergeArray.size()-1;
        // return IntoBSt(s,e,mergeArray);
        
        return mergeArray;
        
        
    }
};