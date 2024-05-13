// Online C++ compiler to run C++ program online
#include <iostream>
 #include<stdlib.h>
 using namespace std;

 struct stnode{
     int value;
     stnode*next;
 };
 stnode* top=NULL;
string reverse(string infix){
    string a="";
    for(int i=infix.length()-1;i>=0;i--){
        a+=infix[i];
    }
    return a;
}
void push(int value){
	stnode *temp=(stnode*)malloc(sizeof(stnode));
	temp->value=value;
	temp->next=top;
	top=temp;
}
void pop(){
	while(top==NULL){
		return;
	}
	stnode* temp=top;
	top=top->next;
	free(temp);
	return;
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
string infixtoprefix(string y){
	string prefix="";
	for(int i=0;i<y.length();i++){
		char ch=y[i];
		if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9' )){
			prefix+=ch;
		}
		else if(ch=='('){
			push(ch);
		}
		else if(ch ==')'){
			while(top!=NULL && top->value!='('){
				prefix+=top->value;
				pop();
			}
			if(top!=NULL){
				pop();//pop(
			}
		}
		else{
			while(top!=NULL && precedence(ch)<=precedence(top->value)){
				prefix+=top->value;
				pop();
			}
			push(ch);
		}

	}
	while(top!=NULL){
			prefix+=top->value;
			pop();
		}
	return prefix;
}
string reversebracket(string x){
    string b="";
    for(int i=0;i<x.length();i++){
        if(x[i]=='('){
            b+=')';
        }
        else if(x[i]==')'){
            b+='(';
        }
        else{
            b+=x[i];
        }
    }
    return b;
}

int main() {
    string infix="a+(b*c/x)";
    cout<<"infix expression:"<<infix<<endl;
    string x=reverse(infix);
  //  cout<<"infix expression reverse:"<<x<<endl;
    string y=reversebracket(x);
  //  cout<<"infix expression reverse bracket:"<<y<<endl;
    string z=infixtoprefix(y);
 //   cout<<"prefix expression:"<<z<<endl;
    string prefix=reverse(z);
    cout<<"prefix expression:"<<prefix<<endl;

    return 0;
}
