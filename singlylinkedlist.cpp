#include <iostream>
#include <stdlib.h>
using namespace std;
struct record{
    int rno;
    record *next;
};
void insert(record**head){
    record *ptr;
    ptr=(record*)malloc(sizeof(record));
    cout<<"enter roll no"<<endl;
    cin>>ptr->rno;
    if(*head==nullptr){
        *head=ptr;
    }
    else{
        record *curr=*head;
        while(curr->next !=nullptr){
            curr=curr->next;
        }
        curr->next=ptr;
    }
}
void display(record **head){
    record *curr=*head;
    if(curr==nullptr){
        cout<<"list is empty"<<endl;
        return;
     }
    while(curr!=nullptr){
        cout<<curr->rno<<endl;
        curr=curr->next;
    }
}
void search(record **head){
        int tosearch;
        cout<<"enter no to search"<<endl;
        cin>>tosearch;
        record *curr=*head;
         if(curr==nullptr){
         cout<<"list is empty"<<endl;
         return;
     }

     while(curr!=nullptr){
         if(curr->rno==tosearch){
             cout<<"found"<<endl;
             break;
         }
             curr=curr->next;
     }
}
void letdelete(record**head){
    int todelete;
    cout<<"enter rno to delete"<<endl;
    cin>>todelete;
    record *curr=*head;
    record *prev=nullptr;
    //empty list
    if(curr==nullptr){
        cout<<"list is empty"<<endl;
        return;
     }
     //if 1 2 3 and to delete 1
     if(curr->rno==todelete){
        *head = curr->next;
        free(curr);
        cout << "Deleted" << endl;
        return;
     }
     //if only 1 and to delete 1
    if(todelete==curr->rno){
        if((*head)->next==nullptr){
            free(*head);
            *head=nullptr;
        }
}
// todelete last
    while(curr != nullptr && curr->rno != todelete){
        prev = curr;
        curr = curr->next;
    }
    //out of loop bcz of first condition and if not present
    if (curr == nullptr) {
        cout << "Not found" << endl;
        return;
    }
    //out of loop bcz of second condition
    prev->next = curr->next;
    free(curr);
    cout << "Deleted" << endl;

}
void deleteall(record **head){
    
    record *curr=*head;
    record *temp=nullptr;
    if(curr==nullptr){
        cout<<"list is empty";
        return;
    }
    while(curr!=nullptr) {
        temp=curr->next;
        free(curr);
        curr=temp;
    } 
    *head=NULL;
}



int main(){
    record* head = nullptr;
    int choice;
    do {
        cout << "Enter 1 for insert, 2 for display,3 for search,4 to delete,5 to deleteall 0 to exit: ";
        cin >> choice;
        switch (choice) {
            case 1:
                insert(&head);
                break;
            case 2:
                display(&head);
                break;
            case 3:
                search(&head);
                break;
            case 4:
                letdelete(&head);
                break;
            case 5:
                deleteall(&head);
                break;
            default:
                cout << "Invalid choice" << endl;
        }
        }while(choice!=0);
  
  

    return 0;

}
