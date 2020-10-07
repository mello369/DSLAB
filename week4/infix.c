#include <stdio.h>
#include<string.h>
void strrev (char array[20])
{

  int i, j;
  char temp[100];
  for (i = strlen (array) - 1, j = 0; i + 1 != 0; --i, ++j)
    {
      temp[j] = array[i];
    }
  temp[j] = '\0';
  strcpy (array, temp);

}
int F(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':return 1;
        case '/':
        case '*':return 3;
        case '^':
        case '$':return 6;
        case ')':return 0;
        case '#':return -1;
        default:return 8;
    }
}
int G(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':return 2;
        case '/':
        case '*':return 4;
        case '^':
        case '$':return 5;
        case '(':return 0;
        case ')':return 9;
        default:return 7;
    }
}
void infix_prefix(char infix[],char prefix[])
{
    int top=-1,j=0,i;
    char s[30];
    char symbol;
    s[++top]='#';
    strrev(infix);
    for(i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        while(F(s[top])>G(symbol))
        {
            if(s[top]!='(' && s[top] !=')')
            prefix[j++]=s[top--];
			else
			top--;
        }
        if(F(s[top])!=symbol)
            s[++top]=symbol;
        else
            top--;
    }
    while(s[top]!='#')
    {
        if(s[top]!='(' && s[top] !=')')
        prefix[j++]=s[top--];
        else
        top--;
    }
    prefix[j]='\0';
   strrev(prefix);
   printf("Prefix expression:\n %s",prefix);
}

int main()
{
    char infix[20];
    char prefix[20];
    printf("Enter infix expression:\n");
    scanf("%s",infix);
    infix_prefix(infix,prefix);
    return 0;
}
