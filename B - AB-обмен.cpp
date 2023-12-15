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
int n,st;
signed main(){
	int T=read();
	while(T--){
		n=read();long long ans=0;st=0;
		for(int i=1;i<=n;i++){
			char s;
			scanf("%c",&s);
			if(s=='A')st++;
			  else {
			  	ans+=st;
			  	if(st!=0)st=1;
		      }
		}
		printf("%lld\n",ans);
	}
	return 0;
}
