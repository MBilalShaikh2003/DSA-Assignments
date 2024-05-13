#include <iostream>
#include <stdlib.h>
using namespace std;

struct record {
    int rno;
    string name;
    record* next;
};
int count=0;

void insert(record** head) {
    record* ptr = (record*)malloc(sizeof(record));
    int a;
    string b;
    cout << "Enter roll number: ";
    cin >> a;
    cout << "Enter name: ";
    cin >> b;
    ptr->rno = a;
    ptr->name = b;
    count++;
    if ((*head) == NULL || (*head)->rno > ptr->rno) {
        ptr->next = *head;
        *head = ptr;
    } else {
        record* curr = *head;
        while (curr->next != NULL && curr->next->rno < ptr->rno) {
            curr = curr->next;
        }
        ptr->next = curr->next;
        curr->next = ptr;
    }
}

void display(record** head) {
    record* curr = *head;
    if (curr == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    while (curr != NULL) {
        cout << "Roll number: " << curr->rno << endl;
        cout << "Name: " << curr->name << endl;
        curr = curr->next;
    }
}
void letdelete(record** head){
    if(*head == NULL){
        cout<<"list empty"<<endl;
        return ;
    }
    cout<<"enter rno to delete:";
    int x;
    cin>>x;
    record* curr=*head;
    record* prev=NULL;
    
    if(curr->rno==x){
        *head=curr->next;
        delete curr;
        cout<<"deleted"<<endl;
        count--;
        return;
    }
    // if(curr->rno == x && (*head)->next == NULL){
    //     free(*head);
    //     *head==NULL;
    // }

    
    while(curr!=NULL && curr->rno != x){
        prev=curr;
        curr=curr->next;
    }
    if(curr == NULL){
        cout<<"NOT FOUND "<<endl;
        return;
    }
    prev->next=curr->next;
    cout<<"DELETED"<<endl;
    delete curr;
    count--;
    
}
void deleteall(record**head){
    record* curr=*head;
    count=0;
    if(curr == NULL){
        cout<<"empty list"<<endl;
        return ;
    }
    record* temp=NULL;
    while(curr!=NULL){
        temp=curr->next;
        delete curr;
        curr=temp;
    }
    *head=NULL;
    
}
void search(record **head){
        int tosearch;
        cout<<"enter no to search"<<endl;
        cin>>tosearch;
        record *curr=*head;
         if(curr==NULL){
         cout<<"list is empty"<<endl;
         return;
     }

     while(curr!=NULL){
         if(curr->rno==tosearch){
             cout<<"found"<<endl;
             break;
         }
             curr=curr->next;
     }
     cout<<"NOT FOUND"<<endl;
}
void listofelements(){
    cout<<"NO LIST ARE :"<<count<<endl;
}
void reverselist(record **head){
    record *prev=NULL;
    record *curr=*head;
    record *next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head=prev;
    
}
int main() {
    record* head = NULL;
    int choice;
    do {
        cout << "Enter 1 for insert, 2 for display,3 to delete,4 to deleteall,5 to search,6 to find no of list,7 to reverselist 0 to exit: ";
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
                 deleteall(&head);
                 break;
             case 5:
                 search(&head);
                 break;
          case 6:
                 listofelements();
                 break;
          case 7:
                 reverselist(&head);
                 break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 0);

    return 0;
}


