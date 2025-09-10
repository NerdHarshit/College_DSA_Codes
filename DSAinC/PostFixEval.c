#include<stdio.h>
#include<ctype.h>
#define max 100

float stack [max];
char postfix[]="342*+62/3+5%-2-";
int top = -1;
int i =0;

void push(float val)
{
    if(top == max-1){
        printf("Stack overflow");
        return;
    }

    top+=1;
    stack[top] = val;
}

float pop()
{
    if(top==-1){
        printf("Stack empty");
        return 0.0;
    }

    int lastval = stack[top];
    top-=1;
    return(lastval);
}

void postfixEval()
{
    while(postfix[i] !='\0')
    {
        char x = postfix[i];

        if(isdigit(x))
        {
            float p = (float)(x - '0');
            push(p);
        }

        else if(x == '-' || x == '+' || x == '/' || x == '*' || x == '%')
        {
            float res;
            float op2 = pop();
            float op1 = pop();

            switch (x)
            {
            case '+':
                res = op1+op2;
                break;

            case '-':
                res = op1-op2;
                break;
            
            case '*':
                res = op1*op2;
                break;
            
            case '/':
                res = op1/op2;
                break;

            case '%':
                res = (int)op1%(int)op2;
                break;
            
            default:
                printf("error");
                break;
            }

            push(res);
        }

        else{
            printf("Invalid");
        }

        i+=1;
    }
    printf("Ans is %f :",stack[top]);
}

void main()
{
    postfixEval();
}