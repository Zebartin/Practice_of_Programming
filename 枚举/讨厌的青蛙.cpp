#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct plant {
	int x;
	int y;
	plant() {}
	plant(int x_,int y_):x(x_),y(y_) {}
};
bool operator<(const plant &p1,const plant &p2) {
	if(p1.x==p2.x)
		return p1.y<p2.y;
	return p1.x<p2.x;
}
int main() {
	int R,C,x,y,N,maxstep=2;
	vector<plant> damaged;
	cin>>R>>C>>N;
	for(int i=0; i<N; ++i) {
		cin>>x>>y;
		damaged.push_back(plant(x,y));
	}
	sort(damaged.begin(),damaged.end());
	for(int i=0; i<N-2; ++i)
		for(int j=i+1; j<N-1; ++j) {
			int dx=damaged[j].x-damaged[i].x,dy=damaged[j].y-damaged[i].y;
			int px=damaged[i].x-dx,py=damaged[i].y-dy;
			if(px>=1&&px<=R&&py>=1&&py<=C)
				continue;
			if(damaged[i].x+maxstep*dx>R)
				break;
			if(damaged[i].y+maxstep*dy<1||damaged[i].y+maxstep*dy>C)
				continue;
			int tmax=2;
			plant tplant(damaged[j].x+dx,damaged[j].y+dy);
			while(tplant.x<=R&&tplant.x>=1&&tplant.y>=1&&tplant.y<=C) {
				if(binary_search(damaged.begin(),damaged.end(),tplant))
					++tmax;
				else
					break;
				tplant.x+=dx;
				tplant.y+=dy;
			}
			if(!(tplant.x<=R&&tplant.x>=1&&tplant.y>=1&&tplant.y<=C))
				maxstep=tmax;
		}
	cout<<(maxstep=(maxstep==2)?0:maxstep)<<endl;
	return 0;
}
