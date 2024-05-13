
#include <iostream>
#include<stdlib.h>
using namespace std;
struct record{
    int rno;
    string name;
    record *next;
};
int count=0;
void insert(record** head){
    record* ptr=new record;
    cout<<"enter rno: ";
    cin>>ptr->rno;
    cout<<"enter name: ";
    cin>>ptr->name;
    ptr->next=NULL;
    count++;
    if((*head)==NULL){
        (*head)=ptr;
        ptr->next=*head;
    }
    else{
        record* curr=*head;
        while(curr->next!=*head){
            curr=curr->next;
        }
        curr->next=ptr;
        ptr->next=*head;
    }
}
void display(record** head){
    record* curr=*head;
   if(curr==NULL){
        cout<<"list empty"<<endl;
        return;
    }
    do{
        cout<<"ROLLN0:"<<curr->rno<<endl;
        cout<<"NAME:"<<curr->name<<endl;
        curr=curr->next;
    }while(curr != (*head));
}
void letdelete(record** head){
    int x;
    cout<<"enter a no to delete: ";
    cin>>x;
    record* curr=*head;
    if(curr==NULL){
        cout<<"list empty"<<endl;
        return;
    }
    if((*head)->rno==x){
        if((*head)->next== (*head)){
            delete *head;
            *head=NULL;
            cout<<"DELETED"<<endl;
            count--;
            return;
        }
        else{
           record* lastnode=*head;
           while(lastnode->next != (*head)){
               lastnode=lastnode->next;
           }
           *head=(*head)->next;
            lastnode->next=*head;
            delete curr;
            cout<<"DELETED"<<endl;
            count--;
            return;
        }
    }
    else{
        record* prev=*head;
        curr=(*head)->next;
        while (curr != *head) {
            if (curr->rno == x) {
                prev->next = curr->next;
                delete curr;
                cout << "DELETED" << endl;
                count--;
                return; // Exit the function after deletion
            }
            prev = curr;
            curr = curr->next;
        }
    }
    cout<<"NOT FOUND"<<endl;
}
void deleteall(record** head){
    record* curr=*head;
    record* temp=NULL;
    if(curr==NULL){
        cout<<"LIST EMPTY"<<endl;
        return;
    }
    ;
    while(curr != *head){
        record* temp=curr->next;
        delete curr;
        curr=temp;
    }
    *head=NULL;
    count=0;
}
// void reverseList(record** head) {
//     if (*head == NULL) // If the list is empty, there's nothing to reverse
//         return;

//     record* current = *head;
//     record* prevNode = NULL;
//     record* nextNode = NULL;

//     // Traverse the list to find the last node
//     record* lastNode = *head;
//     while (lastNode->next != *head) {
//         lastNode = lastNode->next;
//     }

//     // Set the last node as the new head
//     *head = lastNode;

//     // Traverse the list and reverse the pointers
//     current = *head;
//     do {
//         nextNode = current->next;
//         current->next = prevNode;
//         prevNode = current;
//         current = nextNode;
//     } while (current != *head);

//     // Update the next pointer of the last node to point to the new head
//     lastNode->next = *head;
// }
void totallist(){
    cout<<"TOTAL LIST: "<<count<<endl;
}

int main() {
    record* head = NULL;
    int choice;
    do {
        cout << "Enter 1 for insert, 2 for display,3 for delete,4 to deleteall,6 to find no of list, 0 to exit: ";
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
            //   case 5:
            //  reverseList(&head);
            //    break;    
            case 6:
               totallist();
                break;    
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 0);

    return 0;
}
