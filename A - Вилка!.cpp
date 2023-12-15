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
int a,b,xk,yk,xq,yq;
map<pair<int,int>,int>mp;
int dx[4]={1,1,-1,-1},dy[4]={1,-1,1,-1};
signed main(){
	int T=read();
	while(T--){
		mp.clear();int ans=0;
		a=read();b=read();
		xk=read();yk=read();
		xq=read();yq=read();
		for(int i=0;i<4;i++)
		  mp[make_pair(xk+dx[i]*a,yk+dy[i]*b)]++;
		swap(a,b);
		for(int i=0;i<4;i++)
		  mp[make_pair(xk+dx[i]*a,yk+dy[i]*b)]++;
		swap(a,b);
		for(int i=0;i<4;i++)
		  if(mp[make_pair(xq+dx[i]*a,yq+dy[i]*b)])ans++,mp[make_pair(xq+dx[i]*a,yq+dy[i]*b)]=0;
		swap(a,b);
		for(int i=0;i<4;i++)
		  if(mp[make_pair(xq+dx[i]*a,yq+dy[i]*b)])ans++;
		printf("%d\n",ans);
	}
	return 0;
}
