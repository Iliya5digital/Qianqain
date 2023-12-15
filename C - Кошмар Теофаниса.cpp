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
#define ll long long
const int N=1e5+10;
ll sum[N];int a[N],n;
int main(){
	int T=read();
	while(T--){
		n=read();sum[n+1]=0;
		for(int i=1;i<=n;i++)
		  a[i]=read();
		for(int i=n;i;i--)
		  sum[i]=sum[i+1]+a[i];
		ll now=sum[1];
		for(int i=2;i<=n;i++)
		  if(sum[i]>0)now+=sum[i];
		printf("%lld\n",now);
	}
	return 0;
}
