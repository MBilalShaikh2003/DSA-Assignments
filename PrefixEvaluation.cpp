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
int prefixevaluation(string prefix) {
    for(int i = prefix.length()-1; i >=0 ; i--) {
        char ch = prefix[i];
        if(isdigit(ch)) {
            push(ch - '0');
        } else {
            int r = pop();
            int l = pop();
            if(ch == '+') {
                push(l + r);
            } else if(ch == '-') {
                push(l - r);
            } else if(ch == '*') {
                push(l * r);
            } else if(ch == '/') {
                push(l / r);
            } else if(ch == '>') {
                push(l > r ? 1 : 0);
            } else if(ch == '<') {
                push(l < r ? 1 : 0);
            } else if(ch == '|') {
                push((l == 0 && r == 0) ? 0 : 1);
            }
        }
    }
    int res = pop();
    return res;
}

int main() {
    string prefix = "+*93/22";  // Example prefix expression: + * 9 3 / 2 2
    int result=prefixevaluation(prefix);
    cout<<"result:"<<result;
    return 0;
    //3>8;  //0 means false 1 means true
    //38>
    //932*2/+
    //infix="9+(3*2)/2";
    //3>2 || 4<1
    //32>41<|
   // string postfix="932*2/+";
   
}
