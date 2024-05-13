#include <iostream>
 #include<stdlib.h>
 using namespace std;

struct stnode{
    int value;
    stnode*next;
};
stnode*top=NULL;

void push(int value){
    stnode *temp=(stnode*)malloc(sizeof(stnode));
    temp->value=value;
    temp->next=top;
    top=temp;
}
void pop(){
    if(top==NULL){
        return ;
    }
    
    stnode* temp=top;
    top=top->next;
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
            push(ch);
        } else if (ch == ')') {
            while (top != NULL && top->value != '(') {
                postfix += top->value;
                pop();
            }
            if (top != NULL) {
                pop(); // Pop the '('
            }
        } else {
            while (top != NULL && precedence(ch) <= precedence(top->value)) {
                postfix += top->value;
                pop();
            }
            push(ch);
        }
    }
    while (top != NULL) {
        postfix += top->value;
        pop();
    }
    return postfix;
}

int main() {
    //string infix="a+(b*c/(x+e)*(y-x*d)";
    string infix="a+(b*c/x)";
    cout<<"infix expression:"<<infix<<endl;
    cout<<"postfix expression:"<<infixtopostfix(infix)<<endl;

    
    return 0;
}



//
//// Online C++ compiler to run C++ program online
//#include <iostream>
// #include<stdlib.h>
// using namespace std;
//struct stnode{
//    int value;
//    stnode*next;
//};
//stnode*top=NULL;
//void push(int value){
//    stnode* temp=(stnode*)malloc(sizeof(stnode));
//    temp->value=value;
//    temp->next=top;
//    top=temp;
//}
//int pop(){
//    if(top!=NULL){
//        return -1;
//    }
//    int popedvalue=top->value;
//    stnode* temp=top;
//    top=top->next;
//    free(temp);
//    return popedvalue;
//    
//}
//int precedence(char ch){
//    if(ch=='*' || ch=='/'){
//        return 6;
//    }
//    if(ch=='+' || ch=='-'){
//    return 5;
//    }
//    return 0;
//}
//string infixtopostfix(string infix){
//    string postfix="";
//    for(int i=0;i<infix.length();i++){
//        char ch=infix[i];
//        if(ch>='a' && ch<='z' || ch>='A' && ch<='Z'){
//            postfix+=ch;
//        }
//        else{
//            if(top!=NULL && precedence(ch)<=precedence(top->value)){
//                postfix+=top->value;    
//                pop();
//            }
//            push(ch);
//        }
//    }
//    while(top!=NULL){
//        postfix+=top->value;
//        pop();
//    }
//    return postfix;
//}
//int main() {
//    string infix="a+b*c/d";
//    cout<<"infix expression:"<<infix<<endl;
//      cout<<"postfix expression:"<<infixtopostfix(infix)<<endl;
//    return 0;
//}
