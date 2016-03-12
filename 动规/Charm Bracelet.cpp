#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
    int N,M,charm[3500][2],ans[13000];
    cin>>N>>M;
    for(int i=0;i<N;++i)
        cin>>charm[i][0]>>charm[i][1];
    memset(ans,0,sizeof ans);
    for(int i=0;i<N;++i)
        for(int j=M;j>=0;--j)
            if(j-charm[i][0]>=0)
                ans[j]=max(ans[j],ans[j-charm[i][0]]+charm[i][1]);
    cout<<ans[M];
    return 0;
}
