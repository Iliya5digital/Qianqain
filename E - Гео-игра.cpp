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
#define P pair<int,int>
#define M(x,y) make_pair(x,y)
struct cow{
	struct C{
		P pos;int id;
	};
	void sh(P x,int y){
		a.push_back(C{x,y});
	}
	vector<C>a;int len;
}zer,one;
int n;P st;int z;bool v[N];
signed main(){
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)v[i]=0;
		zer.a.clear();one.a.clear();
		st.first=read();st.second=read();
		for(int i=1;i<=n;i++){
			int x=read(),y=read();
			if(x%2==y%2)zer.sh(M(x,y),i);
			  else one.sh(M(x,y),i);
		}
		one.len=one.a.size();zer.len=zer.a.size();
		if(st.first%2==st.second%2&&zer.len>=one.len)printf("First\n"),z=1;
		  else if(st.first%2!=st.second%2&&zer.len<=one.len)printf("First\n"),swap(zer,one),z=1;
		    else if(st.first%2==st.second%2&&zer.len<one.len)printf("Second\n"),z=0;
		      else if(st.first%2!=st.second%2&&zer.len>one.len)printf("Second\n"),swap(zer,one),z=0;
		fflush(stdout);
		if(zer.len>=one.len)swap(zer,one);
		for(;zer.len!=0||one.len!=0;z^=1){
			if(z){
				if(zer.len){
					printf("%d\n",zer.a[zer.len-1].id);
					v[zer.a[zer.len-1].id]=1;
				}
				else{
					printf("%d\n",one.a[one.len-1].id);
					v[one.a[one.len-1].id]=1;
				}
				fflush(stdout);
			}
			else v[read()]=1,fflush(stdout);
			while(zer.len&&v[zer.a[zer.len-1].id])zer.len--,zer.a.pop_back();
			while(one.len&&v[one.a[one.len-1].id])one.len--,one.a.pop_back();
		}
	}
	return 0;
}
