#include <iostream>
#include <stdlib.h>
using namespace std;
struct queue{
    int value;
    queue* next;
};
queue* front=nullptr;
queue* back=nullptr;
void enqueue(){
    queue* ptr=(queue*)malloc(sizeof(queue));
    int a;
    cout<<"enter a value";
    cin>>a;
    ptr->value=a;
    ptr->next=nullptr;
    if(front==nullptr){
        front=ptr;
        back=ptr;
    }
    else{
        back->next=ptr;
        back=back->next;
    }
}
void dequeue(){
    if(front==nullptr && back==nullptr){
        cout<<"empty";
        return;
    }
    else{
        queue* curr=front;
        if(front->next!=nullptr){
        front=front->next;
        cout<<"topelement:"<<front->value<<endl;
        free(curr);
        }
        else{
            cout<<"topelement:"<<front->value<<endl;
        }
    }
}
int main() {
    int choice;
    do {
        cout << "Enter 1 for push, 2 for pop, 0 to exit: ";
        cin >> choice;
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            default:
                cout << "Invalid choice" << endl;
        }
        }while(choice!=0);
    return 0;
}
