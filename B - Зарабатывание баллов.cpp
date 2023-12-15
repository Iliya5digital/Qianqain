#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int num=0;bool flag=1;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar())
	  if(c=='-')flag=0;
	for(;c>='0'&&c<='9';c=getchar())
	  num=(num<<1)+(num<<3)+c-'0';
	return flag?num:-num;
}
int n,P,l,t;
signed main(){
	int T=read();
	while(T--){
		n=read();P=read();l=read();t=read();
		int hv=(n-1)/7+1;
		int Sum=2*t+l;
		int Max=hv/2;
		if(Sum*Max>=P){
			int nd=n-P/Sum;
			if(P%Sum!=0)nd--;
			printf("%lld\n",nd);
			continue;
		}
		int sh=P-Sum*Max,nd=n-Max;
		nd--;sh-=l;if(hv&1)sh-=t;
		if(sh<=0){
			printf("%lld\n",nd);
			continue;
		}
		nd=nd-sh/l;
		if(sh%l!=0)nd--;
		printf("%lld\n",nd);
	}
	return 0;
}
