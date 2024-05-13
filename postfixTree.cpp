#include <iostream>
#include <string>
 #include<stdlib.h>
 using namespace std;
 struct stnode{
    int value;
    stnode*next;
};
stnode*top1=NULL;
struct node*postfix=NULL;
void push1(int value){
    stnode *temp=(stnode*)malloc(sizeof(stnode));
    temp->value=value;
    temp->next=top1;
    top1=temp;
}
void pop1(){
    if(top1==NULL){
        return ;
    }
    //int poppedvalue=top->value;
    stnode* temp=top1;
    top1=top1->next;
    free(temp);
    return ;
}
int precedence(char op){
    if(op=='*' || op=='/' || op=='%')
    return 6;
    if(op=='+' || op=='-')
    return 5;
     if(op=='<' || op=='>' || op=='<=' || op=='>=')
     return 4;
     if(op=='==' || op=='!=')
     return 3;
     if(op=='&&')
     return 2;
     if(op=='||')
     return 1;
    
    return 0;
}
string infixtopostfix(string infix) {
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;
        } else if (ch == '(') {
            push1(ch);
        } else if (ch == ')') {
            while (top1 != NULL && top1->value != '(') {
                postfix += top1->value;
                pop1();
            }
            if (top1!= NULL) {
                pop1(); // Pop the '('
            }
        } else {
            while (top1 != NULL && precedence(ch) <= precedence(top1->value)) {
                postfix += top1->value;
                pop1();
            }
            push1(ch);
        }
    }
    while (top1 != NULL) {
        postfix += top1->value;
        pop1();
    }
    return postfix;
}
struct TreeNode{
	char data;
	TreeNode* left;
	TreeNode* right;
};
struct StackNode{
	TreeNode* data;
	StackNode* next;
};
StackNode* top=NULL;
void push(TreeNode* treenode){
	StackNode* newnode=new StackNode;
	newnode->data=treenode;
	newnode->next=top;
	top=newnode;
}
TreeNode* pop(){
	if(top==NULL){
		cout<<"stack overflow";
		return NULL;
	}
	TreeNode* treenode=top->data;
	StackNode* temp=top;
	top=top->next;
	delete temp;
	return treenode;
	
}

bool isEmpty(){
	return top==NULL;
}
bool isOperator(char c){
	return(c=='+' || c=='-'  || c=='*' || c=='/' || c=='^');
}
TreeNode*  constructexpressiontree(string postfix){
	for(int i=0; i<postfix.length(); i++){
		char ch=postfix[i];
		if(isOperator(ch)){
			TreeNode* right=pop();
			TreeNode* left=pop();
			TreeNode* newnode=new TreeNode;
			newnode->data=ch;
			newnode->left=left;
			newnode->right=right;
			push(newnode);
		}
		else{
			TreeNode* newnode=new TreeNode;
			newnode->data=ch;
			newnode->left=NULL;
			newnode->right=NULL;
			push(newnode);
		
		}	
	}
	return pop();
}
void preordertraversal(TreeNode* root){
	if(root){
		
		preordertraversal(root->left);
		cout<<root->data<<" ";
		preordertraversal(root->left);
	}
}

int main(){
	string infix;
	cout<<"enter any expression";
	getline(cin,infix);
	cout<<"infixexpression:"<<infix<<endl;
	string postfix=infixtopostfix(infix);
	string postfix="abc*x/+";
	cout<<"postfixexpression:"<<postfix<<endl;
	TreeNode* root=constructexpressiontree(postfix);
	cout<<"traversal of the expression tree is:\n";
	preordertraversal(root);
	cout<<endl;
	
	
	
	return 0;
	
}
