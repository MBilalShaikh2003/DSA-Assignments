#include<iostream>
using namespace std;


void delheapify(int arr[],int n){
		for(int i=0;i<n;i++){
		int p=(i-1)/2;
		if(arr[i]<arr[p]){
			int swap=arr[i];
			arr[i]=arr[p];
			arr[p]=swap;
		}
		p=(i-1)/2;
		if(arr[0]>arr[p]){
			int swap=arr[0];
			arr[0]=arr[p];
			arr[p]=swap;
		}
		
	}
}


void del(int arr[],int n){
		int swap=arr[0];
		arr[0]=arr[n-1];
		arr[n-1]=swap;
		delheapify(arr,n-1);	
	
}



void descendingheapsort(int arr[],int n){
	
	for(int i=0;i<n;i++){
		del(arr,n-i);
	}
	cout<<endl;
	cout<<"heapsorted in descending order:"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}


void heapify(int arr[],int n){
	
	for(int i=0;i<n;i++){
		int p=(i-1)/2;
		if(arr[i]<arr[p]){
			int swap=arr[i];
			arr[i]=arr[p];
			arr[p]=swap;
		}
		p=(i-1)/2;
		if(arr[0]>arr[p]){
			int swap=arr[0];
			arr[0]=arr[p];
			arr[p]=swap;
		}
		
	}
	cout<<endl;
	cout<<"min heap:"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}


void insert(int arr[],int n){
	int value;
	for(int i=0;i<n;i++){
		cout<<"enter value:";
		cin>>value;
		arr[i]=value;
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

}



int main(){
	int n;
	cout<<"enter size of array:";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		arr[i]=-1;
	}
	insert(arr,n);
	heapify(arr,n);	
	descendingheapsort(arr,n);
	
}
