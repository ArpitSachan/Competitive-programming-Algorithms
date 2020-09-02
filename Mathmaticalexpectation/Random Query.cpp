#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll a[10000006];
ll ans[10000006]={0};
int main() {
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	    ll n;
	    cin>>n;
	    ll sum=0;
	    unordered_map<ll, ll>mp;
	    for(ll i=1;i<=n;i++){
	    	cin>>a[i];
	    	ans[i]=ans[i-1]+(i-mp[a[i]]);
	    	mp[a[i]]=i;
	    	sum+=ans[i];
	    }
	    float res;
	    res=(double)(2*sum-n)/(n*n);
	    cout<<res;
	
	return 0;
}
