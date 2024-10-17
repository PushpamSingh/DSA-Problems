 class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool isMatching(char top, char ch){
        if(top=='(' && ch==')'){
            return true;
        }
        else if(top=='{' && ch=='}'){
            return true;
        }
        else if(top=='[' && ch==']'){
            return true;
        }
        
        return false;
    }
    bool ispar(string x)
    {
        // Your code here
        stack<char> s;
        
        for(int i=0;i<x.length();i++){
            char ch=x[i];
            if(ch=='(' || ch=='{' || ch=='['){
                s.push(ch);
            }
            else{
                if(!s.empty()){
                        char top=s.top();
                        if(isMatching(top,ch)){
                            s.pop();
                        }else{
                            return false;
                        }
                }else{
                    return false;
                }
            }
        }
        
        if(s.empty())
            return true;
        else
            return false;
    }

};