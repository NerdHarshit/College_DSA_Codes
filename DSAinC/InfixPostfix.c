#include<stdio.h>

char infix [] = "a+b*c-d/e";//a+b*c-(d/e+f)%g-h
char postfix[20];

int top = -1;
int max = 20;
char stack[20];
char y;

int priority(char x)
{
    if(x=='%')
    {
        return 3;
    }

    else if(x =='/'|| x=='*')
    {
        return 2;
    }

    else if(x=='+' || x=='-')
    {
        return 1;
    }

    else{
        return 0;
    }
}

void push(char val)
{
    if(top == max-1){
        printf("Stack overflow");
        return;
    }

    top+=1;
    stack[top] = val;
}

char pop()
{
    if(top==-1){
        printf("Stack empty");
        return '\0';
    }

    char lastval = stack[top];
    top-=1;
    return(lastval);
}

void infixTOPostfix()
{
    int i=0,j=0;
    char c;

    while(infix[i]!='\0') 
        {
        c = infix[i];

        if(c>='a'&&c<='z' || c>='0' && c<='9')
        {
            postfix[j] = c;
            j+=1;
        }

        else if(c == '+' || c=='-'||c == '*'||c=='/'||c=='%')
        {
            if(top==-1)
            {
                push(c);
            }

            else if(priority(c)>priority(stack[top]))
            {
                push(c);
            }

            else if(priority(c)<=priority(stack[top]))
            {
                while(top!=-1 && priority(c)<=priority(stack[top]))
                {
                    y = pop();
                    postfix[j] = y;
                    j+=1;
                }
                push(c);
            }
        }

        else if(c =='(')
        {
            push(c);
        }

        else if(c == ')')
        {
            while(stack[top]!='(')
            {
                y = pop();
                postfix[j] = y;
                j+=1;
            }
            y= pop();
        }
        i+=1;
    }

    while(top!=-1)
    {
        postfix[j] = pop();
        j+=1;
    }
}
void main()
{
    //int i;
    infixTOPostfix();
    /*for(i=0;postfix[i]!='\0';i++)
    {
        //printf("%c ",postfix[i]);
        
    }*/
    puts(postfix);
}
