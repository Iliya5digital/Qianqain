#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int read(){
	int num=0;bool flag=1;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar())
	  if(c=='-')flag=0;
	for(;c>='0'&&c<='9';c=getchar())
	  num=(num<<1)+(num<<3)+c-'0';
	return flag?num:-num;
}
int n,a[N][20],b[N][20];
int ask(int l,int r,bool flag){
	int k=log2(r-l+1);
	if(flag)return max(a[l][k],a[r-(1<<k)+1][k]);
	  else return min(b[l][k],b[r-(1<<k)+1][k]);
}
queue<int>r[N];int l[N];
signed main(){
	int T=read();
	while(T--){
		n=read();bool flag=1;
		for(int i=1;i<=n;i++){
			while(!r[i].empty())r[i].pop();
			l[i]=0;
		}
		for(int i=1;i<=n;i++)a[i][0]=read(),r[a[i][0]].push(i);
		for(int i=1;i<=n;i++)b[i][0]=read();
		for(int j=1;j<20;j++)
		  for(int i=1;i+(1<<j)-1<=n;i++)
		    a[i][j]=max(a[i][j-1],a[i+(1<<j-1)][j-1]),
		    b[i][j]=min(b[i][j-1],b[i+(1<<j-1)][j-1]);
		for(int i=1;i<=n;r[a[i][0]].pop(),l[a[i][0]]=i,i++){
			if(a[i][0]==b[i][0])continue;
			if(a[i][0]>b[i][0]){
				flag=0;break;
			}
			bool If=0;
			if(l[b[i][0]]){
				int u=l[b[i][0]];
				if(ask(u,i,1)==ask(u,i,0))If=1;
			}
			if(!r[b[i][0]].empty()){
				int u=r[b[i][0]].front();
				if(ask(i,u,1)==ask(i,u,0))If=1;
			}
			if(If)continue;
			flag=0;break;
		}
		if(flag)printf("YES\n");
		  else printf("NO\n");
	}
	return 0;
}
