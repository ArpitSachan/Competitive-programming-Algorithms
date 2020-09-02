#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define pb push_back
#define mod 1000000000
#define pll pair<ll, ll>
#define mk make_pair


void factors(ll n){
	vector<pll> v;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			ll count=1;
			while(n%i==0){
				n/=i;
				count++;
			}
			v.pb(mk(i, count));
		}
	}
	if(n!=1) v.pb(mk(n, 1));

	for(ll i=0;i<v.size();i++){
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}
}
int main(){

	#ifndef ONLINE_JUDGE
	    freopen("in2.txt", "r", stdin);
	    freopen("out2.txt", "w", stdout);
	#endif
	ll n;
	cin>>n;
	factors(n);
	return 0;
}


