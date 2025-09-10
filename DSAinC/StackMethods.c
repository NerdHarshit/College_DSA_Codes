#include<stdio.h>

int top = -1;
int max = 5;
int stack[5];

void push(int val)
{
    if(top == max-1){
        printf("Stack overflow");
        return;
    }

    top+=1;
    stack[top] = val;
}

int pop()
{
    if(top==-1){
        printf("Stack empty");
        return;
    }

    int lastval = stack[top];
    top-=1;
    return(lastval);
}

int peek()
{
    if(top==-1){
        printf("Stack empty");
        return;
    }
    return(stack[top]);
}

void display(){
    int i;
     if(top==-1){
        printf("Stack empty");
        return;
    }

    for(i=top;i>=0;i--)
    {
        printf("%d\t",stack[i]);
    }
}


void main()
{
    int stay = 1;
    int choice ;

    while(stay)
    {
        int val;
        printf("Enter your choice\n 1:push\n2:pop\n3:peek\n4:display");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("enter the value");
            scanf("%d",&val);
            push(val);
            break;

        case 2:
            printf("the value popped is %d",pop());
            break;
        
        case 3:
            printf("the value peeked is %d",peek());
            break;

        case 4:
            display();
            break;
        
        
        default:
            printf("invalid input");
            break;
        }

        printf("enter 1 to continue and 0 to exit");
        scanf("%d",&stay);
        
    }
}
