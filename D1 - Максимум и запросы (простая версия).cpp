#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
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
int a[N],n,q,k,v[N];
signed main(){
	n=read();q=read();
	for(int i=1;i<=n;i++)
	  a[i]=read();
	while(q--){
		k=read();int ans=0;
		for(int i=1;i<=n;i++)v[i]=a[i];
		for(int j=60;j>=0;j--){
			int sum=0;
			for(int i=1;i<=n;i++){
				if((v[i]>>j&1)==0)
				  sum+=(1ll<<j)-v[i];
				if(sum>k)break;
			}
			if(sum<=k){
				k-=sum;ans+=(1ll<<j);
				for(int i=1;i<=n;i++)
				  v[i]=max(0ll,v[i]-(1ll<<j));
			}
			for(int i=1;i<=n;i++)
			  if(v[i]>=(1ll<<j))v[i]-=(1ll<<j);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
