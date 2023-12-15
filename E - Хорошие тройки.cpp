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
int n;long long ans;
signed main(){
	int T=read();
	while(T--){
		n=read();ans=1;
		while(n!=0){
			int now=n%10;now++;
			ans=ans*(1+now)*now/2;
			n/=10;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
