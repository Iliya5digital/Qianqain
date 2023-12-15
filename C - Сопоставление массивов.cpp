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
int n,x,b[N];
struct cow{
	int x,id,y;
}a[N];
bool cmp1(cow A,cow B){
	return A.x>B.x;
}
bool cmp2(cow A,cow B){
	return A.id<B.id;
}
signed main(){
	int T=read();
	while(T--){
		n=read();x=read();
		for(int i=1;i<=n;i++){
			a[i].x=read();
			a[i].id=i;a[i].y=0;
		}
		for(int i=1;i<=n;i++)b[i]=read();
		sort(a+1,a+n+1,cmp1);sort(b+1,b+n+1);
		bool flag=1;
		for(int i=1,r=n;i<=x;i++){
			while(r&&a[r].x<=b[i])r--;
			if(r==0){
				flag=0;break;
			}
			a[r].y=b[i];r--;
		}
		for(int i=1,now=1;i<=n;i++){
			if(a[i].y==0)continue;
			while(now<=i&&a[now].y!=0)now++;
			if(now>=i)continue;
			a[now].y=a[i].y;a[i].y=0;
		}
		for(int i=x+1,r=n;i<=n;i++){
			while(a[r].y!=0)r--;
			if(a[r].x>b[i]){
				flag=0;break;
			}
			a[r].y=b[i];r--;
		}
		if(!flag){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++)
		  printf("%d ",a[i].y);
		printf("\n");
	}
	return 0;
}
