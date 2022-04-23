#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Create A class node

class node{
    public:
    int data;
    node* next;

    // Node Class Constructor
    node(int val){
        data=val;
        next=NULL;

    }
};

// Detect a Cycle  Hare And Tortoise Algorithm Or Floyd's Algorithm.
bool detectCycle(node* &head){
    node* slow=head;
    node* fast =head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}

// Make A cycle 

void makeCycle(node* &head,int pos){
    node* temp=head;
    node* startNode;
    int count=1;

    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;

        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}

// Remove A cycle 
void removeCycle(node* &head){
    node* slow=head;
    node* fast=head;

    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);
    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}

// Insert Element At Tail

void insertAtTail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        }
        temp->next=n;
}
// Deletion, Delete A particular Element

//Corner Case When want to delete firts node
void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    // Avoid Memory Leak
    delete todelete;  
}

void deletion(node* &head,int val){
    //For No Node present
    if(head==NULL){
        return;
    }
    //For present only one node
    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
     delete todelete;   
     //Avoid Memory Leak
}

//Reverse A Linked list

node* reverse(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;

    }
    return prevptr;
}

//Reverse A linked list using recursive call Recursion

node* reverseRecursive(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* newhead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;

    return newhead;
}


// Reverse K nodes 

node* reversek(node* &head,int k){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
         }
    if(nextptr!=NULL ){
            head->next=reversek(nextptr,k);
        }
    return prevptr;

}

// Display All Element
// for display not mendatory &head you can use void display(node* head)

void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

// Insert At Head

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}

// Seraching  At Linked List

bool Search(node* head,int key){
    node* temp=head;
    while(temp->next!=NULL){
        if(temp->data==key){
          return true;
        }
        temp=temp->next;  
  }
  return false;
}

int main(){
    
    node* head =NULL;
    insertAtTail(head,12);
    insertAtTail(head,178);
    insertAtTail(head,1788);
    // display(head);
    // insertAtHead(head,345);
    // display(head);
    // cout<<Search(head,178);
    // display(head);
    // deleteAtHead(head);
    // display(head);
    // deletion(head,1788);
    // display(head);
    // deletion(head,178);
    // display(head);
    insertAtTail(head,125);
    insertAtTail(head,198);
    insertAtTail(head,18);
    display(head);
    //node* newhead=reverse(head);
    //node* newhead=reverseRecursive(head);
    // node* newhead=reversek(head,3);

    cout<<detectCycle(head)<<endl;
    // display(newhead);
     makeCycle(head,4);
    //  display(head);
     cout<<detectCycle(head)<<endl;
     removeCycle(head);
     cout<<detectCycle(head)<<endl;




    return 0;
}