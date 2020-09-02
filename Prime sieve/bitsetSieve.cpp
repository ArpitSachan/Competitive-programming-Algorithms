#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define pb push_back
#define mod 1000000000

const int n=10000000;
bitset<10000005> b;
vector<int> primes;
void sieve(){
	b.set(); // 1,1,1,1,......
	b[0]=0;
	b[1]=0;

	for(ll i=2;i<=n;i++){
		if(b[i]){
			primes.pb(i);
			for(ll j=i*i;j<=n;j+=i){
				b[j]=0;
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
	for(int i=0;i<=100;i++){
		cout<<primes[i]<<" ";
	}
	return 0;
}


