#include<limits.h>
void push(stack<int>& s, int a){
	// Your code goes here
    s.push(a);
    return;
	
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
    return s.size()==n;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
    return s.empty();
}

int pop(stack<int>& s){
	// Your code goes here
    int val=s.top();
    s.pop();
    return val;
}


int getMin(stack<int>& s){
	// Your code goes here
	int mini=INT_MAX;
	while(!s.empty()){
	    mini=min(mini,s.top());
	    s.pop();
	}
	return mini;
}