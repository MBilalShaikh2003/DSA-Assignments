// Online C++ compiler to run C++ program online
#include <iostream>
#include<stdlib.h>
using namespace std;
struct record{
    int rno;
    string name;
    record* next;
    record* prev;
};
int count=0;
void insert(record** head){
    record* ptr=new record;
    cout<<"enter rno:";
    cin>>ptr->rno;
    cout<<"enter name:";
    cin>>ptr->name;
    ptr->next=NULL;
    ptr->prev=NULL;
    count++;
    if(*head==NULL){
        *head=ptr;
    }
    else{
        record* curr=*head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=ptr;
        ptr->prev=curr;
    }
}
void display(record** head){
    record* curr=*head;
    if(curr==NULL){
        cout<<"list empty"<<endl;
        return;
    }
    while(curr!=NULL){
        cout<<"ROLLN0:"<<curr->rno<<endl;
        cout<<"NAME:"<<curr->name<<endl;
        curr=curr->next;
    }
}
void letdelete(record** head){
    int x;
    cout<<"enter a no to delete: ";
    cin>>x;
    record* curr=*head;
    record* prev=NULL;
    if(curr==NULL){
        cout<<"list empty"<<endl;
        return;
    }
    if((*head)->rno==x){
        *head=curr->next;
        if((*head) != NULL){
            (*head)->prev=NULL;
        }
        delete curr;
        cout<<"DELETED"<<endl;
        count--;
        return;
    }
    while(curr!=NULL && curr->rno!=x){
        prev=curr;
        curr=curr->next;
    }
    if(curr==NULL){
        cout<<"NOT FOUND"<<endl;
        return;
    }
    prev->next=curr->next;
    if(curr->next==NULL){
        curr->next->prev=prev;
    }
    delete curr;
    cout<<"DELETED"<<endl;
    count--;
}
void search(record** head){
    int a;
    cout<<"enter a no to search: ";
    cin>>a;
    record* curr=*head;
    if(curr==NULL){
        cout<<"LIST EMPTY"<<endl;
        return;
    }
    while(curr!=NULL){
        if(curr->rno==a){
            cout<<"FOUND"<<endl;
            return;
        }
        curr=curr->next;
    }
    cout<<"NOT FOUND"<<endl;
}
void deleteall(record** head){
    record* curr=*head;
    if(curr==NULL){
        cout<<"LIST EMPTY"<<endl;
        return;
    }
    while(curr!=NULL){
        record* temp=curr->next;
        delete curr;
        curr=temp;
    }
    *head=NULL;
    count=0;
}
void totallist(){
    cout<<"NO OF LIST: "<<count<<endl;
}
void reverselist(record** head){
    record* curr=*head;
    record* prev=NULL;
    record* next;
    if(curr==NULL){
        cout<<"LIST EMPTY"<<endl;
        return;
    }
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        curr->prev=next;
        prev=curr;
        curr=next;
    }
    *head=prev;
    cout<<"LIST REVERSED "<<endl;
    
}
int main() {
   record* head=NULL;
   int choice;
       do {
        cout << "Enter 1 for insert, 2 for display,3 for delete,4 to search,5 to deleteall,6 to find no of list,7 to reverse a list 0 to exit: ";
        cin >> choice;
        switch (choice) {
            case 1:
                insert(&head);
                break;
            case 2:
                display(&head);
                break;
            case 3:
                letdelete(&head);
                break;
            case 4:
                search(&head);
                break;
            case 5:
                deleteall(&head);
                break;
            case 6:
                totallist();
                break;
            case 7:
                reverselist(&head);
                break;
    
            default:
                cout << "Invalid choice" << endl;
        }
        }while(choice!=0);
    return 0;
}
     
