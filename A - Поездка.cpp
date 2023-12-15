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
const int N=60;
int n,x,a[N];
signed main(){
	int T=read();
	while(T--){
		n=read();x=read();
		for(int i=1;i<=n;i++)
		  a[i]=read();
		int Max=a[1];
		for(int i=2;i<=n;i++)
		  Max=max(Max,a[i]-a[i-1]);
		printf("%d\n",max(Max,(x-a[n])*2));
	}
	return 0;
}
