/* 
 * implementation of biginteger algebra
 */
#include<iostream>
#include<climits>
#include<sstream>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;
int int_byte(){
    int i=1;
    unsigned int test=UINT_MAX;
    test/=2;
    while(test){
        i++;
        test/=2;
    }
    return i;
}
const unsigned int base=1<<int_byte()/2;
const int precision=8;
class BigInteger{
    public:
    unsigned int num[precision];
    BigInteger(){
        int i;
        for (i = 0; i < precision; i++) {
            this->num[i]=0;
        }
        return;
    }
    BigInteger(unsigned n){
        int i=1,q=n/base,r=n%base;
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
    BigInteger add(const BigInteger a,const BigInteger b);
    BigInteger sub(const BigInteger a,const BigInteger b);
    BigInteger mul(const BigInteger a,const unsigned int b,const unsigned int offset);
    pair<BigInteger,unsigned int> div(const BigInteger a,const unsigned int b);
    BigInteger mul(const BigInteger a,const BigInteger b);
    int compare(const BigInteger a,const BigInteger b);
    string str();
};

BigInteger BigInteger::add(const BigInteger a,const BigInteger b){
    int i;
    unsigned int sum;
    unsigned int carry=0;
    BigInteger result(0);
    for (i = 0; i < precision; i++) {
        sum=a.num[i]+b.num[i]+carry;
        result.num[i]=sum%base;
        carry=sum/base;
    }
    return result;
}

BigInteger BigInteger::sub(const BigInteger a,const BigInteger b){
    int i;
    unsigned int dif;
    unsigned int carry=0;
    BigInteger result(0);
    for (i = 0; i < precision; i++) {
        if(a.num[i] >= b.num[i] + carry){
            carry=0;
            result.num[i]=a.num[i]-b.num[i]-carry;
        }else{
            carry=1;
            result.num[i]=a.num[i]+base-b.num[i]-carry;
        }
    }
    return result;
}

BigInteger BigInteger::mul(const BigInteger a,const unsigned int b,const unsigned int offset=0){
    int i;
    unsigned int pro;
    unsigned int carry=0;
    BigInteger result(0);
    for (i = 0; i < precision-offset; i++) {
        pro=b*a.num[i];
        result.num[i+offset]=(pro+carry)%base;
        carry=(pro+carry)/base;
    }
    return result;
}

pair<BigInteger,unsigned int> BigInteger::div(const BigInteger a,const unsigned int b){
    int i;
    unsigned int dividend;
    unsigned int remander=0;
    BigInteger result(0);
    for (i = precision-1; i >= 0 ; i--) {
        dividend=a.num[i]+(base)*remander;
        result.num[i]=dividend/b;
        remander=dividend%b; 
    }
    return pair<BigInteger,unsigned int>(result,remander);
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

string BigInteger::str(){
    stringstream result;
    string strresult;
    pair<BigInteger,unsigned int> QnR(BigInteger(),0);
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

BigInteger BigInteger::mul(const BigInteger a,const BigInteger b){
    unsigned int i;
    BigInteger result(0);
    for (i = 0; i < precision; i++) {
        result=BigInteger::add(result,BigInteger::mul(a,b.num[i],i));
    }
    return result; 
}

int main(){
    BigInteger a(UINT_MAX);
    BigInteger b;
    b=a.mul(a,a);
    cout<<a.str()<<endl;
    cout<<b.str()<<endl;
    return 0;
}
