/*
 *  ACM 107 (AC)
 */
#include<cstdio>
#include<utility>
using namespace std;

pair<int,int> solve(int H,int X){
    int N,n,h,x;
    for(N=0;;N++){
        h=1;
        x=1;
        for(n=0;h<=H&&x>0;n++,h*=(N+1),x*=N){
            if(h==H&&x==X){
                return pair<int,int>(N,n);
            }
        }
    }
}


int main(){
    int H,X;
    while(scanf("%d %d",&H,&X)==2){
        if(H==0&&X==0){
            break;
        }
        pair<int,int> Nn;
        Nn = solve(H,X);
        printf("%d %d\n",Nn.first>1?(X-1)/(Nn.first-1):Nn.second,H*(Nn.first+1)-X*Nn.first);
    }
    return 0;
}
