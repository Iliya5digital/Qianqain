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
struct cow{
	int id,x;
	bool operator <(const cow A)const{
		return x<A.x;
	}
}a[N];
int n,sum[N],ans[N];
signed main(){
	int T=read();
	while(T--){
		n=read();a[n+1].x=0;
		for(int i=1;i<=n;i++)
		  a[i].id=i,a[i].x=read();
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		  sum[i]=sum[i-1]+a[i].x;
		int lst=n-1;sum[n+1]=0;
		for(int i=n;i;i--){
			if(sum[i]<a[i+1].x)lst=i-1;
			ans[a[i].id]=lst;
		}
		for(int i=1;i<=n;i++)
		  printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
