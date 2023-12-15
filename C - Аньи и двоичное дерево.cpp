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
int n,ls[N],rs[N];char a[N];
int dfs(int x){
	if(!ls[x]&&!rs[x])return 0;
	int Min=INT_MAX;
	if(ls[x])Min=min(Min,(a[x]=='L'?0:1)+dfs(ls[x]));
	if(rs[x])Min=min(Min,(a[x]=='R'?0:1)+dfs(rs[x]));
	return Min;
}
int main(){
	int T=read();
	while(T--){
		n=read();scanf("%s",a+1);
	    for(int i=1;i<=n;i++)
	      ls[i]=read(),rs[i]=read();
	    printf("%d\n",dfs(1));
	}
	return 0;
}
