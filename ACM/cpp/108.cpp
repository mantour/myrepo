/*
 *  ACM 108 (AC)
 */
#include<cstdio>
using namespace std;

void constructMatrix(int N,int ***pA){
    *pA = new int* [N];
    for(int i=0;i<N;i++){
        (*pA)[i]=new int [N];
    }
}

void destructMatrix(int N,int **A){
    for(int i=0;i<N;i++){
        delete [] A[i];
    }
    delete [] A;
}

void readMatrix(int N,int **A){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&A[i][j]);
        }
    }
}

void printMatrix(int N,int **A){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}

int maxSum(int N,int **A){
    int maxOfAll=0;
    int ** B; 
        //max sum of for right sided boxes from row a to row b
    constructMatrix(N,&B);
    for(int a=0;a<N;a++){
        for(int b=0;b<N;b++){
            B[a][b]=0;
        }
    }
    for(int j=0;j<N;j++){
        for(int a=0;a<N;a++){
            for(int b=a;b<N;b++){
                if(B[a][b]<0){
                    B[a][b]=0;
                }
                for(int i=a;i<=b;i++){
                    B[a][b]+=A[i][j];
                }
                if(B[a][b]>maxOfAll){
                    maxOfAll=B[a][b];
                }
            }
        }
        //printMatrix(N,B);
    }
    destructMatrix(N,B);
    return maxOfAll;
}

int main(){
    int N;
    int **A;
    while(scanf("%d",&N)==1){
        constructMatrix(N,&A);
        readMatrix(N,A);
        //printMatrix(N,A);
        printf("%d\n",maxSum(N,A));
        destructMatrix(N,A);
    }
    return 0;
}
