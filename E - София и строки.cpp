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
int n,m;char s[N],t[N];
queue<int>e[30];
bool flag;
int main(){
	int T=read();
	while(T--){
		n=read();m=read();
		scanf("%s",s+1);
		scanf("%s",t+1);flag=1;
		for(int i=0;i<='z'-'a';i++)
		  while(!e[i].empty())e[i].pop();
		for(int i=1,j=1;i<=m;i++){
			int nd=t[i]-'a';
			if(e[nd].empty()){
				for(;j<=n&&s[j]-'a'!=nd;j++)
				  e[s[j]-'a'].push(j);
				if(j<=n)
				  e[nd].push(j),j++;
			}
			if(e[nd].empty()){
				flag=0;break;
			}
			int now=e[nd].front();e[nd].pop();
			for(int k=0;k<nd;k++)
			  while(!e[k].empty())
			    if(e[k].front()<now)e[k].pop();
			      else break;
		}
		if(flag)printf("YES\n");
		  else printf("NO\n");
	}
	return 0;
}
