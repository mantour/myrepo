#include <cstdio>
#include <algorithm>
using namespace std;
class box
{
    int dim, edges[10];
public:
    box *parent;
    void init(int);
    int get_edge(int);
    bool operator< (box);
};

void box::init(int n)
{
    dim=n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",edges+i);
    }
    partial_sort(edges,edges+n-1,edges+10);
}

int box::get_edge(int x)
{
    return edges[x];
}

bool box::operator<(box a)
{
    for(int i=0;i<dim;i++)
    {
        if(edges[i]>=a.get_edge(i))
            return false;
    }
    return true;
}

int main()
{
    box boxset[30];
    int m,n;
    while(scanf("%d %d",&m,&n)==2)
    {
        for(int i=0;i<m;i++)
        {
            boxset[i].init(n);
        }
        sort("%d %d")
    }
}
