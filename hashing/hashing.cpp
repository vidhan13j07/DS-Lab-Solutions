#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=25145;
unsigned int *hash[N];
ll power[50];
class node
{
    public:
        char st[50];
        node * next;
};
node * getNode()
{
    node *p=(node *)malloc(sizeof(node));
    p->next=NULL;
    return p;
}
ll findHash(char a[50])
{
    int n=strlen(a);
    ll h=0;
    int i=0;
    while(i<n)
    {
        ll temp=((int)(a[i]));
        temp*=power[n-i-1];
        if(temp>=N)
            temp%=N;
        h+=temp;
        if(h>=N)
            h%=N;
        i++;
    }
    return h;
}
void pre()
{
    power[0]=1;
    int i=1;
    while(i<50)
    {
        power[i]=power[i-1]*31;
        if(power[i]>=N)
            power[i]%=N;
        i++;
    }
    for(int i=0;i<N;i++)
        hash[i]=NULL;
}
void insert(ll n,char *a)
{
    node *p=getNode();
    strcpy(p->st,a);
    if(hash[n]==NULL)
        hash[n]=(unsigned int *)p;
    else
    {
        node *temp=(node *)hash[n];
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=p;
    }
}
bool query(char *s)
{
    ll n=findHash(s);
    if(hash[n]!=NULL)
    {
        node *temp=(node *)hash[n];
        while(temp!=NULL)
        {
            if(strcmp(temp->st,s)==0)
                return 1;
            temp=temp->next;
        }
    }
    return 0;
}
bool combinations(char *s)
{
    int i=1;
    bool fl=0;
    int l=strlen(s);
    while(i<l)
    {
        swap(s[i],s[i-1]);
        if(query(s))
            if(fl)
                printf("\t\t%s\n",s);
            else
            {
                printf("\n\tSome combinations of the string that are in dictionary are-\n");
                fl=1;
                printf("\t\t%s\n",s);
            }
        swap(s[i],s[i-1]);
        i++;
    }
}
int main()
{
    int q;
    pre();
    fstream fl;
    char temp[50];
    fl.open("dictionary.txt",ios::in | ios::app);
    while(!fl.eof())
    {
        char data[50];
        int i=0;
        char ch;
        while(data[i])
        {
            ch=data[i];
            data[i]=(tolower(ch));
            i++;
        }
        fl.getline(data,50);
        ll n=findHash(data);
        insert(n,data);
    }
    fl.close();
    int c=0;
    for(int i=0;i<N;i++)
        if(hash[i]!=NULL)
            c++;
    //cout<<c<<" "<<N-c<<endl;
    cout<<"\n\tEnter the number of queries\n";
    cin>>q;
    while(q--)
    {
        cout<<"\nEnter the string that you want to query\n";
        cin>>temp;
        int i=0;
        char ch;
        while(temp[i])
        {
            ch=temp[i];
            temp[i]=(tolower(ch));
            i++;
        }
        if(query(temp))
            printf("\n\tFound!The given word is found in the dictionary\n");
        else
        {
            printf("\n\tNot Found!The given does not exist in the dictionary\n");
            combinations(temp);
        }
    }
    return 0;
}
