// binarysearch
#include <iostream>
using namespace std;
int main() {
    // data must be sorted
    int n;
    cout<<"enter size of array:";
    cin>>n;
    int arr[n];
    int key;
    for(int i=0;i<n;i++){
        int x;
        cout<<"enter value:";
        cin>>x;
        arr[i]=x;
    }
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
    cout<<"enter value to find:";
    cin>>key;
    bool y=false;
    int s=0;
    int e=n-1;
    int mid=(s+e)/2;
    while(s<=e){
    if(arr[mid]==key){
        cout<<"value found at "<<mid<<" index";
        y=true;       
        break;
    }
    else if(key>arr[mid]){
        s=mid+1;
    }
    else{
        e=mid-1;
    }
}
if(y==false){
    cout<<"not found";
}
    return 0;
}
