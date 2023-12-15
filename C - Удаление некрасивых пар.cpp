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
int n,a[N];char s[N];
signed main(){
	int T=read();
	while(T--){
		n=read();scanf("%s",s+1);
		for(int i='a';i<='z';i++)
		  a[i]=0;
		for(int i=1;i<=n;i++)
		  a[s[i]]++;
		int Max=0;
		for(int i='a';i<='z';i++)
		  Max=max(Max,a[i]);
		if(Max<=n/2){
			if(n&1)printf("1\n");
			  else printf("0\n");
		}
		else{
			printf("%d\n",Max-(n-Max));
		}
	}
	return 0;
}
