#include <stdio.h>
using namespace std;
int main(){
    const int MAX=35660;
    int k,len=1,ans[MAX]={1};
    scanf("%d",&k);
    for(int i=2;i<=k;++i){
        for(int p=0;p<len;++p)
            ans[p]*=i;
        for(int p=0;p<len;++p)
            if(ans[p]>=10){
                ans[p+1]+=ans[p]/10;
                ans[p]%=10;
            }
        if(ans[len]){
            ++len;
            while(ans[len-1]>=10){
                ans[len]+=ans[len-1]/10;
                ans[len-1]%=10;
                ++len;
            }
        }
    }
    for(int i=len-1;i>=0;--i)
        printf("%d",ans[i]);
    printf("\n");
    return 0;
}
