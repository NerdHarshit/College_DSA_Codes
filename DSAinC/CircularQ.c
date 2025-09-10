#include<stdio.h>
#include<ctype.h>

#define size 5

int queue[size];
int f = -1,e =-1;

void enQ(int val)
{
    if(f==(e+1)%size)
    {
        printf("Full");
    }

    else if(f==-1)//or e ==-1
    {
        f =0;
        e = 0;
        queue[e] = val;
    }

    else{
        e = (e+1)%size;
        queue[e] = val;
    }
}

void dQ()
{
    int val;

    if(f==-1)
    {
        printf("empty");
    }

    else if(f == e)
    {
        val = queue[f];
        f = -1;
        e = -1;
        printf("deleted val %d:",val);
    }

    else{
        val = queue[f];
        f = (f+1)%size;
        printf("deleted value is :%d",val);
    }
}

void display()
{int i;
   if(f==-1)
    {
        printf("empty");
    }
    
    for(i =f;i!=e;i = (i+1)%size)
    {
        printf("%d",queue[i]);
    }

    printf("%d",queue[i]);
}
void main()
{
    int choice;
    int x;
    int yes = 1;

    while(yes)
    {

        printf("enter the number");
        scanf("%d",&x);

        printf("enter the choice 1 enq 2 deq 3 print 0 to exit");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            enQ(x);
            break;

        case 2:
            dQ(x);
            break;

        case 3:
            display();
            break;

        case 0:
            yes = 0;
            break;
        
        default:
            break;
        }


    }

}