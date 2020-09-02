#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define pb push_back
#define mod 1000000000

int sieve(int n){
	int pr[n+1]={0};
	vector<int> primes;
	for(ll i=2;i<=n;i++){
		if(!pr[i]){
			primes.pb(i);
			for(ll j=i;j<=n;j+=i){
				pr[j]++;
			}
		}
	}
	int ans=0;
	for(ll i=2;i<=n;i++){
		if(pr[i]==2) ans++;
	}
	return ans;
}
int main(){

	#ifndef ONLINE_JUDGE
	    freopen("in2.txt", "r", stdin);
	    freopen("out2.txt", "w", stdout);
	#endif
	    
	    ll k;
	cin>>k;
	cout<<sieve(k);
	
	return 0;
}


