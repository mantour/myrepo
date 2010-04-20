#include <stdio.h>
int lenth(int n){
	int count=1;
	while(n>1){
		if(n%2==0){
			n=n/2;
			}
		else{
			n=3*n+1;
			}
		count++;
		}
	return count;
	}
int maxlenth(int i,int j){
	int n,tmp;
	tmp=lenth(i);
	for(n=i+1;n<=j;n++){
		if(lenth(n)>tmp){
			tmp=lenth(n);
			}
		}
	return tmp;
	}
int main(){
	int i,j,m,n,tmp;
	while(scanf("%d %d",&i,&j)==2){
		if(i>j){
			m=j;
			n=i;
			}
		else{
			m=i;
			n=j;
			}
		printf("%d %d %d\n",i,j,maxlenth(m,n));
		}
	return 0;
	}

