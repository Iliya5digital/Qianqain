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
const int N=3e5+10;
#define ll long long
int a[N],n;ll l[N],r[N];
int main(){
	n=read();ll Min=1e12;
	for(int i=1;i<=n;i++)
	  a[i]=read();
	for(int i=1;i<=n;i++)
	  l[i]=max(l[i-1],1ll*a[i])+1;
	for(int i=n;i;i--)
	  r[i]=max(r[i+1],1ll*a[i])+1;
	for(int i=1;i<=n;i++)
	  Min=min(Min,max(max(l[i-1]+(n-i),r[i+1]+(i-1)),1ll*a[i]));
	printf("%lld",Min);
	return 0;
}
