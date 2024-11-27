#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int d){
            this->data=d;
            this->left=NULL;
            this->right=NULL;
        }
};
void levelOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }

}
Node* insertIntoBSt(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }

    if(data<root->data){
        root->left=insertIntoBSt(root->left,data);
    }
    else{
        root->right=insertIntoBSt(root->right,data);
    }
    return root;
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        cout<<"enter data";
        root=insertIntoBSt(root,data);
        cin>>data;
    }
}
int main(){
    Node* root=NULL;
    // 10 5 4 3 27 21 20 -1
    cout<<"Enter BST data (End with -1)"<<endl;
    takeInput(root);
    cout<<"Printing data";

    levelOrderTraversal(root);

}