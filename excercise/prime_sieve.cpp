#include<cstdio>
#include<vector>
using namespace std;
vector<int> prime_sieve(int n){
    vector<int> List;
    vector<int>::iterator i1,i2;
    for(int i=2;i<=n;i++){
        List.push_back(i);
    }
    for(i1=List.begin();i1!=List.end();i1++){
        for(i2=i1+1;i2!=List.end();){
            if((*i2)%(*i1)==0){
                i2=List.erase(i2);
            }
            else{
                i2++;
            }
        }
    }
    return List;
}

int main(){
    int n;
    vector<int> prime_list;
    //scanf("%d",&n);
    prime_list=prime_sieve(65536);
    printf("%d\n",prime_list.size());
    return 0;
}
