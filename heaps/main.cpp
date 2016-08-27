#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
class heap
{
    public:
        int val;
        int index;
};
heap hp[N];
int h=1;

void heapify(int i)
{
    if(i==1)
        return ;
    int root=i/2;
    if(hp[root].val>hp[i].val)
    {
        swap(hp[root],hp[i]);
        heapify(root);
    }
}

void buildheap(int i)
{
    int ind=i;
    if(2*i<h and hp[2*i].val<hp[ind].val)
        ind=2*i;
    if(2*i+1<h and hp[2*i+1].val<hp[ind].val)
        ind=2*i+1;
    if(ind!=i)
    {
        swap(hp[i],hp[ind]);
        buildheap(ind);
    }
}

heap delfromheap()
{
    heap ans=hp[1];
    hp[1]=hp[h-1];
    h--;
    buildheap(1);
    return ans;
}

int main()
{
    int n,k;
    printf("Enter the number of subarrays\n");
    scanf("%d",&k);
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    int ar[k+1][n+1],ans[n*k+5];
    int ind[k+1];
    for(int i=1;i<=k;i++)
    {
        printf("Enter the elements of the %d subarray\n",i);
        for(int j=1;j<=n;j++)
            scanf("%d",&ar[i][j]);
        ind[i]=2;
    }
    for(int i=1;i<=k;i++)
    {
        hp[h].val=ar[i][1];
        hp[h].index=i;
        heapify(h);
        h++;
    }
    int x=1;
    while(x<=n*k)
    {
        heap t=delfromheap();
        ans[x]=t.val;
        if(ind[t.index]<=n)
        {
            hp[h].val=ar[t.index][ind[t.index]];
            hp[h].index=t.index;
            heapify(h);
            ind[t.index]++;
            h++;
        }
        x++;
    }
    printf("The final array is :");
    for(int i=1;i<=n*k;i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
