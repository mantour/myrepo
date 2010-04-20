#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct block{
	int num;
	struct block * next;
	struct block * previous;
	};
struct block * top(struct block * blockx){
	struct block * iterator;
	iterator=blockx;
	while(iterator->next){
		iterator=iterator->next;
		}
	return iterator;
	}
struct block * base(struct block * blockx){
	struct block * iterator;
	iterator=blockx;
	while(iterator->previous){
		iterator=iterator->previous;
		}
	return iterator;
	}
void initialize(struct block * bases[],struct block * blocks[],int n){
	int i;
	for(i=0;i<n;i++){
		bases[i]=(struct block *)malloc(sizeof(struct block));
		blocks[i]=(struct block *)malloc(sizeof(struct block));
		bases[i]->num=-1;
		bases[i]->next=blocks[i];
		bases[i]->previous=NULL;
		blocks[i]->num=i;
		blocks[i]->next=NULL;
		blocks[i]->previous=bases[i];
		}
	}
void parser(char * s,char * p,char * q,int * a,int * b){
	int k=0;
	char * space1, * space2,* space3;
	*p=*s;
	space1=strchr(s,' ');
	space2=strchr(space1+1,' ');
	space3=strchr(space2+1,' ');
	*q=*(space2+2);
	*a=atoi(space1);
	*b=atoi(space3);
	
	}

void output(struct block * base[], int n){
	int i;
	struct block * iterator;
	for(i=0;i<n;i++){

		printf("%d:",i);

		iterator=base[i]->next;
		while(iterator){
			printf(" %d",iterator->num);
			iterator=iterator->next;
			}
		printf("\n");
		}
	}

void uncover(struct block * bases[],struct block * blocks[],int c){
	struct block * iterator, * tmp,* tmp1;
	iterator=top(blocks[c]);
	while(iterator->num!=c){
			tmp=top(bases[iterator->num]);
			tmp1=iterator->previous;
			iterator->previous->next=NULL;
			tmp->next=iterator;
			iterator->previous=tmp;
			iterator=tmp1;
		}
	}

void moveonto(struct block * bases[],struct block * blocks[],int a, int b){
	uncover(bases,blocks,a);
	uncover(bases,blocks,b);
	blocks[a]->previous->next=NULL;
	blocks[a]->previous=blocks[b];
	blocks[b]->next=blocks[a];
	}

void moveover(struct block * bases[],struct block * blocks[],int a,int b){
	uncover(bases,blocks,a);
	moveonto(bases,blocks,a,top(blocks[b])->num);
	}



void pileonto(struct block * bases[],struct block * blocks[],int a,int b){
	int c;
	uncover(bases,blocks,b);
	c=top(blocks[b])->num;
	blocks[a]->previous->next=NULL;
	blocks[a]->previous=blocks[c];
	blocks[c]->next=blocks[a];
	}

void pileover(struct block * bases[],struct block * blocks[],int a,int b){
	int c;
	c=top(blocks[b])->num;
	blocks[a]->previous->next=NULL;
	blocks[a]->previous=blocks[c];
	blocks[c]->next=blocks[a];
	}



int main(){
	int a,b,n,i;
	char s[17],p,q;
	struct block * blocks[24],* bases[24];
	fgets(s,sizeof(s),stdin);
	n=atoi(s);
	initialize(bases,blocks,n);
	for(;;){
		fgets(s,sizeof(s),stdin);
		if(s[0]=='q'){
			break;
			}
		parser(s,&p,&q,&a,&b);
		if(a==b){
			continue;
			}
		if(base(blocks[a])==base(blocks[b])){
			continue;
			}
		if(p=='p'&&q=='v'){
			pileover(bases,blocks,a,b);
			}
		if(p=='p'&&q=='n'){
			pileonto(bases,blocks,a,b);
			}
		if(p=='m'&&q=='v'){
			moveover(bases,blocks,a,b);
			}
		if(p=='m'&&q=='n'){
			moveonto(bases,blocks,a,b);
			}
		}
	output(bases,n);
	return 0;
	}
