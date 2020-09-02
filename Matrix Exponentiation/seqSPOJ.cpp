#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define pb push_back
#define mod 1000000000

ll k;
vector<ll> b, c;

vector<vector<ll>> multiply(vector<vector<ll>> m, vector<vector<ll>> n){
	
	vector<vector<ll>> mc(k+1, vector<ll>(k+1));
	
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			for(int x=1;x<=k;x++){
				mc[i][j]=(mc[i][j]+(m[i][x]*n[x][j])%mod)%mod;
			}
		}
	}
	
	return mc;
}

vector<vector<ll>> pow(vector<vector<ll>> v, ll p){
	if(p==1) return v;

	if(p&1){
		return multiply(v, pow(v, p-1));
	}
	vector<vector<ll>> x=pow(v, p/2);
	return multiply(x, x);
}

ll compute(ll n){
	if(n==0) return 0;
	if(n<=k) return b[n-1];

	vector<ll> a(k+1);
	for(int i=1;i<=k;i++){
		a[i]=b[i-1];
	}

	vector<vector<ll>> v(k+1, vector<ll>(k+1));

	for(int i=1;i<=k;i++){
	 	for(int j=1;j<=k;j++){
	 		if(i<k){
	 			if(j==i+1){
	 				v[i][j]=1;
	 			}
	 			else v[i][j]=0;
	 		}
	 		else{
	 			v[i][j]=c[k-j];
	 			
	 		}
	 	}
	 }
	v=pow(v, n-1);

	 	ll res=0;
	 	for(int i=1;i<=k;i++){
	 		res=(res+(v[1][i]*a[i])%mod)%mod;
	 	}

	 	return res;
}
int main(){

	#ifndef ONLINE_JUDGE
	    freopen("inp.txt", "r", stdin);
	    freopen("out.txt", "w", stdout);
	#endif
	 ll t,n; cin>>t;
	 while(t--){
	 	cin>>k;
	 	for(int i=0;i<k;i++){
	 		int y;
	 		cin>>y;
	 		b.pb(y);
	 	}
	 	for(int i=0;i<k;i++){
	 		int y;
	 		cin>>y;
	 		c.pb(y);
	 	}
	 	cin>>n;
	 	cout<<compute(n)<<endl;
	 	b.clear();
	 	c.clear();

	 }
	return 0;
}


