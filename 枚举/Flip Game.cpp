#include <iostream>
#include <string.h>
using namespace std;
const int N=4;
int board[N+2][N+2],oper[N+2][N+2],minstep=0x3f3f3f3f;
bool judge1(){
    for(int i=2;i<=N;++i)
        for(int j=1;j<=N;++j)
            oper[i][j]=(board[i-1][j]+oper[i-1][j]+oper[i-1][j-1]+oper[i-1][j+1]+oper[i-2][j])%2;
    for(int i=1;i<=N;++i)
        if((board[N][i]+oper[N-1][i]+oper[N][i-1]+oper[N][i+1]+oper[N][i])%2!=0)
            return false;
    return true;
}
bool judge2(){
    for(int i=2;i<=N;++i)
        for(int j=1;j<=N;++j)
            oper[i][j]=!((board[i-1][j]+oper[i-1][j]+oper[i-1][j-1]+oper[i-1][j+1]+oper[i-2][j])%2);
    for(int i=1;i<=N;++i)
        if((board[N][i]+oper[N-1][i]+oper[N][i-1]+oper[N][i+1]+oper[N][i])%2!=1)
            return false;
    return true;
}
int enumerate(){
    int step=-1;
    while(1){
        if(judge1()){
            int sum=0;
            for(int i=1; i<=N; ++i)
                for(int j=1; j<=N; ++j)
                    sum+=oper[i][j];
            if(step==-1||sum<step)
                step=sum;
        }
        if(judge2()){
            int sum=0;
            for(int i=1; i<=N; ++i)
                for(int j=1; j<=N; ++j)
                    sum+=oper[i][j];
            if(step==-1||sum<step)
                step=sum;
        }
        ++oper[1][1];
        int c=1;
        while(oper[1][c]>1){
            oper[1][c]=0;
            ++c;
            if(c<=N)
                oper[1][c]+=1;
            else
                break;
        }
        if(c>N)
            break;
    }
    return step;
}
int main(){
    char c;
    memset(board,0,sizeof board);
    memset(oper,0,sizeof oper);
    for(int i=1;i<=N;++i)
        for(int j=1;j<=N;++j){
            cin>>c;
            board[i][j]=(c=='w')?0:1;
        }
    int t=enumerate();
    if(t+1)
        cout<<t<<endl;
    else
        cout<<"Impossible"<<endl;
    return 0;
}
