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
const int N=1e6+10;
char s[N];int n;bool v[N];
vector<int>lst,LST;
signed main(){
	int T=read();
	while(T--){
		scanf("%s",s+1);int n=strlen(s+1);
		for(int i=1;i<=n;i++)v[i]=1;
		lst.clear();LST.clear();
		for(int i=1;i<=n;i++){
			if(s[i]=='b'){
				v[i]=0;
				if(!lst.empty()){
					v[lst[lst.size()-1]]=0;
					lst.pop_back();
				}
			}
			else if(s[i]=='B'){
				v[i]=0;
				if(!LST.empty()){
					v[LST[LST.size()-1]]=0;
					LST.pop_back();
				}
			}
			else{
				if(s[i]>='a'&&s[i]<='z')lst.push_back(i);
				  else LST.push_back(i);
			}
		}
		for(int i=1;i<=n;i++)
		  if(v[i])printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
