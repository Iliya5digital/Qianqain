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
int n,a[N],q;
set<int>odd;
signed main(){
	int T=read();
	while(T--){
		n=read();q=read();
		int sum=0;odd.clear();
		for(int i=1;i<=n;i++){
		  a[i]=read();sum+=a[i];
		  if(a[i]==1)odd.insert(i);
	    }
		for(int i=1;i<=q;i++){
			int op=read();
			if(op==1){
				int s=read(),p=sum,nd=sum-s;
				if(!odd.empty()){
					auto itb=odd.begin();
					auto ite=--odd.end();
					p=min(2*((*itb)-1),2*(n-(*ite)));
				}
				if(nd<0){
					printf("NO\n");
					continue;
				}
				if(nd==0){
					printf("YES\n");
					continue;
				}
				if(p%2!=nd%2&&nd<p)printf("NO\n");
				  else printf("YES\n");
			}
			else{
				int u=read(),v=read();
				if(a[u]==v)continue;
				if(v==1)odd.insert(u);
				else odd.erase(u);
				sum+=v-a[u];a[u]=v;
			}
		}
	}
	return 0;
}
