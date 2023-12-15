#include<bits/stdc++.h>
using namespace std;
int read(){
	int num=0;bool flag=1;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar())
	  if(c=='-')flag=0;
	for(;c>='0'&&c<='9';c=getchar())
	  num=(num<<1)+(num<<3)+c-'0';
	return flag?num:-num;
}
const int N=2e5+10;
int n,a[N];
vector<int>e;
signed main(){
	int T=read();
	while(T--){
		n=read();int Max=0;
		for(int i=1;i<=n;i++)
		  a[i]=read();
		sort(a+1,a+n+1);e.clear();
		while(a[1]!=a[n]){
			int op=1;
			if(a[n]&1)op=0;
			e.push_back(op);
			a[n]/=2;a[1]=(a[1]+op)/2;
		}
		printf("%d\n",e.size());
		if(e.size()<=n){
			for(auto x:e){
				printf("%d ",x);
				printf("\n");
			}
		}
	}
	return 0;
}
