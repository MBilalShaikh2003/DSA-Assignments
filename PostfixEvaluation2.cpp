// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct stnode{
  int value;
  stnode* next;
};
stnode* top=NULL;
void push(int value){
    stnode* st=new stnode;
    st->value=value;
    st->next=top;
    top=st;
}
int pop(){
    if(top==NULL){
        cout<<"stack ovrflow"<<endl;
        return -1;
    }
    stnode* temp=top;
    int val=temp->value;
    top=top->next;
    delete temp;
    return val;
}
int postfixevaluation(string postfix){
    for(int i=0;i< postfix.length();i++){
        char ch=postfix[i];
        if(isdigit(ch)){
            push(ch -'0');
            
        }
        else{
            if(ch=='+'){
                int r=pop();
                int l=pop();
                int z=r+l;
                push(z);
            }
            if(ch=='/'){
                int r=pop();
                int l=pop();
                int z=l/r;
                push(z);
            }
            if(ch=='*'){
                int r=pop();
                int l=pop();
                int z=r*l;
                push(z);
            }
            if(ch=='>'){
                int r=pop();
                int l=pop();
                if(l>r){
                    push(1);
                }
                else{
                    push(0);
                }
            }
            if(ch=='<'){
                int r=pop();
                int l=pop();
                if(l<r){
                    push(1);
                }
                else{
                    push(0);
                }
            }            
        }
            if(ch=='|'){
                int r=pop();
                int l=pop();
                if(l==0 && r==0){
                     push(0);
                }
                else{
                    push(1);
                }
            }        
    }
    int res=pop();
    return res;
}
int main() {
    //3>8;  //0 means false 1 means true
    //38>
    //932*2/+
    //infix="9+(3*2)/2";
    //3>2 || 4<1
    //32>41<|
    string postfix="932*2/+";
    int result=postfixevaluation(postfix);
    cout<<"result:"<<result;
    
    return 0;
}
