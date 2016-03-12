#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
	int clock[3][3],oper[9],minoper[9],min=10000,t;
	for(int i=0; i<9; ++i)
		cin>>clock[i/3][i%3];
	for(oper[0]=0; oper[0]<4; ++oper[0])
		for(oper[1]=0; oper[1]<4; ++oper[1])
			for(oper[2]=0; oper[2]<4; ++oper[2]) {
				oper[3]=(4-(clock[0][0]+oper[0]+oper[1])%4)%4;
				oper[4]=(4-(clock[0][1]+oper[0]+oper[1]+oper[2])%4)%4;
				oper[5]=(4-(clock[0][2]+oper[2]+oper[1])%4)%4;
				oper[6]=(4-(clock[1][0]+oper[0]+oper[3]+oper[4])%4)%4;
				oper[7]=(4-(clock[2][0]+oper[3]+oper[6])%4)%4;
				oper[8]=(4-(clock[1][1]+oper[0]+oper[2]+oper[4]+oper[6])%4)%4;
				if(!((clock[1][2]+oper[2]+oper[4]+oper[5]+oper[8])%4)&&
				        !((clock[2][1]+oper[4]+oper[6]+oper[7]+oper[8])%4)&&
				        !((clock[2][2]+oper[5]+oper[7]+oper[8])%4))
					if((t=accumulate(oper,oper+9,0))<min) {
						min=t;
						copy(oper,oper+9,minoper);
					}
			}
	for(int i=0; i<9; ++i)
		for(int j=0; j<minoper[i]; ++j)
			cout<<i+1<<" ";
	cout<<endl;
	return 0;
}
