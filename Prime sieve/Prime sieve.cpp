#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define pb push_back
#define mod 1000000000

int p[1000005]={0};
ll pre[1000005]={0};
int main(){

	#ifndef ONLINE_JUDGE
	    freopen("in2.txt", "r", stdin);
	    freopen("out2.txt", "w", stdout);
	#endif
	ll n;
	cin>>n;
	ll a, b;
	while(n--){
		cin>>a>>b;
	for(ll i=3;i<=1000000;i+=2){
		p[i]=1;
	}
	
	for(ll i=3;i<=1000000;i+=2){
		if(p[i]==1){
			for(ll j=i*i;j<=1000000;j+=i){
				p[j]=0;
			}
		}
	}
	p[2]=1;
	p[1]=p[0]=0;
	pre[0]=p[0];
	for(ll i=1;i<=1000000;i++){
		pre[i]=p[i]+pre[i-1];
	}
	cout<<pre[b]-pre[a-1]<<endl;
}
	return 0;
}


