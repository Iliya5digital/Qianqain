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
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int n,a[N];
map<int,int>b;
signed main(){
	int T=read();
	while(T--){
		n=read();b.clear();
		for(int i=1;i<=n;i++)
		  a[i]=read(),b[a[i]]=1;
		if(n==1){
			printf("1\n");
			continue;
		}
		sort(a+1,a+n+1);
		int x=a[n]-a[1];
		for(int i=2;i<n;i++)
		  x=gcd(x,a[n]-a[i]);
		long long sum=0;
		for(int i=1;i<n;i++)
		  sum=sum+(a[n]-a[i])/x;
		int a_n1=a[n];
		while(b[a_n1]){
			a_n1-=x;
			sum++;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
