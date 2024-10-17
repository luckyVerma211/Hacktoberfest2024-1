#include<iostream>
using namespace std;
class Node{
  public:
    int data;
    Node *next;
    static int size_of_list;
    Node(int value){
      data=value;
      next=NULL;
      size_of_list++;
    }
};
int Node::size_of_list=0;
void add_at_beg(Node **start,int value){
  Node *temp;
  temp=new Node(value);
  if(*start==NULL)
    *start=temp;
  else{
    temp->next=*start;
    *start=temp;
  }
}
void add_at_end(Node **start,int value){
  Node *temp,*ptr;
  ptr=*start;
  temp=new Node(value);
  if(ptr==NULL)
    *start=temp;
  else{
    while(ptr->next!=NULL)
      ptr=ptr->next;
    ptr->next=temp;
  }
}
void add_at_position(Node **start,int value,int pos){
  if(pos==1){
    add_at_beg(&(*start),value);
    return;
  }
  else if(pos>(*start)->size_of_list){
    add_at_end(&(*start),value);
    return;
  }
  Node *temp;
  temp=*start;
  for(int i=1;i<=pos-2;i++)
    temp=temp->next;
  Node *ptr;
  ptr=new Node(value);
  ptr->next=temp->next;
  temp->next=ptr;
}
void display(Node **start){
  Node *temp;
  temp=*start;
  if(temp==NULL)
    printf("List is Empty\n");
  else{
    do{
      cout<<temp->data<<" ";
      temp=temp->next;
    }while(temp!=NULL);
    cout<<endl;
  }
}
int main(){
  Node *Head;
  Head=NULL;
  int ch,val,pos;
  do{
    cout<<"Press 1 - To add a Node at the Beginning"<<endl;
    cout<<"Press 2 - To add a Node at the End"<<endl;
    cout<<"Press 3 - To add a Node at Given position"<<endl;
    cout<<"Press 4 - To Display the Linked List"<<endl;
    cout<<"Press 5 - To Exit\n"<<endl;
    cout<<"Enter the choice:";
    cin>>ch;
    if(ch==1){
      cout<<"Enter the value to be added:";
      cin>>val;
      add_at_beg(&Head,val);
    }
    else if(ch==2){
      cout<<"Enter the value to be added:";
      cin>>val;
      add_at_end(&Head,val);
    }
    else if(ch==3){
      cout<<"Enter the value to be added:";
      cin>>val;
      cout<<"Enter the position where value to be added:";
      cin>>pos;
      add_at_position(&Head,val,pos);
    }
    else if(ch==4)
      display(&Head);
    else 
      break;
  }while(1);
  return 0;
}
