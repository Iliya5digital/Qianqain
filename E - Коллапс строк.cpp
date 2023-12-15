#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,len;long long ans;string s[N];
struct Trie{
	int nxt[N][26],tot,SIZE[N][26];
	void inst(int id){
		int p=0;
		for(int i=0;i<len;i++){
			int now=s[id][i]-'a';
			if(!nxt[p][now])
			  nxt[p][now]=++tot;
			SIZE[p][now]++;
			p=nxt[p][now];
		}
	}
	void ask(int id){
		int p=0;
		for(int i=len-1;i>=0;i--){
			int now=s[id][i]-'a';
			if(!nxt[p][now])break;
			ans-=SIZE[p][now];
			p=nxt[p][now];
		}
	}
}T;
signed main(){
	ios::sync_with_stdio(false); 
	cin.tie(0);cout.tie(0);cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];len=s[i].size();
		T.inst(i);ans+=1ll*n*len;
	}
	for(int i=1;i<=n;i++){
		len=s[i].size();
		T.ask(i);
	}
	cout<<ans*2;
	return 0;
}
