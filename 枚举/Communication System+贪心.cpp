#include <iostream>
#include <iomanip>
#include <algorithm>
const int N=101;
using namespace std;
struct device{
    int bandwidth;
    int price;
    device(int bw,int p):bandwidth(bw),price(p){}
};
int main(){
    int t,n,lowest,highest;
    int num[N],bandwidth[N][N],price[N][N];
    cin>>t;
    while(t--){
        lowest=0x3f3f3f3f;
        highest=0;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>num[i];
            for(int j=0;j<num[i];++j){
                cin>>bandwidth[i][j]>>price[i][j];
                lowest=lowest<bandwidth[i][j]?lowest:bandwidth[i][j];
                highest=highest>bandwidth[i][j]?highest:bandwidth[i][j];
            }
        }
        double tmp,ans=0;
        for(int i=lowest;i<=highest;++i){
            int sump=0;
            for(int j=0;j<n;++j){
                int minp=0x3f3f3f3f;
                for(int k=0;k<num[j];++k){
                    if(bandwidth[j][k]>=i&&price[j][k]<minp)
                        minp=price[j][k];
                }
                sump+=minp;
            }
            tmp=double(i)/sump;
            ans=tmp>ans?tmp:ans;
        }
        cout<<fixed<<setprecision(3)<<ans<<endl;
    }
    return 0;
}
