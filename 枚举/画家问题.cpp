#include <stdio.h>
#include <memory.h>
using namespace std;
int n,board[16][17],paint[16][17];
bool judge()
{
    for(int i=1; i<n; ++i)
        for(int j=1; j<=n; ++j)
            paint[i+1][j]=(board[i][j]+paint[i][j]+paint[i-1][j]+paint[i][j-1]+paint[i][j+1])%2;
    for(int j=1; j<=n; ++j)
        if(board[n][j]!=(paint[n-1][j]+paint[n][j-1]+paint[n][j]+paint[n][j+1])%2)
            return false;
    return true;
}
int enumerate()
{
    int c,step=-1;
    memset(paint,0,sizeof paint);
    while(1)
    {
        if(judge())
        {
            int sum=0;
            for(int i=1; i<=n; ++i)
                for(int j=1; j<=n; ++j)
                    sum+=paint[i][j];
            if(step==-1||sum<step)
                step=sum;
        }
        ++paint[1][1];
        c=1;
        while(paint[1][c]>1)
        {
            paint[1][c]=0;
            ++c;
            if(c<=n)
                ++paint[1][c];
            else
                break;
        }
        if(c>n)
            break;
    }
    return step;
}
int main()
{
    char c;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
        {
            scanf("%c",&c);
            if(c=='\n')
                scanf("%c",&c);
            board[i][j]=(c=='y')?0:1;
        }
    int t=enumerate();
    if(t+1)
        printf("%d\n",t);
    else
        printf("inf\n");
    return 0;
}
