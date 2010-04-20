#include<cstdio>
#include<vector>
using namespace std;
void print(vector<int> a)
{
    int i;
    for(i=2;i<a.size()-2;i++)
    {
        printf("%d ",a[i]);
    }
    printf("%d\n",a[i]);
}

void print_debug(vector<int> a)
{
    int i;
    for(i=0;i<a.size();i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    vector<int> a;
    vector<int> a1;
    a.push_back(0);
    a.push_back(0);
    a.push_back(10001);
    int b[3],i,hr;
    while(scanf("%d %d %d",&b[0],&b[1],&b[2])==3)
    {
        for(i=0;a[i]<b[0];i+=2)
        {
            a1.push_back(a[i]);
            a1.push_back(a[i+1]);
        }
        if(a[i]==b[0])
        {
            hr=a[i+1]>b[1]?a[i+1]:b[1];
            i+=2;
        }
        else
        {
            hr=a[i-1]>b[1]?a[i-1]:b[1];
        }
        if(a1.back()!=hr)
        {
            a1.push_back(b[0]);
            a1.push_back(hr);
        }
        for(;a[i]<b[2];i+=2)
        {
            hr=a[i+1]>b[1]?a[i+1]:b[1];
            if(a1.back()!=hr)
            {
                a1.push_back(a[i]);
                a1.push_back(hr);
            }
        }
        if(a[i]==b[2])
        {
            hr=a[i+1];
            i+=2;
        }
        else
        {
            hr=a[i-1];
        }
        if(a1.back()!=hr)
        {
            a1.push_back(b[2]);
            a1.push_back(hr);
        }
        for(;i<a.size();i++)
        {
            a1.push_back(a[i]);
        }
        a=a1;
        a1.clear();
    }
    print(a);
    return 0;
}
