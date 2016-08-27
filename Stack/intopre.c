#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char op[8][2]={{'\0','0'},{'+','2'},{'-','2'},{'/','3'},{'*','3'},{'%','3'},{'^','4'}};
char ch[100],temp1;
char ans[100];
void printStack(stack *s)
{
    for(int i=0;i<s->sz;i++)
        printf("%c ",s->A[i]);
    printf("\n");
}
int main()
{
    int n,t,k1,k2;
    stack *oper,*temp;
    temp=(stack *)malloc(sizeof(stack));
    oper=(stack *)malloc(sizeof(stack));
    create(oper);
    create(temp);
    printf("\nEnter the string to be converted to prefix\n");
    scanf("%s",ch);
    n=strlen(ch);
    for(int i=n-1;i>=0;i--)
    {
        //printf("Character is : %c\n",ch[i]);
        t=(int)(ch[i]);
        if(ch[i]==' ')
            continue;
        if(ch[i]==')')
            push(oper,ch[i]);
        else if(ch[i]=='(')
        {
            int c=0;
	    while(top(oper)!=')')
            {
               push(temp,pop(oper));
               if(c==3)
                   break;
                c++;
            }
            pop(oper);
        }
        else if((t>=65 && t<=91) || (t>=97 && t<=121) || (t>=48 && t<=57))
	    push(temp,ch[i]);
        else
        {
            while(1)
            {
                k1=0;k2=1;
                for(int j=0;j<7;j++)
        	    {
                        if(ch[i]==op[j][0])
                            k1=op[j][1]-'0';
                        if(top(oper)==op[j][0])
		            k2=op[j][1]-'0';
	            }
                if(k1<k2)
                    push(temp,pop(oper));
                else
                    break;
            }
            push(oper,ch[i]);
        }
        //printf("temp : ");
        //printStack(temp);
        //printf("oper : ");
        //printStack(oper);
        //printf("\n");
    }
    int sz=0;
    printf("\nThe prefix form of string is:");
    while(top(oper)!='\0')
        ans[sz++]=pop(oper);
    for(int i=sz-1;i>=0;i--)
    {
        if(ans[i]=='(' || ans[i]==')')
            continue;
        printf("%c",ans[i]);
    }
    while(top(temp)!='\0')
         printf("%c",pop(temp));
    printf("\n");
    return 0;
}
