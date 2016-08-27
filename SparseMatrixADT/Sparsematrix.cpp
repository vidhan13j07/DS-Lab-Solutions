#include<bits/stdc++.h>
using namespace std;

class Mat
{
    public:
        int size;
        int row;
        int *col;
        int *val;
};


void create(Mat *,int,int);
void init(Mat *,int,int);
void print(Mat,int,int);
void printSum(Mat,Mat,int,int);
void printMul(Mat,Mat,int);
void transpose(Mat,int,int);


void create(Mat *s,int sz,int r)
{
    s->row=r;
    s->size=sz;
    s->col=new int[sz];
    s->val=new int[sz];
}


void init(Mat *s,int sz)
{
    int c,v;
    for(int j=0;j<sz;j++)
    {
        cout<<"Enter colmn no: ";
        cin>>c;
        cout<<"Enter value: ";
        cin>>v;
        s->col[j]=c;
        s->val[j]=v;
        cout<<"\n\n";
    }
}


void print(Mat s[],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        int k=0;
        for(int j=0;j<c;j++)
        {
            if(j==s[i].col[k])
            {
                cout<<s[i].val[k]<<" ";
                k++;
            }
            else
                cout<<"0 ";
        }
        cout<<"\n";
    }
}


void printSum(Mat s1[],Mat s2[],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        int k1=0;
        int k2=0;
        for(int j=0;j<c;j++)
        {
            if(j==s1[i].col[k1] && j==s2[i].col[k2])
            {
                cout<<s1[i].val[k1]+s2[i].val[k2]<<" ";
                k1++;
                k2++;
            }

            else if(j==s1[i].col[k1])
            {
                cout<<s1[i].val[k1]<<" ";
                k1++;
            }

            else if(j==s2[i].col[k2])
            {
                cout<<s2[i].val[k2]<<" ";
                k2++;
            }
            else
                cout<<"0 ";
        }
        cout<<"\n";
    }
}


void printMul(Mat s1[],Mat s2[],int r)
{
    int i,j,k,l,v,val1,val2;
    for(i=0;i<r;i++)
    {
        for(j=0;j<r;j++)
        {
            v=0;
            for(k=0;k<r;k++)
            {
                val1=0;val2=0;
                for(l=0;l<s1[i].size;l++)
                    if(s1[i].col[l]==k)
                    {
                        val1=s1[i].val[l];
                        break;
                    }
                for(l=0;l<s2[k].size;l++)
                    if(s2[k].col[l]==j)
                    {
                        val2=s2[k].val[l];
                        break;
                    }
                v+=(val1*val2);
            }
            cout<<v<<" ";
        }
        cout<<"\n";
    }
}


void transpose(Mat s[],int r,int c)
{
    int v;
    for(int j=0;j<c;j++)
    {
        for(int i=0;i<r;i++)
        {
            v=0;
            for(int k=0;k<s[i].size;k++)
            {
                if(s[i].col[k]==j)
                {
                    v=s[i].val[k];
                    break;
                }
            }
            cout<<v<<" ";
        }
        cout<<"\n";
    }
}


int main()
{
    int r,n,c;
    cout<<"\nEnter the number of rows and columns matrix\n";
    cin>>r>>c;
    Mat s1[r];
    Mat s2[r];
    for(int i=0;i<r;i++)
    {
        cout<<"\nRow "<<i+1<<": ";
        cout<<"\nNo of not null elements: ";
        cin>>n;
        create(&s1[i],n,r);
        init(&s1[i],n);
    }
    for(int i=0;i<r;i++)
    {
        cout<<"\nRow "<<i+1<<": ";
        cout<<"\nNo of not null elements: ";
        cin>>n;
        create(&s2[i],n,r);
        init(&s2[i],n);
    }
    cout<<"\nMatrix 1: \n";
    print(s1,r,c);
    cout<<"\nMatrix 2: \n";
    print(s2,r,c);
    cout<<"\nSum : \n";
    printSum(s1,s2,r,c);
    if(r!=c)
        cout<<"\nMultiplication cannot be performed\n";
    else
    {
        cout<<"\nMultiplication of the matrices\n";
        printMul(s1,s2,r);
    }
    cout<<"\nTranspose of first matrix is: \n";
    transpose(s1,r,c);
    cout<<"\nTranspose of second matrix is: \n";
    transpose(s2,c,r);
    return 0;
}
