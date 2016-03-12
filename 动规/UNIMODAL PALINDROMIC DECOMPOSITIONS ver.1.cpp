#include <iostream>
#include <string.h>
using namespace std;
int main(){
    const int N=250;
    int figure,last=1,decrease[N][N];
    long long ans[N];
    memset(ans,0,sizeof ans);
    memset(decrease,0,sizeof decrease);
    while(cin>>figure){
        if(!figure)
            break;
        if(last<=figure){
            for(int i=last;i<=figure;++i){
                for(int j=i;j>0;j-=2){
                    if(!decrease[j][i-(i-j)/2]){
                        if(j==i-(i-j)/2) decrease[j][i-(i-j)/2]=1;
                        for(int k=j-1;j-k<=j&&j-k<=i-(i-j)/2-j;--k)
                            decrease[j][i-(i-j)/2]+=decrease[j-k][i-(i-j)/2-j];
                    }
                    ans[i]+=decrease[j][i-(i-j)/2];
                    if(i%2==0){
                        if(!decrease[j/2][i/2]){
                            if(j/2==i/2) decrease[j/2][i/2]=1;
                            for(int k=j/2-1;j/2-k<=j/2&&j/2-k<=i/2-j/2;--k)
                                decrease[j/2][i/2]+=decrease[j/2-k][i/2-j/2];
                        }
                        ans[i]+=decrease[j/2][i/2];
                    }
                }
            }
            last=figure+1;
        }
        cout<<figure<<" "<<ans[figure]<<endl;
    }
    return 0;
}
/*
用decrease[start][sum]表示以start开头、序列和为sum的下降序列个数
则i>=j时，decrease[i][j]=(i==j);
i<j时，decrease[i][j]=decrease[i][j-i]+decrease[i-k][j-i]+…(k>i-j/2)

用ans[sum]表示以sum为序列和的回文单峰序列个数
ans[1]=1,ans[2]=1+decrease[1][1]=2
ans[3]=1+decrease[1][2]=2
ans[4]=1+decrease[2][2]+decrease[2][3]+decrease[1][2]=1+1+1+1=4
ans[5]=1+decrease[3][4]+decrease[1][3]=3
ans[6]=1+decrease[4][5]+decrease[2][4]+decrease[3][3]+decrease[2][3]+decrease[1][3]=1+1+2+1+1+1=7
ans[7]=1+decrease[5][6]+decrease[3][5]+decrease[1][4]=1+1+2+1=5
ans[8]=1+decrease[6][7]+decrease[4][6]+decrease[2][5]+decrease[4][4]+decrease[3][4]+decrease[2][4]+decrease[1][4]=1+1+2+2+1+1+2+1=11
*/
