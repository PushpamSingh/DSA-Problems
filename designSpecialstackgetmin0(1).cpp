#include <stack>
#include <limits.h>
class SpecialStack {
    public:
    stack<int> s;
    int mini=INT_MAX;
    void push(int data) {
        // Implement the push() function.
        if(s.empty()){
            s.push(data);
            mini=data;
        }else{
            if(data<mini){
                int val=2*data-mini;
                s.push(val);
                mini=data;
            }else{
                s.push(data);
            }
        }
    }

    void pop() {
        // Implement the pop() function.
        if(s.empty()){
            return;
        }
        else{
             int data=s.top();
            if(data>mini){
                s.pop();
            }else{
                int val=2*mini-data;
                mini=val;
                s.pop();
            }
        }
    }

    int top() {
        // Implement the top() function.
        if(s.empty()){
            return -1;
        }
        return s.top()<mini?mini:s.top();
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty()){
            return -1;
        }
        return mini;
    }  
};