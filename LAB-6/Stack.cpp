#include<cstdio>
#include<cstdlib>
class stack{
    private:
            struct node{
               char data;
               struct node* next;  
            }*top;
    public:
            stack()
            {
                top=nullptr;
            } 
            int push(char);
            char pop();
            int check_bal(const char*);
            int isEmpty();
            void display();

};
int main()
{
   stack s1;
   int opt;
   while(1)
   {
    printf("Enter your choice between the following\n1.Check Balance\n2.Exit\n");
    scanf("%d",&opt);
    switch(opt)
    {
      case 1:
              char str[100];
              printf("Enter the expression you want to check\n");
              scanf("%s",str);
              int check;
              check=s1.check_bal(str);
              if(check==0)
              {
                printf("It is an unbalanced equation\n");
              }
              else
              {
                printf("It is a balanced reaction\n");
              }
              break;
      case 2:
              printf("Exiting program\n");
              return 0;
      default:
              printf("Invalid option\n");
              break;
    }
   }  
}

int stack::push(char c)
{
  struct node* newnode=(struct node*)malloc(sizeof(struct node*));
  if (!newnode) {
    printf("Stack Overflow\n");
    return 0;
  }
  newnode->data=c;
  newnode->next=top;
  top=newnode;
  return 1;
}

char stack::pop()
{
  if(top==nullptr)
  {
    return '0';
  }
  
    struct node* del_node=top;
    char del=top->data;
    top=top->next;
    free(del_node);
    return del;
  
  
}
int stack::isEmpty()
{
    return top==nullptr;
}

int stack::check_bal(const char* str)
{
   for(int i=0;str[i]!='\0';i++)
   {
    if(str[i]=='(')
    {
        push('(');
    }
    else if (str[i]==')')
    {
        pop();
    }
    
   }
   return isEmpty();
}


