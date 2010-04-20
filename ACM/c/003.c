#include <stdio.h>

struct color_num{
	int num;
	char color[4];
	};

void testoutput(int bins[][3]){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d ",bins[i][j]);
			}
		}
	printf("\n");
	}

char color(int i){
	if(i==0){
		return 'B';
		}
	if(i==1){
		return 'C';
		}
	if(i==2){
		return 'G';
		}
	}


int length(int bins[3][3],int i,int j,int k){
	int sum=0,p;
	for(p=0;p<3;p++){
		if(p!=i){
			sum+=bins[0][p];
			}
		if(p!=j){
			sum+=bins[1][p];
			}
		if(p!=k){
			sum+=bins[2][p];
			}
		}
	return sum;
	}

int main(){
	int bins[3][3],i,j,k,c,n;
	struct color_num result; 
	while(scanf("%d %d %d %d %d %d %d %d %d",&bins[0][0],&bins[0][2],&bins[0][1],&bins[1][0],&bins[1][2],&bins[1][1],&bins[2][0],&bins[2][2],&bins[2][1])==9){
		result.num=length(bins,0,1,2);
		result.color[0]='B';
		result.color[1]='C';
		result.color[2]='G';
		result.color[3]=0;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(j==i){
					continue;
					}
				for(k=0;k<3;k++){
					if(k==i||k==j){
						continue;
						}
					if(length(bins,i,j,k)<result.num){
						result.num=length(bins,i,j,k);
						result.color[0]=color(i);
						result.color[1]=color(j);
						result.color[2]=color(k);
						}
					}
				}
			}
		printf("%s %d\n",result.color,result.num);
		}
	return 0;
	}

