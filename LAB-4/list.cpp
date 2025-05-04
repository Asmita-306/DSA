#include<stdio.h>
#include<iostream>
class List{
private:
    struct node{
        int data;
        struct node *next;
    };
   node *head;
public:
  List(){
    head=NULL;
  }
  int insertionBeg(int num);
  int insertionEnd(int num);
  int insertionpo(int num,int pos);
  int deleteBeg(int num);
  int deleteEnd(int num);
  int deletepo(int pos);
  int search(int key);
  void reverselink();
  void display();
  void displayReverse();
};
int main(){
    int choice,num,pos,key;
    List l;
    do{
        printf("\nMenu:\n");
        printf("1.Insert Beginning\n");
        printf("2.Insert at the End\n");
        printf("3.Insert at any position\n");
        printf("4.Deletion at the Beginning\n");
        printf("5.Deletion at the End\n");
        printf("6.Deletion at any  position\n");
        printf("7.Search\n");
        printf("8.Display\n");
        printf("9.Display Reverse\n");
        printf("10.Reverse link\n");
        printf("11.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
        case 1:
            printf("Enter the value to insert at the beginning: \n");
            scanf("%d",&num);
            l.insertionBeg(num);
            break;
        case 2:
            printf("Enter the value to insert at the end: \n");
            scanf("%d",&num);
            l.insertionEnd(num);
            break;
        case 3:
            printf("Enter the value to inserted at any position: \n");
            scanf("%d",&num);
            printf("Enter the the position at which the value should be inserted: \n");
            scanf("%d",&pos);
            l.insertionpo(num,pos);
            break; 
        case 4:
            l.deleteBeg(num);
            break;
        case 5:
            l.deleteEnd(num);
            break;
        case 6:
            printf("Enter the position: \n");
            scanf("%d",&num);
            l.deletepo(pos);
            break;
        case 7:
            printf("Enter the key value to be searched: ");
            scanf("%d",&key);
            l.search(key);
        case 8:
            l.display();
            break;
        case 9:
            l.displayReverse();
            break;
        case 10:
            printf("The reversed list is");
            l.reverselink();
            break;
        case 11:
            printf("Exitingggg......");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }while(choice!=11);
    return 0;
}
int List::insertionBeg(int num){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
    return 1;
    }
int List::insertionEnd(int num){
 struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    if(head==NULL){
    head=newnode;
    return 1;
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=newnode;
        return 1;
    }
}
int List::deleteBeg(int num){
    if(head==NULL){
        printf("List is empty\n");
        return 0;
    }
    node*temp=head;
    head=head->next;
    delete temp;
    return 1;
}
int List::deleteEnd(int num){
 if(head==NULL){
  printf("The list is empty\n");
  return 0;
 }
 node *temp=head;
 while(temp->next!=NULL && temp->next->next!=NULL){
    temp=temp->next;
 }
 node *todelete = temp->next;
 temp->next=NULL;
 delete todelete;
 return 1;
}
int List::deletepo(int pos)
{
struct node *temp = head;
while(pos != 1 && temp->next->next != NULL){
temp = temp -> next;
pos--;
 }
if (pos!=1)
return 0;
else
{
int data = temp->next->data;
struct node* temp1 = temp->next;
 temp -> next = temp1 ->next;
 free(temp1);
return data;
}
}
int List::insertionpo(int num, int pos){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    if(pos <= 0){
        printf("Invalid position\n");
        return 0;
    }
    if(pos == 1){
        newnode->next = head;
        head = newnode;
        return 1;
    }
    struct node *temp = head;
    int count = 1; 
    while(count < pos - 1 && temp != NULL){
        temp = temp->next;
        count++;
    }
    if(temp == NULL){
        printf("Position is invalid\n");
        free(newnode); 
        return 0;
    }
    newnode->next = temp->next;
    temp->next = newnode;
     return 1;
}

void List::display(){
    node *temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
int List::search(int key){
   struct node *temp=head;
    int index=0;
    while(temp !=NULL){
        if(temp->data==key){
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}
void List::reverselink(){
    node *prev=NULL;
    node *current=head;
    node *nextNode=NULL;
    while(current !=NULL){
        nextNode=current->next;
        current->next=prev;
        prev=current;
        current=nextNode;
    }
    head=prev;
}
void List::displayReverse(){
    struct node *temp = head;
    int count =0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    for(int i = count;i>0;i--){
        temp = head;
        int j=i-1;
        while( j>0){
            temp = temp->next;
            j--;
        }
        printf("%d->",temp->data);
    }
}