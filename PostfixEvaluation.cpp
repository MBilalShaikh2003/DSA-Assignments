#include <iostream>
#include <string>
#include<stdlib.h>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
};

struct StackNode {
    TreeNode* data;
    StackNode* next;
};
                                                                                                                                                                                                                                
StackNode* top = NULL;

void push(TreeNode* treeNode) {
    StackNode* newnode = new StackNode;
    newnode->data = treeNode;
    newnode->next = top;
    top = newnode;
}

TreeNode* pop() {
    if (top == NULL) {
        cout << "Stack underflow";
        return NULL;
    }
    TreeNode* treeNode = top->data;
    StackNode* temp = top;
    top = top->next;
    delete temp;
    return treeNode;
}

bool isEmpty() {
    return top == NULL;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

TreeNode* constructExpressionTree(string postfix) {
    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        if (isOperator(ch)) {
            TreeNode* right = pop();
            TreeNode* left = pop();
            TreeNode* newNode = new TreeNode;
            newNode->data = ch;
            newNode->left = left;
            newNode->right = right;
            push(newNode);
        } else {
            TreeNode* newNode = new TreeNode;
            newNode->data = ch;
            newNode->left = NULL;
            newNode->right = NULL;
            push(newNode);
        }
    }
    return pop();
}

void preorderTraversal(TreeNode* root) {
    if (root) {
        
        preorderTraversal(root->left);
        cout << root->data << " ";
        preorderTraversal(root->right);
    }
}
int evaluate(TreeNode* root) {
    if (root) {
        if (root->data == '+')
            return evaluate(root->left) + evaluate(root->right);
        else if (root->data == '-')
            return evaluate(root->left) - evaluate(root->right);
        else if (root->data == '*')
            return evaluate(root->left) * evaluate(root->right);
        else if (root->data == '/')
            return evaluate(root->left) / evaluate(root->right);
        else
            return atoi(&root->data); // Convert character to integer
    }
    return 0;
}
struct stnode{
    int value;
    stnode*next;
};
stnode*top1=NULL;

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
            if (top1 != NULL) {
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


int main() {
	string infix="9+(3*2/3)";
	//string infix="a+(b*c/x)";
    cout<<"infix expression:"<<infix<<endl;
    string postfix = infixtopostfix(infix);
    cout << "postfix expression: " << postfix << endl;
    TreeNode* root = constructExpressionTree(postfix);
    cout << "inorder traversal of the expression tree is: ";
    preorderTraversal(root);
    cout << endl;
    cout << "Result of postfix expression evaluation: " << evaluate(root) << endl;

    return 0;
}
