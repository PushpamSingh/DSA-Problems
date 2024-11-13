 vector <int> zigZagTraversal(Node* root)
    {
        vector<int> res;
        if(root==NULL){
            return res;
        }
        
        queue<Node*> q;
        q.push(root);
        
        bool leftToright=true;
        while(!q.empty()){
            int size=q.size();
            vector<int> ans(size);
            
            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();
                
                int index=leftToright?i:size-i-1;
                ans[index]=temp->data;
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            
            //change direction
            leftToright=!leftToright;
            
            for(auto i:ans){
                res.push_back(i);
            }
        }
        return res;
    }
};