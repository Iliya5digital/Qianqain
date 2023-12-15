#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define P pair<int,int>
#define M(x,y) make_pair(x,y)
int n,q;char s[N];
map<P,set<int>>a;
P pos[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q>>s+1;P now={};
	pos[0]=now;a[now].insert(0);
	for(int i=1;i<=n;i++){
		if(s[i]=='U')now.second++;
		if(s[i]=='D')now.second--;
		if(s[i]=='L')now.first--;
		if(s[i]=='R')now.first++;
		a[now].insert(i);pos[i]=now;
	}
	for(int i=1;i<=q;i++){
		P q;int l,r;bool flag=0;
		cin>>q.first>>q.second>>l>>r;
		auto it=a[q].lower_bound(0);
		if(it!=a[q].end()&&(*it)<l)flag=1;
		it=a[q].lower_bound(r+1);
		if(it!=a[q].end())flag=1;
		P p=M(pos[l-1].first+pos[r].first-q.first,
		pos[l-1].second+pos[r].second-q.second);
		it=a[p].lower_bound(l-1);
		if(it!=a[p].end()&&(*it)<=r)flag=1;
		if(flag)printf("YES\n");
		  else printf("NO\n");
	}
	return 0;
}
