class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    bool Knows(vector<vector<int> >& mat,int a, int b){
        if(mat[a][b]==1){
            return true;
        }
        
        return false;
    }
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int> s;
        int n=mat.size();
        //step1: Push all the element in the stack
        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        //step2: while s.size()!=1 check a knows b or b knows a
        while(s.size()>1){
            int a=s.top();
            s.pop();
            
            int b=s.top();
            s.pop();
            
            if(Knows(mat,a,b)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        
        //step3:s.top() can be celebrity so check rows and column 
        
        int ans=s.top();
        
        bool rowCheck=false;
        int zeroCount=0;
        
        //row check
        for(int i=0;i<n;i++){
            if(mat[ans][i]==0){
                zeroCount++;
            }
        }
        
        if(zeroCount==n){
            rowCheck=true;
        }
        
        //column check
        bool columnCkeck=false;
        int oneCount=0;
        
        for(int i=0;i<n;i++){
            if(mat[i][ans]==1){
                oneCount++;
            }
        }
        
        if(oneCount==n-1){
            columnCkeck=true;
        }
        
        if(rowCheck==true && columnCkeck==true){
            return ans;
        }
        else{
            return -1;
        }
        
    }
};