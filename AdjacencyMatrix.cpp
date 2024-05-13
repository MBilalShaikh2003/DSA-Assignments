// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void printmatrix(int **matrix, int noofvertex){
    for(int i=0;i<noofvertex;i++){
        for(int j=0;j<noofvertex;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int noofdegree(int** matrix,int noofvertex,int vertex){
    int degree;
    for(int i=0;i<noofvertex;++i){
        if(matrix[vertex][i]==1){
            degree++;
        }
    }
    return degree;
}
int main() {
    int noofvertex;
    cout<<"enter no of vertexs:";
    cin>>noofvertex;
    int** matrix=new int*[noofvertex];
    for(int i=0;i<noofvertex;++i){
        matrix[i]=new int[noofvertex];
        for(int j=0;j<noofvertex;++j){
            matrix[i][j]=0;
        }
    }
    int noofedge;
    cout<<"enter no of edge:";
    cin>>noofedge;
for(int j=0;j<noofvertex;++j){    
    cout<<"enter vertex:";
    int ver1;
    cin>>ver1;
    for(int i=0;i<noofvertex;++i){
        int ver2;
        cout<<"enter vertex2:";
        cin>>ver2;//2,3,4;
        int x;
        cout<<"Enter 1 for relation ship  OR Enter 0 for no relationship between "<<ver1<<" and "<<ver2<<" =";
        cin>>x;
        if(x==1){
        matrix[j][i]=1;
        }
    }
}
    printmatrix(matrix,noofvertex);
    cout<<"no of degree:"<<endl;
    for(int i=0;i<noofvertex;++i){
        cout<<"degree of"<<i<<":"<<noofdegree(matrix,noofvertex,i)<<endl;
    }
        
    return 0;
}
