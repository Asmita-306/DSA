#include<stdio.h>
#include<iostream>
using namespace std;
class List{

   private:
   struct node{
    int data;
    struct node *next;
    struct node *prev;
   };
    struct node *head;
    struct node *tail;
   public:
   List(){
    //Constructor
    head=tail=NULL;
   }
   void insertionBeg(int num);
   void display();
};
int main(){
    int choice,num,pos,key,result;
    List l;
    l.insertionBeg(45);
    l.insertionBeg(100);
    l.display();
    return 0;
}
void List::insertionBeg(int num){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->prev=NULL;
    if(head==NULL){
        head=tail=newnode;
    }
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}
void List::display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
struct node *temp = head;
// Display forward
printf("Forward: ");
do{
        printf("%d<=>", temp->data);
        temp = temp->next;
    }
    while(temp!=NULL);
    printf("NULL\n");
temp = tail;
while (temp->next != NULL) {
        temp = temp->next;
}
// Display backward
    printf("Backward: ");
    do{
        printf("%d<=>", temp->data);
        temp = temp->prev;
    }while(temp!=NULL);
    printf("NULL\n");
}
