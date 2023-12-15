#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
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
int n,c[N];
signed main(){
	int T=read();
	while(T--){
		n=read();int sum=0;
		for(int i=1;i<=n;i++)
		  c[i]=read();
		for(int i=1;i<=n;i++)
		  if(c[i]>c[i-1])sum+=c[i]-c[i-1];
		printf("%lld\n",sum-1);
	}
	return 0;
}
