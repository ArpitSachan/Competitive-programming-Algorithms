#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define pb push_back

ll a[1000005];
ll pre[1000005];


int main(){

	#ifndef ONLINE_JUDGE
	    freopen("inp.txt", "r", stdin);
	    freopen("out.txt", "w", stdout);
	#endif

	    int n;
	    cin>>n;
	    memset(pre, 0, sizeof(pre));

	    pre[0]=1;
	    ll sum=0;
	    for(int i=0;i<n;i++){
	    	cin>>a[i];
	    	sum+=a[i];
	    	sum%=n;
	    	sum=(sum+n)%n; // to avoid negative value we added n.
	    	pre[sum]++;
	    }
	    ll ans=0;
	    for(int i=0;i<n;i++){
	    	ans+=pre[i]*(pre[i]-1)/2;
	    }
	    cout<<ans<<endl;

	return 0;
}


