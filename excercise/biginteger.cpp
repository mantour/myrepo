/* 
 * implimentation of big integer type
 */
#include<iostream>
#include<cstdio>
#include<climits>
#include<sstream>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;
int int_byte(){
    int i=1;
    unsigned long test=ULONG_MAX;
    test/=2;
    while(test){
        i++;
        test/=2;
    }
    return i;
}
const unsigned long base=1<<int_byte()/2;
const int precision=3;
class BigInteger{
    public:
    unsigned long num[precision];
    BigInteger(){
        int i;
        for (i = 0; i < precision; i++) {
            this->num[i]=0;
        }
        return;
    }
    BigInteger(unsigned long n){
        int i=1;
        unsigned long q=n/base,r=n%base;
        this->num[0]=n%base;
        while(q!=0)
        {
            num[i]=q%base;
            q=q/base;
            i++;
        }
        for (; i < precision; i++) {
            num[i] = 0;
        }
        return;
    }
    BigInteger(const BigInteger& n){
        int i;
        for (i = 0; i < precision; i++) {
            this->num[i]=n.num[i];
        }
        return;
    }
    friend BigInteger operator+(const BigInteger a,const BigInteger b);
    friend BigInteger operator-(const BigInteger a,const BigInteger b);
    friend BigInteger mul(const BigInteger a,const unsigned long b,const unsigned long offset);
    friend pair<BigInteger,unsigned long> div(const BigInteger a,const unsigned long b);
    friend BigInteger operator*(const BigInteger a,const BigInteger b);
    static int compare(const BigInteger a,const BigInteger b);
    string toString();
    unsigned long toULong();
};

BigInteger operator+(const BigInteger a,const BigInteger b){
    int i;
    unsigned long sum;
    unsigned long carry=0;
    BigInteger result(0);
    for (i = 0; i < precision; i++) {
        sum=a.num[i]+b.num[i]+carry;
        result.num[i]=sum%base;
        carry=sum/base;
    }
    return result;
}

BigInteger operator-(const BigInteger a,const BigInteger b){
    int i;
    unsigned long dif;
    unsigned long carry=0;
    BigInteger result(0);
    for (i = 0; i < precision; i++) {
        if(a.num[i] >= b.num[i] + carry){
            result.num[i]=a.num[i]-b.num[i]-carry;
            carry=0;
        }else{
            result.num[i]=a.num[i]+base-b.num[i]-carry;
            carry=1;
        }
    }
    return result;
}

BigInteger mul(const BigInteger a,const unsigned long b,const unsigned long offset=0){
    int i;
    unsigned long pro;
    unsigned long carry=0;
    BigInteger result(0);
    for (i = 0; i < precision-offset; i++) {
        pro=b*a.num[i];
        result.num[i+offset]=(pro+carry)%base;
        carry=(pro+carry)/base;
    }
    return result;
}

pair<BigInteger,unsigned long> div(const BigInteger a,const unsigned long b){
    int i;
    unsigned long dividend;
    unsigned long remander=0;
    BigInteger result(0);
    for (i = precision-1; i >= 0 ; i--) {
        dividend=a.num[i]+(base)*remander;
        result.num[i]=dividend/b;
        remander=dividend%b; 
    }
    return pair<BigInteger,unsigned long>(result,remander);
}

int BigInteger::compare(BigInteger a,BigInteger b){
    int i;
    for (i = precision-1; i >= 0 ; i--) {
        if(a.num[i]>b.num[i]){
            return 1;
        }else if(a.num[i]<b.num[i]){
            return -1;
        }
    }
    return 0;
}

string BigInteger::toString(){
    stringstream result;
    string strresult;
    pair<BigInteger,unsigned long> QnR(BigInteger(),0);
    QnR.first=*this;
    while(compare(QnR.first,BigInteger(0)))
    {
        QnR=div(QnR.first,10);
        result<<QnR.second;
    }
    strresult=result.str();
    reverse(strresult.begin(),strresult.end());
    return strresult;
}

unsigned long BigInteger::toULong(){
    return num[0]+num[1]*base;
}

BigInteger operator*(const BigInteger a,const BigInteger b){
    int i;
    BigInteger result(0);
    for (i = 0; i < precision; i++) {
        result=result+mul(a,b.num[i],i);
    }
    return result; 
}

BigInteger bigMul(unsigned long a, unsigned long b){
    BigInteger A(a),B(b);
    return A*B;
}

unsigned long gcd(unsigned long a, unsigned long b){
    if(a<b){
        return gcd(b,a);
    }
    else if(a%b==0){
        return b;
    }
    else{
        return gcd(b,a%b);
    }
}

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


unsigned long isSquare(BigInteger a){
    unsigned long x=1;
    for(;;){
        if(BigInteger::compare(bigMul(x,x),a)==0){
            return x;
        }
        if(BigInteger::compare(bigMul(x,x),a)==1){
            return 0;
        }
        x++;
    }
}

unsigned long isSquare(unsigned long a){
    unsigned long x=1;
    for(;;x++){
        if(x*x==a){
            return x;
        }
        if(x*x>a){
            return 0;
        }
    }
}

int main(){
    cout<<bigMul(1000000,1000000).toString()<<endl;
    return 0;
}
