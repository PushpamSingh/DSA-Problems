class Solution {
  public:
  Node* ParentmappingNode(Node* root,int target,map<Node*,Node*> &nodeToparent){
      Node* res=NULL;
      
      queue<Node*> q;
      q.push(root);
      nodeToparent[root]=NULL;
      
      while(!q.empty()){
          Node* front=q.front();
          q.pop();
          
          if(front->data==target){
              res=front;
          }
          
          if(front->left){
              nodeToparent[front->left]=front;
              q.push(front->left);
          }
          if(front->right){
              nodeToparent[front->right]=front;
              q.push(front->right);
          }
      }
      return res;
      
  }
  int burnTree(Node* root,map<Node*,Node*> &nodeToparent){
      map<Node*,bool> visited;
      queue<Node*>q;
      
      q.push(root);
      visited[root]=true;
      
      int ans=0;
      while(!q.empty()){
          int size=q.size();
          bool flag=0;
          for(int i=0;i<size;i++){
          Node* front=q.front();
          q.pop();
          if(front->left && !visited[front->left]){
             flag=1;
             q.push(front->left);
             visited[front->left]=1;
          }
          if(front->right && !visited[front->right]){
              flag=1;
              q.push(front->right);
              visited[front->right]=1;
          }
          
          if(nodeToparent[front] && !visited[nodeToparent[front]]){
              flag=1;
              q.push(nodeToparent[front]);
              visited[nodeToparent[front]]=1;
          }
              
          }
          if(flag==1){
              ans++;
          }
      }
      return ans;
  }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*> nodeToparent;
        Node* targetNode=ParentmappingNode(root,target,nodeToparent);
        
        int ans=burnTree(targetNode,nodeToparent);
        return ans;
    }
};