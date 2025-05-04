#include<stdio.h>
#include<stdlib.h>
#include<cstdio>
class Tree{
    private:
        struct node{
            int data;
            struct node *left;
            struct node *right;
        };
        node *root;
    public:
        Tree(){
            root=NULL;
        }
        int insertion(int num);
        void preorder();
        void inorder();
        void postorder();
        int search(int num);
};
int main(){
    Tree t;
    int choice,num,result;
    do{
        printf("Menu\n");
        printf("1.Insertion\n");
        printf("2.Preorder\n");
        printf("3.Inorder\n");
        printf("4.Postorder\n");
        printf("5.Search\n");
        printf("6.Exit\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the the value to be inserted: ");
                scanf("%d",&num);
                t.insertion(num);
                break;
            case 2:
                t.preorder();
                break;
            case 3:
                t.inorder();
                break;
            case 4:
                t.postorder();
                break;
            case 5:
                printf("Enter the value to be searched: ");
                scanf("%d",&num);
                result=t.search(num);
                if(result!=0){
                    printf("Element found!");
                }
                else{
                    printf("Element is not found\n");
                }
                break;
            case 6:
                printf("Exiting!\n");
                break;
            default:
                printf("Invalid choice! Try again\n");
        }
    }while(choice!=6);
    return 0;
}
int Tree::insertion(int num){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL){
        root=newnode;
        return 0;
    }
    struct node *temp=root;
    struct node *parent=NULL;
    while(temp!=NULL){
        parent=temp;
        if(num<temp->data){
           temp=temp->left; 
        }
        else if(num>temp->data){
            temp=temp->right;
        }
        else{
            return 0;
        }
    }
    if(num<parent->data){
        parent->left=newnode;
    }
    else{
        parent->right=newnode;
    }
    return root->data;
    }
void Tree::preorder() {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
        }
        struct node *stack[100]; 
        int top = -1;
    
        stack[++top] = root; 
    
        while (top >= 0) {
            struct node *temp = stack[top--]; 
            printf(" %d ", temp->data);
            if (temp->right != NULL) {
                stack[++top] = temp->right;
            }
            if (temp->left != NULL) {
                stack[++top] = temp->left;
            }
        }
        printf("\n");
    }
void Tree::inorder(){
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    struct node *stack[100];
    int top = -1;
    struct node *temp = root;
    while (temp != NULL || top >= 0) {
        while (temp != NULL) {
            stack[++top] = temp;
            temp = temp->left;
        }
        temp = stack[top--];
        printf(" %d ", temp->data);
        temp = temp->right;
    }
    printf("\n"); 

}
void Tree::postorder(){
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    struct node *stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {
        struct node *temp = stack1[top1--];
        stack2[++top2] = temp;
        if (temp->left != NULL) {
            stack1[++top1] = temp->left;
        }
        if (temp->right != NULL) {
            stack1[++top1] = temp->right;
        }
    }
    while (top2 >= 0) {
        printf(" %d ", stack2[top2--]->data);
    }
    printf("\n");
}
int Tree::search(int num){
    node *temp=root;
    while(temp!=NULL){
     if(temp->data==num) return 1;
     if(num<temp->data){
         temp=temp->left;
     }
     else{
         temp=temp->right;
     }
    }
    return 0;
 }
