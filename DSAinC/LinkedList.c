#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
}*start;

void create_LL(){

    struct node *newnode, *temp;
    int n, i;
    
    printf("enter the no of nodes");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        if(start==NULL)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("enter the data");
            scanf("%d", &newnode->data);
            start = newnode;
        }

        else
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("enter the data");
            scanf("%d", &newnode->data);
            temp = start;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

void insert_b4()
{
    struct node *newnode,*temp,*p;

    int val,data;

    printf("Data to be inserted");
    scanf("%d",&data);

    printf("Value before which data to be inserted");
    scanf("%d",&val);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    p = start;
    temp = start;

    while(temp -> data !=val)
    {
        p = temp;
        temp = temp ->next;
    }

    if(temp == start)
    {
        newnode -> next = start;
        start = newnode;
    }
    else
    {
        p -> next = newnode;
        newnode -> next = temp;
    }
}

void insert_aft()
{
    struct node *temp,*newnode,*post;

    int val,data;
    printf("enter the dat to be inserted");
    scanf("%d",&data);

    printf("enter the value after which data to be inserted");
    scanf("%d",&val);   

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = data;

    post = start;
    temp = start;

    while(temp -> data !=val)
    {
        temp = temp -> next;
    }

    post = temp ->next;
    temp ->next = newnode;
    newnode -> next = post;
}

void delete_node()
{
    struct node *temp ,*p,*post;
    int x;
    printf("enter the value to be deleted");
    scanf("%d",&x);

    temp = start;
    while(temp!=NULL && temp->data !=x)
    {
        p = temp;
        temp = temp -> next;
    }

    if(temp == start)
    {
        start = temp->next;
        free(temp);
    }
    else if(temp == NULL)
    {
        printf("value not found");
    }
    else
    {
        post = temp -> next;
        p -> next = post;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp = start;
    while(temp ->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
    printf("\n");
}

void main()
{
    int choice=5,yes =1;
    start = NULL;

    while(choice!=6)
    {
        printf("1.create 2.insert before 3.insert after 4.delete 5.display 6.exit");
        printf("enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: create_LL();
                    break;

            case 2: insert_b4();
                    break;

            case 3: insert_aft();
                    break;

            case 4: delete_node();
                    break;

            case 5: display();
                    break;

            case 6: yes = 0;
                    break;

            default: printf("invalid choice");
        }
    }
}























