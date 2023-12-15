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
const int N=30;
int n,m,k,a[N][N],b[N][N];
signed main(){
	int T=read();
	while(T--){
		n=read();m=read();k=read();
		int Min=n+m-2;
		if(Min%2!=k%2||Min>k){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i<=3;i++){
			for(int j=1;j<3;j++)
			  a[i][j]=0;
		}
		for(int i=1;i<3;i++){
			for(int j=1;j<=3;j++)
			  b[i][j]=1;
		}
		for(int i=3;i<m;i++)
		  a[3][i]=1-a[3][i-1];
		int lst=a[3][m-1];
		for(int i=3;i<n;i++)
		  b[i][m]=1-lst,lst=1-lst;
		if(k-Min%4!=0){
			lst=1;
			for(int i=3;i<n;i++)
			  b[i][1]=1-lst,lst=1-lst;
			for(int i=1;i<m;i++)
			  a[n][i]=1-lst,lst=1-lst;
	    }
		for(int i=1;i<=n;i++){
			for(int j=1;j<m;j++)
			  if(a[i][j])printf("R ");
			    else printf("B ");
			printf("\n");
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<=m;j++)
			  if(b[i][j])printf("R ");
			    else printf("B ");
			printf("\n");
		}		
	}
	return 0;
}
