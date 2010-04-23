/* 
 * UVA 106 (AC)
 */
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

unsigned long bgcd(unsigned long u, unsigned long v){
     int shift;
     /* GCD(0,x) := x */
     if (u == 0 || v == 0)
       return u | v;
     /* Let shift := lg K, where K is the greatest power of 2
        dividing both u and v. */
     for (shift = 0; ((u | v) & 1) == 0; ++shift) {
         u >>= 1;
         v >>= 1;
     }
     while ((u & 1) == 0)
       u >>= 1;
     /* From here on, u is always odd. */
     do {
         while ((v & 1) == 0)  /* Loop X */
           v >>= 1;
 
         /* Now u and v are both odd, so diff(u, v) is even.
            Let u = min(u, v), v = diff(u, v)/2. */
         if (u < v) {
             v -= u;
         } else {
             unsigned long diff = u - v;
             u = v;
             v = diff;
         }
         v >>= 1;
     } while (v != 0); 
    return u << shift;
}




pair<unsigned long,unsigned long> findtriple(unsigned long N){
    unsigned long x,y,z,m,n,count=0,countdown=N,i;
    char *xyz = new char[N+1];
    memset(xyz,0,N*sizeof(char));
    /*for(i=0;i<N+1;i++){
        xyz[i]=i;
    }*/
    for(n=1;2*n*n<=N;n++){
        for(m=n+1;;m+=2){
            z=m*m+n*n;
            if(z>N){
                break;
            }
            if(bgcd(m,n)!=1){
                continue;
            }
            x=m*m-n*n;
            y=2*m*n;
            count++;
            for(i=1;z*i<=N;i++){
                if(xyz[x*i-1]==0){
                    xyz[x*i-1]=1;
                    countdown--; 
                }
                if(xyz[y*i-1]==0){
                    xyz[y*i-1]=1;
                    countdown--;
                }
                if(xyz[z*i-1]==0){
                    xyz[z*i-1]=1;
                    countdown--;
                }
            }
        }
    }
    delete xyz;
    return pair<unsigned long,unsigned long>(count,countdown);
}

int main(){
    unsigned long N;
    pair<unsigned long,unsigned long> result;
    while(scanf("%lu",&N)==1){
        result=findtriple(N);
        printf("%lu %lu\n",result.first,result.second);
    }
    return 0;
}
