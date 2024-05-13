#include <iostream>
using namespace std;

int n=5;
int *arr=new int[n];
int top=-1;
void push(int x){
    if(top==n-1){
        cout<<"stack overflow"<<endl;
        return;
    }
    top++;
    arr[top]=x;
}
void pop(){
    if(top==-1){
        cout<<"empty"<<endl;
        return;
    }
    top--;
}
int Top(){
    if(top==-1){
        cout<<"empty"<<endl;
        return -1;
    }
    return arr[top];
}
int main() {
    int choice;
    cout<<"enter 1 to push,2 to pop and 3 to find top and 0 to exit"<<endl;
    cin>>choice;
    do{
        if(choice==1){
            int a;
            cout<<"enter a no to push"<<endl;
            cin>>a;
            push(a);
             cout<<"enter 1 to push,2 to pop and 3 to find top and 0 to exit"<<endl;
             cin>>choice;
        }
        if(choice==2){
            pop();
            cout<<"enter 1 to push,2 to pop and 3 to find top and 0 to exit"<<endl;
            cin>>choice;
        }
        if(choice==3){
            int topvalue=Top();
            if(topvalue!=-1){
                cout<<"top element:"<<topvalue<<endl;
            }
            cout<<"enter 1 to push,2 to pop and 3 to find top and 0 to exit"<<endl;
            cin>>choice;
        }
    }while(choice!=0);
    
    
    
    
    
    return 0;
}
