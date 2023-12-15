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
const int N=8e4+10;
const int M=1e5+10;
int n,a[N],num[M];ll f[M];
void add(int now,int pos){
	f[now]+=(n-pos)*num[now];
	num[now]++;
}
int main(){
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)
		  a[i]=read();
		for(int i=1;i<=M-10;i++)
		  f[i]=num[i]=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int x=1;x<=sqrt(a[i]);x++){
				if(a[i]%x!=0)continue;
				int l=x,r=a[i]/x;
				add(l,i);if(l!=r)add(r,i); 
			}
		}
		ll ans=0;
		for(int i=M-10;i;i--){
			for(int j=i*2;j<M-9;j+=i)
			  f[i]-=f[j];
			ans+=f[i]*i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
