#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};//template of node..no memory assigned yet

struct node *start;


void create_LL(){

    start = NULL;
    
    struct node *newnode, *temp;
    int n, i;
    
    printf("enter the no of nodes");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        if(start==NULL)//creating 1st node
        {
            newnode = (struct node *)malloc(sizeof(struct node));//assigning memory and taking its address in newnode

            //adding memory alloc failsafe
            if(newnode == NULL){
                printf("Memory allocation failed\n");
                return;
            }

            printf("enter the data");
            scanf("%d", &newnode->data);//taking data input and putting it in data part of node
            newnode->next = NULL;//initialising next part of node to NULL
            start = newnode;//assigning address of 1st node to start
        }

        else //creating subsequent nodes
        {
            temp = (struct node *)malloc(sizeof(struct node));//assigning memory and taking its address in temp

            //adding memory alloc failsafe
            if(temp == NULL){
                printf("Memory allocation failed\n");
                return;
            }

            printf("enter the data");
            scanf("%d", &temp->data);//taking data input and putting it in data part of node
            temp->next = NULL;//initialising next part of node to NULL
            newnode->next = temp;//assigning the cureently created nodes address to next part of previous node as newnode is holding address of previous node
            newnode = temp;//updating newnode to hold address of currently created node
        }
    }
}

void insert_b4()
{
    struct node *newnode,*temp,*p;

    int val,data;

    printf("Data to be inserted");//enter the data to be inserted
    scanf("%d",&data);

    printf("Value before which data to be inserted");//enter the value before which data to be inserted ... ->[data] ->[val] -> ...
    scanf("%d",&val);

    newnode = (struct node *)malloc(sizeof(struct node));//making the node for new data element and assigning memory , storing it in newnode
    newnode->data = data; // filling data part of newnode with data entered by user

    //initially both p and temp will point to start node
    p = start; // p is a pointer which will point to the node previous to the node containing value val
    temp = start;// temp is a pointer which will point to the node containing value val

    while(temp -> data !=val)//traverse the linked list till we find the node containing value val
    {
        //at the last iteration of loop ->see comments below
        p = temp;//pointing to previous node
        temp = temp ->next;//pointing to node containing value val
    }

    if(temp == start)//if the node to be inserted before is the start node
    {
        newnode -> next = start;//next of newnode will point to start node
        start = newnode;//start pointer will point to newnode
    }
    else//if the node to be inserted before is any node other than start node
    {
        p -> next = newnode;//next of previous node will point to newnode
        newnode -> next = temp;//next of newnode will point to node containing value val so its ... -> [p] -> [newnode] -> [temp]-> ...
    }
}

void insert_aft()
{
    struct node *temp,*newnode,*post;

    int val,data;
    printf("enter the dat to be inserted");//enter the data to be inserted
    scanf("%d",&data);

    printf("enter the value after which data to be inserted");//enter the value after which data to be inserted ... ->[val]->[data]  -> ...
    scanf("%d",&val);   

    newnode = (struct node *)malloc(sizeof(struct node));//making the node for new data element and assigning memory , storing it in newnode
    newnode -> data = data;// filling data part of newnode with data entered by user


     //initially both post and temp will point to start node
    post = start;// post is a pointer which will point to the node after  the node containing value val
    temp = start;// temp is a pointer which will point to the node containing value val

    while(temp -> data !=val)//traverse the linked list till we find the node containing value val .it traverses till one node less but temp is storing next so at last iteration temp will point to node containing value val
    {
        temp = temp -> next;
    }

    if(val == start->data && start->next == NULL)//if there is only one node in the linked list and we have to insert after that node
    {
        start -> next = newnode;//next of start node will point to newnode
        newnode -> next = NULL;//next of newnode will point to NULL as it is the last node now
        return;
    }

    post = temp ->next;//post points to node after node containing value val
    temp ->next = newnode;//make next of node containing value val point to newnode
    newnode -> next = post;//make next of newnode point to post so its ... -> [temp] -> [newnode] -> [post] -> ...
}

void delete_node()
{
    struct node *temp ,*p,*post;
    int val;
    printf("enter the value to be deleted");//enter the value to be deleted
    scanf("%d",&val);

    temp = start;// temp will point to the node containing value val initially at start
    p = start;// p will point to the node previous to the node containing value val initially at start

    while(temp!=NULL && temp->data !=val)//while end of linked list is not reached and node containing value val is not found . goes till one node less but temp is storing next so at last iteration temp will point to node containing value val
    {
        p = temp; //pointing to previous node
        temp = temp -> next;//pointing to node containing value val
    }

    if(temp == start)//if the node to be deleted is the start node
    {
        start = temp->next;//make start point to next of start node
        free(temp);//free the memory allocated to start node
    }
    else if(temp == NULL)//if null so all nodes traversed and value not found
    {
        printf("value not found");
    }
    else //if the node to be deleted is any node other than start node 
    {
        post = temp -> next;//store the address of node after node containing value val in post
        p -> next = post; //make next of previous node point to post bypassing node containing val ,  so its ... -> [p] -> [post] -> ...
        free(temp);//free the memory allocated to node containing value val
    }
}

void display_and_count()
{
    struct node *temp;
    temp = start;
    int count = 0;
    while(temp ->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        count+=1;
    }
    printf("%d",temp->data);
    count+=1;
    printf("\n");
    printf("no of nodes = %d",count);
    printf("\n");
}

void main()
{
    int choice,yes =1;

    while(yes)
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

/*void create_LL(){ depricated method.. inefficient due to linked list traversal for every new node

    start = NULL;
    
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
}*/























