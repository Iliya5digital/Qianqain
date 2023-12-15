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
int n,a[N],b[N];
signed main(){
	int T=read();
	while(T--){
		n=read();int num1=0,num2=0;
		int pos_1=0,pos_2=0;
		for(int i=1;i<=n;i++){
			a[i]=read();b[n-i+1]=a[i];
			if(i!=1){
				if(a[i]>a[i-1])num1++,pos_1=i;
				if(a[i]<a[i-1])num2++,pos_2=i;
			}
		}
		int Min=INT_MAX;
		if(num1==0)Min=min(Min,1);
		  else if(num1==1&&a[n]>=a[1])Min=min(Min,n-pos_1+1+1);
		if(num2==0)Min=min(Min,0);
		  else if(num2==1&&a[n]<=a[1])Min=min(Min,n-pos_2+1);
		num1=0;num2=0;pos_1=0;pos_2=0;
		for(int i=2;i<=n;i++){
			if(b[i]>b[i-1])num1++,pos_1=i;
			if(b[i]<b[i-1])num2++,pos_2=i;
		}
		if(num1==0)Min=min(Min,2);
		  else if(num1==1&&b[n]>=b[1])Min=min(Min,n-pos_1+1+1+1);
		if(num2==0)Min=min(Min,1);
		  else if(num2==1&&b[n]<=b[1])Min=min(Min,n-pos_2+1+1);
		printf("%d\n",Min==INT_MAX?-1:Min);
	}
	return 0;
}
