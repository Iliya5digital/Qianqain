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
const int N=1010;
int a[N],b[N][N],n;
signed main(){
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=0;
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=n;j++)
		    b[i][j]=read();
		for(int k=0;k<=29;k++){
			bool flag=0;int u;
			for(int i=1;i<=n;i++){
				for(int j=1;j<i;j++)
				  if((b[i][j]>>k&1)==0){
				  	u=i;flag=1;break;
				  }
				if(flag)break;
			}
			if(!flag){
				for(int i=1;i<=n;i++)
				  a[i]+=(1<<k);
				continue;
			}
			for(int i=1;i<=n;i++)
			  if(i!=u&&(b[u][i]>>k&1))a[i]+=(1<<k);
		}
		bool flag=0; 
		for(int i=1;i<=n;i++){
		  for(int j=1;j<i;j++)
		    if(b[i][j]!=(a[i]|a[j])){
				flag=1;break;
			}
		  if(flag)break;
		}
		if(flag){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i<=n;i++)
		  printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}
