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
char s[10];
signed main(){
	int T=read();
	while(T--){
		scanf("%s",s+1);
		for(int i='a';i<='h';i++)
		  for(int j='1';j<='8';j++){
		  	if(i==s[1]&&j==s[2])continue;
		  	if(i!=s[1]&&j!=s[2])continue;
		  	printf("%c%c\n",char(i),char(j));
		  }
	}
	return 0;
}
