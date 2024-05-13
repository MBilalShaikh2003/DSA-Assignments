// linear search
#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"enter size of array:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        int x;
        cout<<"enter value:";
        cin>>x;
        arr[i]=x;
    }
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
    int key;
    cout<<"enter value to search:";
    cin>>key;
    bool y=false;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            cout<<"value found at "<<i<<" index";
            y=true;
            break;
        }
    }
    if(y==false){
        cout<<"value not found";
    }
    
    return 0;
}
