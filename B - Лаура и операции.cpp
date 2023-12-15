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
bool check(int a,int b,int c){
	if(b>c)swap(b,c);
	if((c-b)&1)return 0;
	if(b!=c&&a==0)return 0;
	return 1;
}
int a,b,c;
int main(){
	int T=read();
	while(T--){
		a=read();b=read();c=read();
		printf("%d %d %d\n",check(a,b,c),check(b,a,c),check(c,a,b));
	}
	return 0;
}
