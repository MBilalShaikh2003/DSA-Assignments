
#include <iostream>
using namespace std;
struct vertex;
struct edge{
    int data;
    edge* next;
    vertex* ver;
};
struct vertex{
    bool visited;
  int data;
  vertex* next;
  edge* edgelist=NULL;
};

vertex* head=NULL;
int top=-1;
void push(vertex* value,vertex* stack[],int size){
    if(top==size-1){
        cout<<"stackoverflow"<<endl;
        return;
    }
    top++;
    stack[top]=value;
    
}
vertex* pop(vertex* stack[],int size){
    if(top==-1){
        return NULL;
    }
    vertex* temp=stack[top];
    top--;
    return temp;
    
    
}
vertex* searchvertex(int a){
    if(head==NULL){
        cout<<"no vertex"<<endl;
        return NULL;
    }
    vertex* curr=head;
    while(curr!=NULL){
        if(curr->data==a){
            return curr;
        }
        curr=curr->next;
    }
    if(curr==NULL){
        cout<<" vertex not founded";
    }
    return curr;
}

void addvertex(){
    vertex* ptr=new vertex;
    int a;
    cout<<"enter vertex:";
    cin>>a;
    ptr->data=a;
    ptr->next=NULL;
    ptr->edgelist=NULL;
    ptr->visited=false;
    if(head==NULL){
        head=ptr;
        return;
    }
    vertex* curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=ptr;
    
}

void addedge(){
    int source;
    cout<<"enter source vertex:";
    cin>>source;
    int dest;
    cout<<"enter source destination:";
    cin>>dest;
    vertex* searchsource=searchvertex(source);
    vertex* searchdest=searchvertex(dest);
    
    edge* ptr1=new edge;
    ptr1->data=dest;
    ptr1->ver=searchdest;
    ptr1->next=NULL;
    
    
    if(searchsource->edgelist==NULL){
        searchsource->edgelist=ptr1;
    }
    else{
    edge* curr=searchsource->edgelist;
    while(curr->next!=NULL){
        curr=curr->next;
    }
        curr->next=ptr1;
    }
    edge* ptr2=new edge;
    ptr2->ver=searchsource;
    ptr2->next=NULL;
    if(searchdest->edgelist==NULL){
        searchdest->edgelist==ptr2;
    }
    else{
        edge* temp=searchdest->edgelist;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr2;
    }
    
}
void printvertices(){
    vertex* curr=head;
    if(curr==NULL){
        cout<<"no vertices in graph"<<endl;
        return;
    }
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}
void printconnectedvertices(){
    vertex* curr=head;
    if(curr==NULL){
        cout<<"no vertex"<<endl;
        return;
    }
    while(curr!=NULL){
        cout<<curr->data<<" ";
        edge* edg=curr->edgelist;
        while(edg!=NULL){
            cout<<"Edge"<<curr->data<<"to"<<edg->ver->data<<endl;
            edg=edg->next;
        }
        curr=curr->next;
    }
}
void findpath(int src, int dest) {
    vertex* stack[10];
    vertex* srcnode = searchvertex(src);
    vertex* destnode = searchvertex(dest);

    if (destnode == NULL) {
        cout << "Destination node not found." << endl;
        return;
    }

    vertex* currvertex = srcnode;
    do {
        edge* curredge = currvertex->edgelist;
        while (curredge != NULL && curredge->ver->visited) {
            curredge = curredge->next;
        }
        currvertex->visited = true;
        if (curredge == NULL) {
            currvertex = pop(stack, 10);
        }
        else {
            push(currvertex, stack, 10);
            currvertex = curredge->ver;
        }
    } while (currvertex->data != destnode->data);

    cout << currvertex->data;
    while (top != -1) {
        vertex* temp = pop(stack, 10);
        cout << "<-" << temp->data;
    }
    cout << endl;

    // Reset visited flag for all vertices
    currvertex = head;
    while (currvertex != NULL) {
        currvertex->visited = false;
        currvertex = currvertex->next;
    }
}
int degree() {
    if (head == NULL) {
        cout << "No vertices in the graph." << endl;
        return -1;
    }

    int vertice;
    cout << "Enter the vertex value: ";
    cin >> vertice;

    vertex* curr = head;
    while (curr != NULL) {
        if (curr->data == vertice) {
            break;
        }
        curr = curr->next;
    }
    if (curr == NULL) {
        cout << "Vertex not present in the graph." << endl;
        return 0; // Degree of a non-existent vertex is 0
    }

    int count = 0;
    edge* temp = curr->edgelist;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    cout << "Degree of vertex " << vertice << " is: " << count << endl;
    return count;
}




int main() {
    int choice;
    do{
        cout<<"enter 1 to add vertex, 2 to ad an edge, 3 to print  vertices, 4 to print connected vertices,5 to find path 6 to find degree, 0 to exit";
        cin>>choice;
        if(choice==1){
            addvertex();
        }
       if(choice==2){
            addedge();
        }
       if(choice==3){
            printvertices();
        }         
        if(choice==4){
            printconnectedvertices();
        }
        if(choice==5){
            int source;
            cout<<"enter source:";
            cin>>source;
            int dest;
            cout<<"enter destination:";
            cin>>dest;
            findpath(source,dest);
        } 
        if(choice==6){
            int deg=degree();
            cout<<"degree= "<<deg<<endl;
        }        
    }while(choice!=0);
    return 0;
}
