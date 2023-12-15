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
const int N=110;
int n;char s[N];
signed main(){
	int T=read();
	while(T--){
		n=read();bool flag=0;
		scanf("%s",s+1);
		for(int i=2;i<=n;i++)
		  if(s[i]!=s[i-1])flag=1;
		if(flag||s[1]=='0')printf("YES\n");
		  else printf("NO\n");
	}
	return 0;
}
