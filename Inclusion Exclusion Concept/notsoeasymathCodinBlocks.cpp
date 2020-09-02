#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define pb push_back

int main(){
	    int t; cin>>t;
	    ll n;
	    ll primes[8]={2,3,5,7,11,13,17,19};
	    while(t--){
	    	cin>>n;
	    	ll ans=0;
	    	for(ll i=1;i<(1<<8)-1;i++){ // i is binary representation of subset
	    	ll denom = 1ll; // calculate denominator
	    	ll setBits = __builtin_popcount(i);
	    	for(ll j=0;j<8;j++){ // we will travel through each of 8 bits to check which bits are set or not
	    		if(i&(1<<j)){
	    		denom=denom*primes[j];
	    	}
	    	}
	    	if(setBits&1){ // odd
	    		ans+=n/denom;
	    	}else{
	    		ans-=n/denom;
	    	}
	    }
	    	cout<<ans<<endl;
	    }
	return 0;
}
