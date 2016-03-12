#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    const int MAX=25;
    int k,missile[MAX],ans[MAX];
    cin>>k;
    for(int i=0;i<k;++i)
        cin>>missile[i];
    ans[0]=1;
    for(int i=1;i<k;++i){
        int m=0;
        for(int j=0;j<i;++j)
            if(missile[j]>=missile[i])
                m=ans[j]>m?ans[j]:m;
        ans[i]=m+1;
    }
    cout<<*max_element(ans,ans+k)<<endl;
    return 0;
}
