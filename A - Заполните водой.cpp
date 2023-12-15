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
const int N=1e5+10;
int n;char a[N];
int main(){
	int T=read();
	while(T--){
		n=read();scanf("%s",a+1);
		int ans=0;int flag=0;
		for(int i=1;i<=n;i++){
			if(a[i]=='#')continue;
			int j=i;
			while(a[j]!='#'&&j<=n)j++;
			if(j-i>2)flag=1;
			  else ans+=j-i;
			i=j;
		}
		if(!flag)printf("%d\n",ans);
	      else printf("2\n");
	}
	return 0;
}
