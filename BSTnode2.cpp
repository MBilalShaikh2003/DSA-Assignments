// Online C++ compiler to run C++ program online
#include <iostream>
#include<stdlib.h>
using namespace std;
struct bstnode{
  int data;
  bstnode* right;
  bstnode* left;
};
bstnode* insert(bstnode* node,int value){
    if(node==NULL){
        node=new bstnode;
        //bstnode* node=(bstnode*)malloc(sizeof(bstnode));
        node->data=value;
        node->right=NULL;
        node->left=NULL;
        return node;
    }
    if(value<node->data){
        node->left=insert(node->left,value);
    }
    else{
         node->right=insert(node->right,value);
    } 
    return node;
}
void search(bstnode* node,int tosearch){
    if(node==NULL){
        cout<<"NOT FOUND"<<endl;
        return;
    }
    
    if(node->data == tosearch){
            cout<<"NOT FOUND"<<endl;
            return;
    }
    else if(node->data>tosearch){
        search(node->left,tosearch);
    }
    else{
        search(node->right,tosearch);
    }
}
void inorder(bstnode* node){
    if(node!=NULL){
        inorder(node->left);
        cout<<node->data;
        inorder(node->right);
    }
}
void preorder(bstnode* node){
    if(node!=NULL){
        cout<<node->data;
        preorder(node->left);
        preorder(node->right);
    }
}
void postorder(bstnode* node){
    if(node!=NULL){
        postorder(node->left);
        postorder(node->right);
        cout<<node->data;
    }
}
bstnode* minimum(bstnode* node){
    bstnode* curr=node;
    while(curr->left != NULL){
        curr=curr->left;
    }
    return curr;
}
bstnode* maximum(bstnode* node){
    bstnode* curr=node;
    while(curr->right != NULL){
        curr=curr->right;
    }
    return curr;
}
bstnode* deletenode(bstnode* node,int todel){
    if(node==NULL){
        cout<<"empty tree"<<endl;
        return node;
    }
    if(node->data>todel){
        node->left=deletenode(node->left,todel);
    }
    else if(node->data<todel){
        node->right=deletenode(node->right,todel);
    }
    else{
        if(node->left==NULL){
            bstnode* temp=node->right;
            free(node);
            return temp;
        }
       else if(node->right==NULL){
            bstnode* temp=node->left;
            free(node);
            return temp;
        }
        bstnode* temp=minimum(node->right);
        node->data=temp->data;
        //free(temp);
        node->right=deletenode(node->right,temp->data);
    }
    return node;
}
int main() {
    bstnode* root=NULL;
        int choice;
    do{
        cout<<"enter 1 to insert 2 to search 3 to inorder 4 to preorder 5 to postorder 6 to minimum 7 to maximum 8 to delete 0 to exit:";
        cin>>choice;
        if(choice==1){
            int value;
            cout<<"enter value to insert:";
            cin>>value;
        root=insert(root,value);
    }
    if(choice==2){
        int tosearch;
        cout<<"enter a value to search";
        cin>>tosearch;
        search(root,tosearch);
    }
    if(choice==3){
        inorder(root);
    }
    if(choice==4){
        preorder(root);
    }
    if(choice==5){
        postorder(root);
    }
    if(choice==6){
        bstnode* temp=minimum(root);
        cout<<"minimum value is:"<<temp->data<<endl;
    }
    if(choice==7){
        bstnode* temp=maximum(root);
        cout<<"maximum value is:"<<temp->data<<endl;
    }
    if(choice==8){
        int todel;
        cout<<"enter value to delete";
        cin>>todel;
        root=deletenode(root,todel);
    }
    }while(choice!=0);
    return 0;
}
    

