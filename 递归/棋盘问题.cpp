#include <iostream>
#include <string.h>
using namespace std;
const int MAXn=8;
int board[MAXn][MAXn],col[MAXn],ans,n,k;
void place(int row,int now){
    if(now==k){
        ans++;
        return;
    }
    if(k-now>n-row)
        return;
    place(row+1,now);
    for(int i=0;i<n;++i)
        if(!col[i]&&board[row][i]){
            col[i]=1;
            place(row+1,now+1);
            col[i]=0;
        }
}
int main(){
    const int MAXn=8;
    while(cin>>n>>k){
        if(n==-1)
            break;
        ans=0;
        memset(col,0,sizeof col);
        char c;
        for(int i=0;i<n*n;++i){
            cin>>c;
            board[i/n][i%n]=(c=='#')?1:0;
        }
        place(0,0);
        cout<<ans<<endl;
    }
    return 0;
}
