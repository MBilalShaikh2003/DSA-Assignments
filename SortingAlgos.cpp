// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int j=i-1;
        while(arr[j]>curr && j>=0){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=curr;
        
    }
    
    
    
    
}


int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> arr[i];
    }
    cout<<"before sorting: "<<endl;
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
    int choice;
    cout<<"Enter 1 for SelectionSort, 2 for BubbleSort,3 for InsertionSort: ";
    cin>>choice;
    if(choice==1){
        selectionSort(arr,n);
    }
    else if(choice==2){
        bubbleSort(arr,n);
    }
    else if(choice==3){
        insertionSort(arr,n);        
    }    
    cout<<endl;
    cout<<"after sorting:"<<endl;
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }    

    return 0;
}
