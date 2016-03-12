#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int f=0;
struct File {
	string name;
	int level;
	File(string s,int l):name(s),level(l) {}
};
bool operator<(File f1,File f2) {
	return f1.name<f2.name;
}
struct Dir {
	string name;
	int level;
	vector<Dir> dirs;
	vector<File> files;
	Dir(string s="#",int l=0):name(s),level(l) {}
};
Dir inputDir(string s,int l) {
	Dir dir;
	string str;
	cin>>str;
	if(str!="#") {
		dir.name=s;
		dir.level=l;
		while(str!="*"&&str!="]") {
			if(str[0]=='f')
				dir.files.push_back(File(str,l));
			else
				dir.dirs.push_back(inputDir(str,l+1));
			cin>>str;
		}
	}
	return dir;
}
template<class T>
void output(T thing) {
	for(int i=0; i<thing.level; ++i)
		cout<<"|     ";
	cout<<thing.name<<endl;
}
void Fun(Dir dir) {
	output(dir);
	for(int i=0; i<dir.dirs.size(); ++i)
		Fun(dir.dirs[i]);
	sort(dir.files.begin(),dir.files.end());
	for(int i=0; i<dir.files.size(); ++i)
		output(dir.files[i]);
}
int main() {
	int k=1;
	Dir root=inputDir("ROOT",0);
	while(root.name=="ROOT") {
		cout<<"DATA SET "<<k++<<":"<<endl;
		Fun(root);
		cout<<endl;
		root=inputDir("ROOT",0);
	}
	return 0;
}
