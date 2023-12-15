#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
#define int long long
int read(){
	int num=0;bool flag=1;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar())
	  if(c=='-')flag=0;
	for(;c>='0'&&c<='9';c=getchar())
	  num=(num<<1)+(num<<3)+c-'0';
	return flag?num:-num;
}
int n,a[N],k;
set<int>s;
signed main(){
	int T=read();
	while(T--){
		n=read();k=read();
		s.clear();bool flag=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(s.find(a[i])!=s.end())flag=1;
			else s.insert(a[i]);
		}
		if(flag){
			printf("0\n");
			continue;
		}
		sort(a+1,a+n+1);
		if(k>=3){
			printf("0\n");
			continue;
		}
		if(k==1){
			int Min=a[1];
			for(int i=1;i<n;i++)
			  Min=min(Min,a[i+1]-a[i]);
			printf("%lld\n",Min);
			continue;
		}
		int Min=a[1];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int u=a[j]-a[i];Min=min(Min,u);
			    auto it=s.lower_bound(u);
			    if(it!=s.end())Min=min(Min,(*it)-u);
			    if(it!=s.begin())Min=min(Min,u-(*(--it)));
			}
		}
		printf("%lld\n",Min);
	}
	return 0;
}
