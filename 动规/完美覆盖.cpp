#include <iostream>
using namespace std;
int WholeSolution[31],BreakSolution[31];
void Solve(int n){
	WholeSolution[0]=1,WholeSolution[1]=0;
	BreakSolution[0]=0,BreakSolution[1]=1;
	for(int i=0;i<n-1;++i){
		WholeSolution[i+2]=i%2?0:WholeSolution[i]+2*BreakSolution[i+1];
		BreakSolution[i+2]=i%2?WholeSolution[i+1]+BreakSolution[i]:0;
	}
}
int main() {
	int n;
	Solve(30);
	while(cin>>n) {
		if(n==-1)
			break;
		cout<<WholeSolution[n]<<endl;
	}
	return 0;
}
