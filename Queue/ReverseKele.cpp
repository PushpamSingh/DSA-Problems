
class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
       stack<int> s;
       int n=q.size();
       int count=0;
       while(count!=k){
           int ele=q.front();
           q.pop();
           s.push(ele);
           count++;
       }
       
       while(!s.empty()){
           int ele=s.top();
           s.pop();
           q.push(ele);
       }
       
       count=0;
       while(count!=n-k){
           int ele=q.front();
           q.pop();
           q.push(ele);
           count++;
         }
         
         return q;
       
    }
};
