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
int n,a[N],b[N];
signed main(){
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)
		  a[i]=read();
		for(int i=1;i<=n;i++)
		  b[i]=read();
		long long ans=0;int r=INT_MAX,l=0;
		for(int i=1;i<=n;i++){
			ans+=abs(a[i]-b[i]);
			r=min(r,max(a[i],b[i]));
			l=max(l,min(a[i],b[i]));
		}
		printf("%lld\n",ans+max(0,2*(l-r)));
	}
	return 0;
} 
