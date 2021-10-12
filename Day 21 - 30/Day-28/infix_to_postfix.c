#include <stdio.h>
#include <conio.h>
#include <string.h>

#define Max 20
char stack[Max];
int top = -1;

void push(char);
char pop();
void convertToPostfix(char [], char[]);
int precd(char);
int isOperator(char);

void main()
{
    char infix[20], postfix[20];

    printf("\n\n\t Infix to Postfix");
    printf("\n\n Enter the Infix Expression: ");
    gets(infix);
    
    convertToPostfix(infix, postfix);
    printf("\n\n The Postfix Expression is: ");
    puts(postfix);
    getch();
}

void push(char exp)
{
    stack[++top] = exp;
}

char pop()
{
    char exp = stack[top--];
    return exp;
}

int precd(char exp)
{
    switch (exp)
    {
        case '(': case ')': case '#': return 1; break;
        case '+': case '-': return 2; break;
        case '*': case '/': return 4; break;
        case '^': return 6; break;
    }
}

int isOperator(char exp)
{
   switch(exp)
   {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(': 
        case ')': return 1; break;
        default: return 0; break;
   }
}

void convertToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    stack[++top] = '#';
    for(i=0;i<strlen(infix);i++)
    {
        if(isOperator(infix[i]) == 0) postfix[j++] = infix[i];
        else
        {
            if(infix[i] == '(') push(infix[i]);
            else if(infix[i] == ')')
            {
                while(stack[top] != '(') postfix[j++] = pop();
                pop();
            }
            else 
            {
                if(precd(infix[i]) > precd(stack[top])) push(infix[i]);
                else
                {
                    while(precd(infix[i]) <= precd(stack[top])) postfix[j++] = pop();
                    push(infix[i]);
                }
            }
        }
    }
    while(stack[top] != '#') postfix[j++] = pop();
    postfix[j] = '\0';
}