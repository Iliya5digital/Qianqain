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
const int N=20;
int a[N];
signed main(){
	int T=read();
	while(T--){
	  int n=read();
	  for(int i=1;i<=n;i++)
	    a[i]=read();
	  if(a[1]==1)printf("YES\n");
	    else printf("NO\n");
	}
	return 0;
}
