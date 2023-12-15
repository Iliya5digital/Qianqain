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
char s[N];int n,a[N],c[N];
vector<int>b[N],e,ans,bl;
bool v[N],g[N];
stack<int>st;
void dfs1(int x){
	if(v[x]){
		e.clear();e.push_back(x);
		while(st.top()!=x)
		  e.push_back(st.top()),st.pop();
		return ;
	}
	st.push(x);v[x]=1;dfs1(a[x]);
}
void dfs2(int x){
	for(auto y:b[x]){
		if(g[y])continue;
		g[y]=1;dfs2(y);
		if(c[y]){
			c[y]=0;c[x]^=1;
			ans.push_back(y);
		}
	}
}
int main(){
	int T=read();
	while(T--){
		n=read();scanf("%s",s+1);
		ans.clear();bool flag=1;
		for(int i=1;i<=n;i++)b[i].clear();
		for(int i=1;i<=n;i++){
			a[i]=read();
			v[i]=g[i]=0;
			b[a[i]].push_back(i);
			c[i]=s[i]-'0';
		}
		for(int i=1;i<=n;i++){
			if(g[i])continue;
			while(!st.empty())
			  st.pop();dfs1(i);
			for(auto x:e)g[x]=1;
			for(auto x:e)dfs2(x);
			bl.clear();
			for(int i=0;i<e.size();i++){
			  if(c[e[i]]==1)bl.push_back(i);
		    }
			if(bl.size()&1){
				flag=0;break;
			}
			if(bl.size()==0)continue;
			int an1=0,an2=0,st;
			for(int j=0;j+1<bl.size();j+=2)
			  an1+=bl[j+1]-bl[j];
			for(int j=1;j+1<bl.size();j+=2)
			  an2+=bl[j+1]-bl[j];
			an2+=e.size()-bl[bl.size()-1]+bl[0];
			if(an1<an2)st=0;
			  else st=1;
			for(int i=bl[st];i<e.size();i++)
			  if(c[e[i]]){
			  	c[e[i]]=0;c[e[(i+1)%e.size()]]^=1;
			  	ans.push_back(e[(i+1)%e.size()]);
			  }
			for(int i=0;i<bl[st];i++)
			  if(c[e[i]]){
			  	c[e[i]]=0;c[e[(i+1)%e.size()]]^=1;
			  	ans.push_back(e[(i+1)%e.size()]);
			  }
		}
		if(!flag){
			printf("-1\n");
			continue;
		}
		printf("%d\n",ans.size());
		for(auto A:ans)printf("%d ",A);
		printf("\n");
	}
	return 0;
}
