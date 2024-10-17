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