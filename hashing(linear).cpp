// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void insert(int key,int size,int arr[]){
    int index=key%size;
    while(arr[index]!=-1){
        index++;
        index=index%size;
        if(arr[index]==-1){
            arr[index]=key;
            break;
        }
        else{
            index++;
        }
    }
    arr[index]=key;
}
void search(int tosearch,int size,int arr[]){
    bool x=false;
    for(int i=0;i<size;i++){
    if(arr[i]==tosearch){
        cout<<"found"<<endl;
        x=true;
        break;
    }
}
    if(x==false){
        cout<<"not found"<<endl;
    }
}




int main() {
    int size;
    cout<<"array size";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        arr[i]=-1;
    }
       int choice;
       int count=0;
    do {
        cout << "Enter 1 for insert, 2 for search, 0 to exit: ";
        cin >> choice;
        switch (choice) {
            case 1:
                count++;
                if(count<=size){
                int key;
                cout<<"enter value to insert:";
                cin>>key;
                insert(key,size,arr);
                }
                else{
                    cout<<"array is full"<<endl;
                }
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
