#include <iostream>
#include <stdlib.h>
using namespace std;
struct stack{
    int value;
    stack*next;
};
void push(stack**top){
    stack *ptr=(stack*)malloc(sizeof(stack));
    int a;
    cout<<"enter value"<<endl;
    cin>>a;
    ptr->value=a;
    if(*top==NULL){
        *top=ptr;
    }
    else{
        ptr->next=*top;
        *top=ptr;
    }
}
void pop(stack**top){
    if(*top==NULL){
        cout<<"stack is empty"<<endl;
    }
    else{   
        stack *curr=*top;		
        *top=(*top)->next;
        cout<<"top element:"<<(*top)->value<<endl;
        free(curr);
    }
}

int main() {
    stack *top=NULL;
      int choice;
    do {
        cout << "Enter 1 for push, 2 for pop, 0 to exit: ";
        cin >> choice;
        switch (choice) {
            case 1:
                push(&top);
                break;
            case 2:
                pop(&top);
                break;
            default:
                cout << "Invalid choice" << endl;
        }
        }while(choice!=0);
    return 0;
}
// #include <iostream>
// #include <stdlib.h>
// using namespace std;
// struct stack{
//   int value;
//   stack* next;
// };
// void push(stack**top){
//     stack *ptr=(stack*)malloc(sizeof(stack));
//     int a;
//     cout<<"enter a value:";
//     cin>>a;
//     ptr->value=a;
//     if((*top)==NULL){
//         *top=ptr;
//     }
//     else{
//     ptr->next=*top;
//     *top=ptr;
// }
// }
// void pop(stack**top){
//     if((*top)==NULL){
//         cout<<"list is empty";
//         return;
//     }
//     else{
//         stack* curr=*top;
//         *top=(*top)->next;
//         free(curr);
//     }
// }
// void Top(stack**top){
//       if((*top)==NULL){
//         cout<<"stack is empty";
//         return;
//     }
//     cout<<"top element:"<<(*top)->value<<endl;
// }
// int main() {
//       stack *top=NULL;
//       int choice;
//     do {
//         cout << "Enter 1 for push, 2 for pop,3 for top 0 to exit: ";
//         cin >> choice;
//         switch (choice) {
//             case 1:
//                 push(&top);
//                 break;
//             case 2:
//                 pop(&top);
//                 break;
//             case 3:
//                 Top(&top);
//                 break;    
//             default:
//                 cout << "Invalid choice" << endl;
//         }
//         }while(choice!=0);
//     return 0;
// }
