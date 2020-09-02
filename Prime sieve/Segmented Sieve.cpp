#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define pb push_back
#define mod 1000000000
const ll N= 1000000;

vector<ll> primes;
int p[N]={0};

void sieve(){
	for(ll i=2;i<=N;i++){
		if(p[i]==0){
			primes.pb(i);
			for(ll j=i*i;j<=N;j+=i){
				p[j]=1;
			}
		}
	}
}
int main(){

	#ifndef ONLINE_JUDGE
	    freopen("in2.txt", "r", stdin);
	    freopen("out2.txt", "w", stdout);
	#endif
	sieve();
	ll q;
	cin>>q;
	while(q--){
		ll m ,n;
		cin>>m>>n;

		int segement[n-m+1];
		memset(segement, 0, sizeof(segement));
		for(ll i=0;primes[i]*(ll)primes[i]<=n;i++){
			ll st=(m/(primes[i]))*(primes[i]);

			if(st<m) st=st+primes[i];

			for(ll j=st;j<=n;j+=primes[i]){
				segement[j-m]=1;
			}
			if(st==primes[i]) segement[st-m]=0;
		}

		for(ll i=0;i<n-m+1;i++){
			if(segement[i]==0 && (i+m)!=1) cout<<i+m<<endl;
		}
		cout<<endl;
	}
	return 0;
}


