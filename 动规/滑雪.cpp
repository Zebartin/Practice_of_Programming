#include <iostream>
#include <algorithm>
using namespace std;
const int N=100;
int area[N][N];
struct coordinate{
    int x;
    int y;
    coordinate(){}
    coordinate(int _x,int _y):x(_x),y(_y){}
};
bool operator<(const coordinate &c1,const coordinate &c2){
    return area[c1.x][c1.y]<area[c2.x][c2.y];
}
int main(){
    coordinate points[N*N],tmp;
    int R,C,k=0,ans[N][N]={0},dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    cin>>R>>C;
    for(int i=0;i<R;++i)
        for(int j=0;j<C;++j){
            cin>>area[i][j];
            points[k].x=i,points[k++].y=j;
        }
    sort(points,points+R*C);
    ++ans[points[0].x][points[0].y];
    for(int i=1;i<R*C;++i){
        int l=0;
        for(int j=0;j<4;++j){
            tmp.x=points[i].x+dir[j][0],tmp.y=points[i].y+dir[j][1];
            if(tmp.x>=0&&tmp.x<R&&tmp.y>=0&&tmp.y<C&&binary_search(points,points+i,tmp)
               &&area[tmp.x][tmp.y]<area[points[i].x][points[i].y])
                l=max(l,ans[tmp.x][tmp.y]);
        }
        ans[points[i].x][points[i].y]=l+1;
    }
    int m=0;
    for(int i=0;i<R;++i)
        for(int j=0;j<C;++j)
            m=m>ans[i][j]?m:ans[i][j];
    cout<<m<<endl;
    return 0;
}
