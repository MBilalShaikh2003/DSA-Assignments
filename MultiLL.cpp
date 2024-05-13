// Online C++ compiler to run C++ program online
#include <iostream>
//#include <stdlib.h>
using namespace std;
struct student{
  int sid;
  student* next;
};
struct course{
  int cid;
  course* next;
  student *stud=NULL;
};
course* head=NULL;
void insert(){
    course* ptr=new course;
    cout<<"enter course code:";
    cin>>ptr->cid;
    ptr->next=NULL;
    if(head==NULL || head->cid > ptr->cid){
        ptr->next=head;
        head=ptr;
        return;
    }
    course* curr=head;
    if(curr->next!=NULL){
        curr=curr->next;
    }
    ptr->next=curr->next;
    curr->next=ptr;
}
void search(){
    course* curr=head;
    cout<< "enter course code";
    int x;
    cin>>x;
    if(curr==NULL){
        cout<<"course list empty"<<endl;
        return;
    }
    while(curr!=NULL){
    if(curr->cid==x){
        cout<<"course id found"<< endl;
        return;
    }
    curr=curr->next;
    }
    cout<<"Course id not found"<<endl;
}
void print(){
    course* curr=head;
    if(curr==NULL){
        cout<<"course list empty";
        return;
    }
    while(curr!=NULL){
        cout<<curr->cid<<" ";
        curr=curr->next;
    }
}
void deletecourse(){
   if(head==NULL){
        cout<<"course list empty";
        return;
    }
    cout<<"enter course id to delete:";
    int x;
    cin>>x;
    course* curr=head;
    if(head->cid==x){
        if(head->next!=NULL){
            head=head->next;
        }
        delete curr;
        cout<<"DELETED"<<endl;
        curr=head;
    }
    course* prev=curr;
    curr=curr->next;
    while(curr!=NULL && curr->cid!=x){
        prev=curr;
        curr=curr->next;
    }
    if(curr==NULL){
        cout<<"NOT FOUND"<<endl;
        return;
    }
    prev->next=curr->next;
    delete curr;
    cout<<"DELETED"<<endl;
    return;
}
void addstudent(){
       if(head==NULL){
        cout<<"course list empty";
        return;
    }
    course* curr=head;
    int c;
    cout<<"which course you want to enroll:";
    cin>>c;
    while(curr!=NULL){
        if( curr->cid==c){
            student* s=new student;
            int a;
            cout<<"enter student id:";
            cin>>a;
            s->sid=a;
            if(curr->stud==NULL){
                curr->stud=s;
                s->next=NULL;
            }
            else{
                student* temp=curr->stud;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=s;
                
            }
        }
        curr=curr->next;
    }
}
void studentprint(){
       if(head==NULL){
        cout<<"course list empty";
        return;
    }
    int b;
    cout<<"enter course id";
    cin>>b;
    course* curr=head;
    while(curr!=NULL){
        if(curr->cid==b){
            if(curr->stud==NULL){
                cout<<"no students in course"<<endl;
                return;
            }
            student* temp=curr->stud;
            while(temp!=NULL){
                cout<<temp->sid;
                temp=temp->next;
            }
            return;
        }
        curr=curr->next;
    }
    if(curr==NULL){
        cout<<"course not found"<<endl;
        return;
    }
}
void deletestdfromcourse(){
     if(head==NULL){
        cout<<"course list empty";
        return;
     }
     int courseid;
     cout<<"enter course id:";
     cin>>courseid;
     course* curr=head;
     while(curr!=NULL){
         if(curr->cid==courseid){
             int delstd;
             cout<<"enter student to delete from this course:";
             cin>>delstd;
             if(curr->stud==NULL){
                 cout<<"no students in this course"<<endl;
                 return;
             }
             student* temp=curr->stud;
             if(curr->stud->sid==delstd){
                 curr->stud=curr->stud->next;
                 delete temp;
                 cout<<"deleted"<<endl;
                 return;
             }
             student* prev=temp;
             temp=temp->next;
             while(temp!=NULL){
                 if(temp->sid==delstd){
                     prev->next=temp->next;
                     delete temp;
                     cout<<"deleted"<<endl;
                     return;
                 }
                 temp=temp->next;
             }
             if(temp==NULL){
                 cout<<"student not found"<<endl;
                 return;
             }
         }
         curr=curr->next;
     }
     if(curr==NULL){
         cout<<"course not found"<<endl;
         return;
     }
}
void searchstudent(){
    if(head==NULL){
        cout<<"course list empty";
        return;
     }
     int search;
     cout<<"enter course id:";
     cin>>search;
     course* curr=head;
     while(curr!=NULL){
         if(curr->cid==search){
            if(curr->stud==NULL){
                 cout<<"no students in this course"<<endl;
                 return;
             }
             int studid;
             cout<<"enter student to search:";
             cin>>studid;
             student* temp=curr->stud;
             while(temp!=NULL){
                 if(temp->sid==studid){
                     cout<<"student found"<<endl;
                     return;
                 }
                 temp=temp->next;
             }
             if(temp==NULL){
                 cout<<"not found"<<endl;
                 return;
             }
             
         }
         curr=curr->next;
     }
     if(curr==NULL){
         cout<<"Course not found"<<endl;
         return;
     }
}
void deleteallstudent(){
   if(head==NULL){
        cout<<"course list empty";
        return;
     }
    course* curr=head;
    while(curr!=NULL){
       if(curr->stud!=NULL){
            student* currst=curr->stud;
            while(currst!=NULL){
                student* temp=currst->next;
                delete currst;
                currst=temp;
            }
            curr->stud=NULL;
         }
        else{
            cout<<"no student in this course:"<<curr->cid<<endl;
        } 
         curr=curr->next;
    }
}
int main() {
    int n;
    do{
        cout<<"enter 1 to add course,2 to search course,3 to print course list,4 to delete a course,5 to add student to a course,6 to print students,7 to delete student from course,8 to search a student,9 to delete student from all courses,0 to exit";
        cin>>n;
        if(n==1){
            insert();
        }
       if(n==2){
            search();
        }
        if(n==3){
            print();
        }
       if(n==4){
            deletecourse();
        }
        if(n==5){
            addstudent();
        }
       if(n==6){
            studentprint();
        }
        if(n==7){
            deletestdfromcourse();
        }
       if(n==8){
            searchstudent();
        }
       if(n==9){
            deleteallstudent();
        }        
    }while(n!=0);
    

    return 0;
}
