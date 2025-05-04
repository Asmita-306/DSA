    #include<stdio.h>
    #include<iostream>
    using namespace std;
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
    //Function prototypes
    void insertionBeg(int num);
    void insertionEnd(int num);
    void insertionPos(int num,int pos);
    int deletionBeg();
    int deletionEnd();
    int deletionPos(int pos);
    void display();
    int search(int key);
    };
    int main(){
        int choice,num,result,key,pos;
    List l;
    do{
        printf("\nMenu:\n");
        printf("1.Insert Beginning\n");
        printf("2.Insert at the end\n");
        printf("3.Insertion at any position\n");
        printf("4.Deletion at the Beginning\n");
        printf("5.Deletion at the End\n");
        printf("6.Deletion at any position\n");
        printf("7.Display\n");
        printf("8.Search\n");
        printf("9.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
        case 1:
            printf("Enter the value to insert at the beginning: ");
            scanf("%d",&num);
            l.insertionBeg(num);
            break;
        case 2:
            printf("Enter the value to insert at the End: ");
            scanf("%d",&num);
            l.insertionEnd(num);
            break;
        case 3:
            printf("Enter the value to insert at any position: ");
            scanf("%d",&num);
            printf("Enter the position at which the number should be inserted: ");
            scanf("%d",&pos);
            l.insertionPos(num,pos);
            break;
        case 4:
            result=l.deletionBeg();
            if(result!=0){
            printf("The element Deleted is: %d\n",result);
            }
            break;
        case 5:
            result=l.deletionEnd();
            if(result!=0){
                printf("The element deleted is: %d",result);
            }
            break;
        case 6:
            printf("Enter the position to be deleted at any position: ");
            scanf("%d",&pos);
            result = l.deletionPos(pos);
            if(result!=0){
                printf("The element Deleted is : %d\n",result);
            }
            break;
        case 7:
            l.display();
            break;
        case 8:
            printf("Enter the element to be saerched: ");
            scanf("%d",&key);
            result = l.search(key);
            if(result!=-1 && result!=0){
                printf("The Target found in the List\n");
                printf("The position of the target in the list is : %d\n",result);
            }
            else if(result==-1){
                printf("The Target is not found in the List\n");
            }
        case 9:
            printf("EITING");
           break;
        
        default:
            printf("Invalid choice\n");
            break;
        }
    }while(choice!=5);
    return 0;
}
    void List::insertionBeg(int num){
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        if(head==NULL){
            newnode->next=newnode;
            head=newnode;
        }
        else{
            node *temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
           temp->next=newnode;
           newnode->next=head;
           head=newnode;
        }
    }
//Function to insertion at the end
void List::insertionEnd(int num){
    if(head==NULL){
        insertionBeg(num);
        return;
    }
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    node *temp=head;
    if(temp->next==head){
        head->next=newnode;
        return;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newnode;
}
//Function to delete at the end
int List :: deletionEnd(){
    if(head==NULL){
        printf("The list is empty");
        return 0;
    }
    if(head == head->next){
        int result = head->data;
        deletionBeg();
        return result;
   }
    node *temp = head;
    while(temp->next->next!=head){
        temp =temp->next;
    }
    node *del = temp->next;
    int result = del->data; 
    temp->next = head;
    free(del);
    return result;
}
//Function to delete at the beginning
int List :: deletionBeg(){
    if (head==NULL){
    printf("The list is empty");
    return 0;
        }
        if(head==head->next){
            node *del = head;
            int result = head->data;
            head = NULL;
            printf("All the elements in the list are deleted\n");
            printf("The list is empty\n");
            free(del);
            return result;
        }
        node *del = head;
        int result = del->data;
        head = del->next;
        node *temp = head;
        while(temp->next!=del){
            temp = temp->next;
        }
        temp->next = head;
        free(del);
        return result;
    }
//Function to insert at any position
void List::insertionPos(int num,int pos){
        if(head == NULL){
            insertionBeg(num);
            return;
        }
        if(pos<1){
            printf("Invalid position \n");
            printf("Enter valid position \n");
            return ;
        }
        if(pos==1){
            insertionBeg(num);
            return ;
        }
        node *newnode = (node*)malloc(sizeof(node));
        newnode->data = num;
        newnode->next = NULL;
        int i =1;
        node *temp = head;
        while(i<pos-1 && temp->next!= head){
            temp = temp->next;
            i++;
        }
        if(temp->next==head && i+1<pos){ 
            printf("Position is out of the list\n");
            printf("Enter valid position\n");
            return ;
        }
        if(temp->next == head && i+1 == pos){
            insertionEnd(num);
            free(newnode);
            return ;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    
    }
//Function to delete at any position
int List::deletionPos(int pos){
if(head == NULL){
    printf("The list is empty\n");
    return 0;
}
if(pos<1){
    printf("Invalid position \n");
    printf("Enter valid position \n");
    return 0;
}
if(pos==1){
    int result = head->data;
    deletionBeg();
    return result;
}
int i =1;
    node *temp = head;
while(i<pos-1 && temp->next!=head){
    temp = temp->next;
    i++;
}
if(temp->next==head){ 
    printf("Position is out of the list\n");
    printf("Enter valid position\n");
    return 0;
}
node *del = temp->next;
int result = del->data;
temp->next = del->next;
free(del);
return result;
}
//Function to Search an element
int List::search(int key){
    if(head==NULL){
        printf("The list is empty");
        return 0;
    }
    node *temp = head;
    int count =1;
    while(temp->next!=head){ 
        if(temp->data==key){
            return count;
        }
        count++;
        temp = temp->next;}
    return -1;
}
//Function to display
void List :: display(){
        if(head==NULL){ 
            printf("The list is empty\n");
            return;
        }
        node *temp = head;
        do{
            printf("%d->",temp->data);
            temp=temp->next;
        }
        while(temp!=head);
        printf("(back to head)\n");
    }