 void InsertAtBottom(stack<int>&st,int num){
        if(st.empty()){
            st.push(num);
            return;
        }
        int x=st.top();
        st.pop();
        
        InsertAtBottom(st,num);
        
        st.push(x);
        
    }
    void solve(stack<int>&St){
        if(St.empty()){
            return;
        }
        int temp=St.top();
        St.pop();
        
        solve(St);
        
        InsertAtBottom(St,temp);
    }
    void Reverse(stack<int> &St){
       
        solve(St);
    }