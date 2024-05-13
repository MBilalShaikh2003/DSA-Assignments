// Online C++ compiler to run C++ program online
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Hash{
  int value;
  Hash* next;
};
void insert(int key,int size,Hash* arr[]){
    int index=key%size;
    Hash* ptr=(Hash*)malloc(sizeof(Hash));
    ptr->value=key;
    ptr->next=nullptr;
    if(arr[index]!=nullptr){
        if(arr[index]->next==nullptr){
            arr[index]->next=ptr;
        }
        else{
            Hash* curr=arr[index];
            while(curr->next!=nullptr){
                curr=curr->next;
            }
            curr->next=ptr;
        }
    }
    arr[index]=ptr;
}
void search(int tosearch, int size, Hash* arr[]) {
    int index = tosearch % size;
    Hash* curr = arr[index];
    while (curr != nullptr) {
        if (curr->value == tosearch) {
            cout << "Found" << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "Not found" << endl;
}
// void search(int tosearch,int size,Hash* arr[]){
//     int index=tosearch%size;
//     Hash* curr=arr[index];
//     while(curr!=nullptr){
//         if(curr->value==tosearch){
//             cout<<"found"<<endl;
//             return;
//         }
//         curr=curr->next;
//     }
//     cout<<"not found"<<endl;
    
// }

int main() {
  int size;
  cout<<"enter size of array:";
  cin>>size;
  Hash* arr[size];
  for(int i=0;i<size;i++){
      arr[i]=nullptr;
  }
       int choice;
    do {
        cout << "Enter 1 for insert, 2 for search, 0 to exit: ";
        cin >> choice;
        switch (choice) {
            case 1:
                int key;
                cout<<"enter value to insert:";
                cin>>key;
                insert(key,size,arr);
                break;
            case 2:
                int tosearch;
                cout<<"enter a no to search:";
                cin>>tosearch;
                search(tosearch,size,arr);
                break;
            default:
                cout << "Invalid choice" << endl;
        }
        }while(choice!=0);

    return 0;
}
