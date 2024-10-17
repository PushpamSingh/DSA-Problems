void SortedInsert(stack<int>&s,int num){
    if(s.empty() || s.top()<=num){
        s.push(num);
        return;
    }
    int temp=s.top();
    s.pop();
    
    SortedInsert(s,num);
    
    s.push(temp);
}
void solve(stack<int>&s){
    if(s.empty()){
        return;
    }
    int num=s.top();
    s.pop();
    
    solve(s);
    
    SortedInsert(s,num);
}
void SortedStack :: sort()
{
   //Your code here
   solve(s);
}