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

int columnSum(int j,int a,int b,int **A){
    /*
     *   return the sum of A[a][j] to A[b][j]
     */
    int sum=0;
    for(int i=a;i<=b;i++){
        sum+=A[i][j];
    }
    return sum;
}

int extend(int N,int j,int **A,int **B){
    /*
     *  B[a][b] is the max sum of boxes from roa a to row b, with right edge at column j
     *  this function extends it to max sum of boxes with right edge at column j+1, and then
     *  return the maximum of B
     */
    int max;
    for(int a=0;a<N;a++){
        for(int b=a;b<N;b++){
            if(B[a][b]<0){
                B[a][b]=0;
            }
            B[a][b]+=columnSum(j,a,b,A);
            if((a==0&&b==0)||B[a][b]>max){
                max=B[a][b];
            }
        }
    }
    return max;
    //printMatrix(N,B);
}

int maxSum(int N,int **A){
    int maxOfAll,max;
    int ** B; 
        //max sum of for right sided boxes from row a to row b
    constructMatrix(N,&B);
    for(int a=0;a<N;a++){
        for(int b=0;b<N;b++){
            B[a][b]=0;
        }
    } // initialize B
    for(int j=0;j<N;j++){
        max=extend(N,j,A,B);
        if(j==0||max>maxOfAll){
            maxOfAll=max;
        }
    } // extend right edge of boxes from j=0 to j=N-1, record the maxSum ever meet
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
