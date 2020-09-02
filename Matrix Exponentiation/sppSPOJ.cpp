#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define pb push_back

ll k, mod;
vector<ll> b, c;

vector<vector<ll>> multiply(vector<vector<ll>> m, vector<vector<ll>> n){
	
	vector<vector<ll>> mc(k+2, vector<ll>(k+2));
	
	for(int i=1;i<=k+1;i++){
		for(int j=1;j<=k+1;j++){
			for(int x=1;x<=k+1;x++){
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

	vector<ll> a(k+2);
	for(int i=1;i<=k+1;i++){
		if(i==1) a[i]=b[0];
		else
		 a[i]=b[i-2];
	}

	vector<vector<ll>> v(k+2, vector<ll>(k+2));

	for(int i=1;i<=k+1;i++){
	 	for(int j=1;j<=k+1;j++){
	 		if(i==1){
	 			if(j==1) v[i][j]=1;
	 			else v[i][j]=c[k+1-j];
	 		}
	 		else if(i<k+1){
	 			if(j==i+1){
	 				v[i][j]=1;
	 			}
	 			else v[i][j]=0;
	 		}
	 		else{
	 			if(j==1) v[i][j]=0;
	 			else v[i][j]=c[k+1-j];
	 			
	 		}
	 		cout<<v[i][j]<<" ";
	 	}
	 	cout<<endl;
	 }
	v=pow(v, n-1);

	 	ll res=0;
	 	for(int i=1;i<=k+1;i++){
	 		res=(res+(v[k+1][i]*a[i])%mod)%mod;
	 	}

	 	return res;
}
int main(){

	#ifndef ONLINE_JUDGE
	    freopen("inp.txt", "r", stdin);
	    freopen("out.txt", "w", stdout);
	#endif
	 ll t,n,m; cin>>t;
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
	 	cin>>m>>n>>mod;
	 	ll first=compute(n);
	 	b.clear();
	 	c.clear();
	 	ll second=compute(m-1);
	 	cout<<first-second<<endl;
	 	b.clear();
	 	c.clear();
	 }
	return 0;
}


