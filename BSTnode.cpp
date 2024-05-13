#include<iostream>
#include<stdlib.h>
using namespace std;
struct bstnode{
	int data;
	bstnode* left;
	bstnode* right;
};
bstnode* insert(bstnode* node, int value) {
    if (node == NULL) {
        bstnode* node = (bstnode*)malloc(sizeof(bstnode));
        node->data = value;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    if (node->data > value) {
        node->left = insert(node->left, value);
    }
    else {
        node->right = insert(node->right, value);
    }
    return node;
}

// bstnode* insert(bstnode* node,int value){
// 	if(node==NULL){
// 		bstnode* newnode=(bstnode*)malloc(sizeof(bstnode));
// 		node->data=value;
// 		node->left=NULL;
// 		node->right=NULL;
// 		return newnode;
// 	}
// 	if(node->data>value){
// 		node->left=insert(node->left,value);
// 	}
// 	else{
// 		node->right=insert(node->right,value);
// 	}
// 	return node;
	
// }
void search(bstnode* node,int tosearch){
	if(node==NULL){
		cout<<"not found"<<endl;
		return;
	}
	if(node->data==tosearch){
		cout<<"found"<<endl;
		return;
		
	}
	if(node->data>tosearch){
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
	while(curr->left!=NULL){
		curr=curr->left;
	}
	return curr;
}
bstnode* maximum(bstnode* node){
	bstnode* curr=node;
	while(curr->right!=NULL){
		curr=curr->right;
	}
	return curr;
}
bstnode* deletenode(bstnode* node,int todel){
	if(node==NULL){
		cout<<"not exist";
		return node;
	}
	if(todel<node->data){
		node->left=deletenode(node->left,todel);
	}
	else if(todel>node->data){
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
		deletenode(temp,todel);
	}
	return node;
}
int main(){
	bstnode* root=NULL;
	       int choice;
    do {
        cout << "Enter 1 for insert, 2 for search,3 to inorder 4 to preorder 5 for postorder 6 to min 7 for max 0 to exit: ";
        cin >> choice;
        switch (choice) {
            case 1:
                int value;
                cout<<"enter value to insert:";
                cin>>value;
                root=insert(root,value);
                break;
            case 2:
                int tosearch;
                cout<<"enter a no to search:";
                cin>>tosearch;
                search(root,tosearch);
                break;
            case 3:
            	inorder(root);
            	break;
            case 4:
				preorder(root);
				break;
			case 5:
				postorder(root);
				break;
			case 6:
				bstnode* temp=minimum(root);
				cout<<"minimum value:"<<temp->data<<endl;
				break;
			case 7:
				bstnode* tempmax=maximum(root);
				cout<<"maximum value:"<<tempmax->data<<endl;
				break;									
			case 8:
				int todel;
				cout<<"enter a no to delete:";
				cin>>todel;
				root=deletenode(root,todel);
            default:
                cout << "Invalid choice" << endl;
                break;
        }
        }while(choice!=0);
        return 0;
}
