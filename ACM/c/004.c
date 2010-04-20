#include <stdio.h>
struct box
{
	int dimension, * length,num,nop,noc; //num=box number,nop=number of parents,noc=number of childs
	struct box * parents, * childs;
};
typedef struct box box;

void swap(int * a,int * b)
{
	int tmp;
	tmp=*b;
	*b=*a;
	*a=tmp;
}

int partition(int dimension,int * array,int pivotindex)
{
	int i,pivotvalue = *(array+pivotindex),storeindex=0;
	swap(array+pivotindex,array+dimension-1);
	for(i=0;i<dimension;i++)
	{
		printf("pivotvalue=%d\n",pivotvalue);
		printf("*(array+i)=%d\n",*(array+i));
		if((*(array+i))<=pivotvalue)
		{
			printf("do swap\n");
			swap(array+i,array+storeindex);
			storeindex=storeindex+1;
			for(i=0;i<dimension;i++)
			{
				printf("%d ",*(array+i));
			}
		}
	printf("storeindex= %d\n",storeindex);
	}
	swap(array+storeindex,array+dimension-1);
	printf("Storeindex= %d\n",storeindex);
	return storeindex;
}

void sort(int dimension,int * array)
{
	int pivotindex,pivotnewindex,i;
	printf("new array = ");
	for(i=0;i<dimension;i++)
	{
		printf(" %d",*(array+i));
	}
	printf("\n");
	if(dimension>1)
	{
		pivotindex=0;
		pivotnewindex=partition(dimension,array,pivotindex);
		printf("%d\n",pivotnewindex);
		sort(pivotnewindex,array);
		sort(dimension-pivotnewindex-1,array+pivotnewindex+1);
	}
}
int main()
{
	int array[4],i;
	for(i=0;i<4;i++)
	{
		scanf("%d",&array[i]);
	}
	sort(4,array);
	for(i=0;i<4;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	return 0;
}

