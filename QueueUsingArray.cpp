// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int n=5;
int *arr=new int[n];
int front=-1;
int back=-1;
void enqueue(int x){
    if(back==n-1){
        cout<<"queue overflow"<<endl;
        return;
    }
    back++;
    arr[back]=x;
    if(front==-1){
        front++;
    }
}
void dequeue(){
    if(front==-1 || front>back){
        cout<<"empty"<<endl;
        return;
    }
    front++;
}
int peek(){
       if(front==-1 || front>back){
        cout<<"empty"<<endl;
        return -1;
       }
    return arr[front];   
}
int main() {
   
        int choice;
    cout<<"enter 1 to enqueue,2 to dequeue and 3 to find peek(top) and 0 to exit"<<endl;
    cin>>choice;
    do{
        if(choice==1){
            int a;
            cout<<"enter a no to push"<<endl;
            cin>>a;
            enqueue(a);
           cout<<"enter 1 to enqueue,2 to dequeue and 3 to find peek(top) and 0 to exit"<<endl;
             cin>>choice;
        }
        if(choice==2){
            dequeue();
            cout<<"enter 1 to enqueue,2 to dequeue and 3 to find peek(top) and 0 to exit"<<endl;
            cin>>choice;
        }
        if(choice==3){
            int topvalue=peek();
            if(topvalue!=-1){
                cout<<"top element:"<<topvalue<<endl;
            }
         cout<<"enter 1 to enqueue,2 to dequeue and 3 to find peek(top) and 0 to exit"<<endl;
            cin>>choice;
        }
    }while(choice!=0);
    return 0;
}
