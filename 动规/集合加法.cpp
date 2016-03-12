#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
void input(int &x){
    scanf("%d",&x);
}
int main(){
    const int N=10000;
    int t,sum,n1,n2,a[N],b[N],tmp[N];
    scanf("%d",&t);
    while(t--){
        unsigned n=0;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        for(int i=0;i<N;++i)
            tmp[i]=-1;
        scanf("%d",&sum);
        scanf("%d",&n1);
        for_each(a,a+n1,input);
        sort(a,a+n1);
        scanf("%d",&n2);
        for_each(b,b+n2,input);
        sort(b,b+n2);
        int j=n2-1;
        for(int i=0;i<n1&&j>=0;++i){
            if(tmp[a[i]-1]==-1){
                int p=0;
                while(a[i]+b[j]>sum)
                    --j;
                if(j>=0&&a[i]+b[j]==sum)
                    for(int k=j;k>=0&&a[i]+b[k]==sum;--k,++p);
                tmp[a[i]-1]=p;
            }
            n+=tmp[a[i]-1];
        }
        printf("%d\n",n);
    }
    return 0;
}
