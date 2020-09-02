#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define pb push_back

int main(){

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	    int t; cin>>t;
	    ll n;
	    while(t--){
	    cin>>n;
	    ll a[n];
	    ll pre[n];
	    memset(pre, -1, sizeof(pre));

	    ll sum=0;
	    pre[0]=0;
	    bool flag=false;
	    for(int i=0;i<n;i++){
	    	cin>>a[i];
	    	sum+=a[i];
	    	sum%=n;
	    	sum=(sum+n)%n; // to avoid negative value we added n.
	    	if(sum==0){
	    		cout<<"1"<<endl;
	    		cout<<i+1<<endl;
	    	}
	    	if(pre[sum]!=-1){
	    		cout<<i-pre[sum]<<endl;
	    		for(ll j=pre[sum]+1;j<=i;j++){
	    			cout<<j+1<<" ";
	    		}
	    		cout<<endl;
	    		break;
	    	}
	    	pre[sum]=i;
	    }
	    if(!flag) cout<<-1<<endl;
	 }
	return 0;
}


