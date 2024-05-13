// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


void printmatrix(int **matrix,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int noofvertex;
    cout<<"enter no of vertex:";
    cin>>noofvertex;
    int** matrix=new int*[noofvertex];
    for(int i=0;i<noofvertex;++i){
        matrix[i]=new int[noofvertex];
        for(int j=0;j<noofvertex;j++){
            matrix[i][j]=0;
        }
    }
    int noofedge;
    cout<<"enter no of edge:";
    cin>>noofedge;
    
    for(int i=0;i<noofvertex;++i){
        cout<<"enter vertex:";
        int ver1;
        cin>>ver1;
        for(int j=0;j<noofvertex;++j){
            int ver2;
            cout<<"enter vertex2:";
            cin>>ver2;
            
            int x;
            cout<<"enter 1 for relationship 0 for no relationship:";
            cin>>x;
            
            if(x==1){
                matrix[i][j]=1;
            }
            
            
        }
        
    }
    printmatrix(matrix,noofvertex);
    
    
    // Calculate in-degree and out-degree
    int  indegree[noofvertex] = {0};
    int outdegree[noofvertex] = {0};

    for (int i = 0; i < noofvertex; ++i) {
        for (int j = 0; j < noofvertex; ++j) {
            if (matrix[i][j] == 1) {
                // Increment out-degree for the current vertex
                outdegree[i]++;
                // Increment in-degree for the destination vertex
                indegree[j]++;
            }
        }
    }
    

    // Print in-degree and out-degree of each vertex
    cout << "Vertex\tIn-degree\tOut-degree" << endl;
    for (int i = 0; i < noofvertex; ++i) {
        cout << i+1<<"vertex" << "\t" << indegree[i] << "\t\t" << outdegree[i] << endl;
    }
    
    
    return 0;
}
