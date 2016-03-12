#include <iostream>
#include <string.h>
using namespace std;
int matrix[100][100],N;
int MaxSubarray(int *a){
    int b=0,MaxSum=a[0];
    for(int i=0;i<N;++i){
        if(b>0)
            b+=a[i];
        else
            b=a[i];
        MaxSum=MaxSum>b?MaxSum:b;
    }
    return MaxSum;
}
int MaxSubmatrix(){
    int MaxSum=-0x3f3f3f3f,tmp,b[100];
    for(int i=0;i<N;++i){
        memset(b,0,sizeof b);
        for(int j=i;j<N;++j){
            for(int k=0;k<N;++k)
                b[k]+=matrix[j][k];
            tmp=MaxSubarray(b);
            MaxSum=tmp>MaxSum?tmp:MaxSum;
        }
    }
    return MaxSum;
}
int main(){
    cin>>N;
    for(int i=0;i<N*N;++i)
        cin>>matrix[i/N][i%N];
    cout<<MaxSubmatrix()<<endl;
    return 0;
}
