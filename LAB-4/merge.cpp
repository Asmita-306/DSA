#include<stdio.h>
#include<iostream>
using namespace std;
class List{
    private:
             struct node{
                 int data;
                 struct node *next;
             }*head;
             node* gethead() const
             {
                 return head;
             }
            
    public:
             List()
             {
                head=NULL;
             }
             int insertAsc(int );
             void display();
             int merge(const List &list1,const List &list2);
            };
 
int main()
{
    List l1;
    List l2;
    List l3;
    int choice,num;
  do
    {
      printf("Menu\n1");
      printf("1.Insertion in  list1\n");
      printf("2.Insertion in  list 2\n");
      printf("3.Merging\n");
      printf("4.Display\n");
      printf("5.Exit\n");
      printf("Enter the choice from the menu: ");
      scanf("%d",&choice);
      switch(choice)
      {
        case 1:
                int num;
                printf("Enter the number to list 1\n");
                scanf("%d",&num);
                l1.insertAsc(num);
                break;
        case 2:
                int num1;
                printf("Enter the number to list2\n");
                scanf("%d",&num1);
                l2.insertAsc(num1);
                break;
        case 3:
                l3.merge(l1,l2);
                break;
                
        case 4:
                printf("The first list is:\n");
                l1.display();
                printf("The second list is:\n");
                l2.display();
                printf("The third list is:\n");
                l3.display();
                break;
        case 5:
                printf("Exitingg\n");
                break;
        default:
                printf("Invalid option\n");
      }
    
    }
    while(choice!=5);
      return 0;
}
int List::insertAsc(int num)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=num;
    if(head==NULL || head->data>num)
    {
       newnode->next=head;  
       head=newnode;
       return 1;
    }
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp->next!=NULL && temp->next->data<num)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return 1;

 }

 int List::merge( const List &list1,  const List &list2) { 
    node* temp1 = list1.gethead();
    node* temp2 = list2.gethead();
    head = NULL;
    node* current = NULL;

    while (temp1 != NULL && temp2 != NULL) {
        node* newNode = new node;
        if (temp1->data < temp2->data) {
            newNode->data = temp1->data;
            temp1 = temp1->next;
        } else {
            newNode->data = temp2->data;
            temp2 = temp2->next;
        }
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }

    while (temp1 != NULL) {
        node* newNode = new node;
        newNode->data=temp1->data;
        newNode->next=NULL;
        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }
        temp1 = temp1->next;
    }

    while (temp2 != nullptr) {
        node* newNode = new node;
        newNode->data=temp2->data;
        newNode->next=NULL;
        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }
        temp2 = temp2->next;
    }

    return 1;
}


 void List::display()
    {
            struct node* temp=(struct node*)malloc(sizeof(struct node));
            temp=head;
            while(temp!=nullptr)
            {
                printf("%d ",temp->data);
                temp=temp->next;
            } 
    }
