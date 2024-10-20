#include<iostream>
#include<queue>
using namespace std;

class Nqueue{
    public:
        int n;
        int k;
        int freeSpot;
        int *arr;
        int *front;
        int *rear;
        int *next;
    public:
        Nqueue(int n,int k){
            this->n=n;
            this->k=k;
            front=new int[n];
            rear=new int[n];
            for(int i=0;i<n;i++){
                front[i]=-1;
                rear[i]=-1;
            }
            arr=new int[n];
            next=new int[n];
            for (int i = 0; i < n; i++)
            {
                next[i]=i+1;
            }
            next[n-1]=-1;
            freeSpot=0;
        }

        void enqueue(int data,int qn){
            if(freeSpot==-1){
                cout<<"Queue overflow";
                return;
            }
            int index=freeSpot;
            freeSpot=next[index];
            
            if(front[qn-1]==-1){
                front[qn-1]=index;
            }
            else{
                next[rear[qn-1]]=index;
            }

            next[index]=-1;
            rear[qn-1]=index;
            arr[index]=data;


        }
    int dequeue(int qn){
        if(front[qn-1]==-1){
            cout<<"Queue Underflow";
            return -1;
        }

        int index=front[qn-1];

        front[qn-1]=next[index];
        next[index]=freeSpot;
        freeSpot=index;
        return arr[index];
    }
};
int main(){
    Nqueue q(10,3);

    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(10,1);


}