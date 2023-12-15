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
#define ll long long
const int N=1e6+10;
int a[N],n,ans[N],q[N<<1];
struct BIT{
	int c[N<<1];
	#define lowbit(x) (x&-x)
	int getsum(int x){
		int sum=0;
		for(;x;x-=lowbit(x))
		  sum+=c[x];
		return sum;
	}
	void add(int x){
		for(;x<=n*2;x+=lowbit(x))
		  c[x]++;
    }
    void cl(){
    	for(int i=1;i<=n*2;i++)
    	  c[i]=0;
	}
}TT;
int main(){
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=2*n;i++)q[i]=0;
		for(int i=1;i<=n;i++){
		  a[i]=read();
		  if(a[i]>=i)q[a[i]]=i,q[a[i]+n]=i+n;
		    else q[a[i]+n]=i;
		}
		TT.cl();
		for(int r=1;r<=n*2;r++){
			int l=q[r];if(q[r]==0)continue;
			ans[(r-1)%n+1]=r-l-(TT.getsum(r-1)-TT.getsum(l-1));
			TT.add(l);
		}
		for(int i=1;i<=n;i++)
		  printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
