#include "ch.h"
#include<stdio.h>
#include<stdlib.h>

str * Substring(str *s,int a,int b)
{
    a--;b--;
    str *temp;
    temp = (str *)malloc(sizeof(str));
    temp->ch=(char *)malloc((b-a+2)*sizeof(char));
    for(int i=a,k=0;i<=b;i++,k++)
        temp->ch[k]=s->ch[i];
    return temp;
}

char Character(str *s,int ind)
{
    ind--;
    return s->ch[ind];
}

str * Concatenate(str *s1,str *s2)
{
    str *temp;
    temp = (str *)malloc(sizeof(str));
    temp->ch=(char *)malloc(400*sizeof(char));
    int i=0,k=0;
    while(s1->ch[i]!='\0')
    {
        temp->ch[k]=s1->ch[i];
        i++;
        k++;
    }
    i=0;
    while(s2->ch[i]!='\0')
    {
        temp->ch[k]=s2->ch[i];
        i++;
        k++;
    }
    return temp;
}

int PatternMatch(str *s1,str *s2)
{
    int sz1=0,sz2=0,i,j,k,ind=-1;
    while(s1->ch[sz1]!='\0')
        sz1++;
    while(s2->ch[sz2]!='\0')
        sz2++;
    for(i=0;i<sz1;i++)
    {
        if(s1->ch[i]==s2->ch[0])
        {
            for(j=i+1,k=1;j<sz1 && k<sz2;j++,k++)
                if(s1->ch[j]!=s2->ch[k])
                    break;
            if(k==sz2)
            {
                ind=i;
                break;
            }
        }
    }
    return ind+1;
}

str * ChangeChar(str *s,int ind,char c)
{
    ind--;
    s->ch[ind]=c;
    return s;
}
