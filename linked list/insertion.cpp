#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data=0;
        this->next=NULL;
    }
      Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void print(Node * head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
}
int findLenth(Node*&head){
    Node* temp=head;
    int len=1;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
return len;
}
void insertAtHead(Node *&head,Node*&tail,int data){ 
     if(head==NULL) {
        Node*newNode=new Node(data);
        head=tail=newNode;
        return;
    }
    Node *newNode=new Node(data);
    newNode->next=head;
    head=newNode;
  
}
void insertAtTail(Node*&head,Node*&tail,int data){
     if(head==NULL) {
        Node*newNode=new Node(data);
        head=tail=newNode;
        return;
    }
    Node*newNode=new Node(data);
    tail->next=newNode;
    tail=newNode;


}

void insertAtPosition(int position,Node *&head, Node *&tail, int data){
  int len=findLenth(head);
  if(position>len){
      cout<<"wrong value"<<endl;
  }

    if(head==NULL) {
        Node*newNode=new Node(data);
        head=tail=newNode;
        return;
    }
if(position==0){
    insertAtHead(head,tail,data);
    return;
}
      Node*newNode=new Node(data);
      Node *prev=head;

      for(int i=1;i!=position;i++){
      prev=prev->next;
  }
      Node* current=prev->next;
      newNode->next=current;
      prev->next=newNode;
}


int main() {
  Node *head = NULL;
  Node *tail = NULL;
  insertAtHead(head,tail,100);
  insertAtHead(head,tail,99);
  insertAtHead(head,tail,98);
  insertAtHead(head,tail,100);
  insertAtHead(head,tail,100);

  insertAtTail(head,tail,1000);
  insertAtPosition(5,head,tail,2);
  print(head);
  
  return 0;
}