#include <cstdio>
#include <vector>
using namespace std;
class sequence:public vector<int>
{
    public:
        float getCircle();
        float getProduct();
        sequence extent(int);
        sequence(){};
        sequence(int,int);
        static void buildTable(int);
        sequence& operator=(const sequence &y);
        static void printTable();
        static vector<vector<float> > rateTable;
    private:

        float product;
};
vector<vector<float> > sequence::rateTable;



void sequence::printTable()
{
    int i,j;
    for(i=0;i<rateTable.size();i++)
    {
        for(j=0;j<rateTable[i].size();j++)
        {
            printf("%f ",rateTable[i][j]);
        }
        printf("\n");
    }
}
void sequence::buildTable(int n)
{
    vector<float> tmp(n);
    int i,j;
    rateTable.clear();
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            scanf("%f",&tmp[j]);
        }
        tmp[i]=1;
        for(j=i+1;j<n;j++)
        {
            scanf("%f",&tmp[j]);
        }
        rateTable.push_back(tmp);
    }
}

sequence& sequence::operator=(const sequence &y)
{
    this->resize(y.size());
    for(int i=0;i<this->size();i++)
    {
        (*this)[i]=y[i];
    }
    this->product=y.product;
    return *this;
}

float sequence::getProduct()
{
    return product;
}

float sequence::getCircle()
{
    return product*sequence::rateTable[back()-1][front()-1];
}

sequence sequence::extent(int i)
{
    sequence tmp;
    tmp=*this;
    tmp.product=product*rateTable[back()-1][i-1];
    tmp.push_back(i);
    return tmp;
}

sequence::sequence(int i,int n)
{
    int j;
    push_back(i);
    product=1;
}

int main()
{
    vector<sequence> list;
    sequence tmp,result;
    int i,n,flag;
    while(scanf("%d",&n)==1)
    {
        flag=0;
        list.clear();
        sequence::buildTable(n);
        for(i=1;i<=n;i++)
        {
            list.push_back(sequence(i,n));
        }
        while(list.size()>0)
        {
            for(i=list.front()[0];i<=n;i++)
            {
                if(list.front().size()>1&&sequence::rateTable[*(list.front().end()-2)-1][list.front().back()-1]*sequence::rateTable[list.front().back()-1][i-1]<=sequence::rateTable[*(list.front().end()-2)-1][i-1])
                    continue;
                tmp=list.front().extent(i);
                if(tmp.getCircle()>1.01)
                {
                    flag=1;
                    result=tmp;
                    break;
                }
                else if(tmp.size()<n)
                {
                    list.push_back(tmp);
                }
            }
            if(flag==1) break;
            list.erase(list.begin());
        }
        if(flag==1)
        {
            for(i=0;i<result.size();i++)
            {
                printf("%d ",result[i]);
            }
            printf("%d\n",result[0]);
        }
        else
        {
            printf("no arbitrage sequence exists\n");
        }
    }
    return 0;
}
