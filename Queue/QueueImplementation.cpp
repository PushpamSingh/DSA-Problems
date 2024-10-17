#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int f;
    int r;
    int size;
public:
    Queue() {
        size=10001;
        arr=new int[size];
        f=0;
        r=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return r==f;
    }

    void enqueue(int data) {
        if(r==size){
            return;
        }
        else{
            arr[r]=data;
            r++;
        }
    }

    int dequeue() {
       if(f==r){
           return -1;
       }else{
           int ans=arr[f];
           arr[f]=-1;
           f++;
           if(r==f){
               r=0;
               f=0;
           }
           return ans;
       }
    }

    int front() {
        if(r==f){
            return -1;
        }
        else{
            return arr[f];
        }
    }
};