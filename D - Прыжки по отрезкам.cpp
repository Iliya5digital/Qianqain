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
int n,l[N],r[N];
bool check(int x){
	int L=0,R=0;
	for(int i=1;i<=n;i++){
		R+=x;L-=x;
		if(R>r[i])R=r[i];
		if(L<l[i])L=l[i];
		if(R<l[i]||L>r[i])return 0;
	}
	return 1;
}
signed main(){
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)
		  l[i]=read(),r[i]=read();
		int l=0,r=1e9;
		while(l<r){
			int mid=l+r>>1;
			if(check(mid))r=mid;
			  else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
