class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        queue<int> newq;
        vector<int> ans;
        int n;
        if(q.size()%2==0){
           n=q.size()/2;
        }else{
           n=(q.size()/2)+1;
        }
        
        for(int i=0;i<n;i++){
            int val=q.front();
            q.pop();
            newq.push(val);
        }
        
        while(!newq.empty()){
            int val=newq.front();
            newq.pop();
            ans.push_back(val);
            int val2=q.front();
            q.pop();
            ans.push_back(val2);
        }
        return ans;
    }
};