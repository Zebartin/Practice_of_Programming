#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    const int N=1000;
    int n,ori[N],ans[N];
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>ori[i];
    ans[0]=ori[0];
    for(int i=1;i<n;++i){
        int m=0;
        for(int j=0;j<i;++j)
            if(ori[j]<ori[i])
                m=m>ans[j]?m:ans[j];
        ans[i]=m+ori[i];
    }
    cout<<*max_element(ans,ans+n)<<endl;
    return 0;
}
