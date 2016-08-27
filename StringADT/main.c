#include<stdio.h>
#include<stdlib.h>
#include "ch.h"
void create(str *a)
{
    a->ch=(char *)malloc(200*sizeof(char));
}
int size(str *a)
{
    int sz=0;
    while(a->ch[sz]!='\0')
        sz++;
    return sz;
}
int main()
{
    int sz1,sz2,temp;
    str *s1,*s2,*s3;
    s1=(str *)malloc(sizeof(str));
    s2=(str *)malloc(sizeof(str));
    s3=(str *)malloc(sizeof(str));
    create(s1);create(s2);create(s3);
    printf("\nEnter the original String \n");
    scanf("%s",s1->ch);
    printf("\nEnter the string to be replaced\n");
    scanf("%s",s2->ch);
    printf("\nEnter the string to replaced with\n");
    scanf("%s",s3->ch);
    sz2=size(s2);
    while(1)
    {
        temp=PatternMatch(s1,s2);
        if(temp==0)
            break;
        sz1=size(s1);
        s1=Concatenate(Concatenate(Substring(s1,1,temp-1),s3),Substring(s1,temp+sz2,sz1));
    }
    printf("\nThe final string is:%s\n",s1->ch);
    return 0;
}
