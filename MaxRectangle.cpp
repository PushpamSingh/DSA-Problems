class Solution{
    private:
       vector<int> nextSmallerElement(int *arr, int n){
       stack<int> s;
	   s.push(-1);
	   vector<int> ans(n);
	   for(int i=n-1;i>=0;i--){
	       int curr=arr[i];
	        
	       while(s.top()!=-1 && arr[s.top()]>=curr){
	           s.pop();
	       }
	       ans[i]=s.top();
	       s.push(i);
	        
       }
        return ans;
}
    vector<int> prevSmallerElement(int *arr, int n){
       stack<int> s;
	   s.push(-1);
	   vector<int> ans(n);
	   for(int i=0;i<n;i++){
	       int curr=arr[i];
	        
	       while(s.top()!=-1 && arr[s.top()]>=curr){
	           s.pop();
	       }
	       ans[i]=s.top();
	       s.push(i);
	        
       }
        return ans;
}
public:
    int largestRectangleArea(int *heights,int n) {
        // int n=heights.size();

        vector<int> nextind;
        nextind=nextSmallerElement(heights,n);

        vector<int> prevind;
        prevind=prevSmallerElement(heights,n);

        int area= INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(nextind[i]==-1){
                nextind[i]=n;
            }
            int b=nextind[i]-prevind[i]-1;

            int newarea=l*b;
            area=max(area,newarea);

        }
        return area;

    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int area=largestRectangleArea(M[0],m);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]!=0){
                    M[i][j]=M[i][j]+M[i-1][j];
                }else{
                    M[i][j]=0;
                }
            }
            
            int newArea=largestRectangleArea(M[i],m);
            area=max(area,newArea);
        }
        return area;
    }
    
};