#include<bits/stdc++.h>
using namespace std;

#define mx 200005
#define mod 1000000007
#define PI acos(-1.0)
#define eps 1e-7
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define mem(name, value) memset(name, value, sizeof(name))
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef vector <ll> vll;
typedef set <ll> sll;
typedef queue <ll> qll;
typedef map <ll, ll> mll;
typedef pair <ll, ll> pll;
typedef vector <pair <ll , ll> > vpll;

int x, y, GCD;
int gcd(int a, int b){
    if(b==0) return a;

    return gcd(b, a%b);
}
void extendedEuclid(int a, int b){
    if(b==0){
        x=1;
        y=0;
        GCD=a;
        return;
    }
    extendedEuclid(b, a%b);
    int cx=y;
    int cy=x-(a/b)*y;

    x=cx;
    y=cy;
}
int inverseModulo(int a, int m){
    extendedEuclid(a, m);
    return (x+m)%m; // adding m to make solution positive
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("in5.txt", "r", stdin);
        freopen("outcast8.txt", "w", stdout);
    #endif
    ll n, p, w, d;
    cin>>n>>p>>w>>d;
    ll x1,y1,z;
    ll g=__gcd(w, d);
    if(p%g!=0) cout<<-1<<endl;
    else if(n*w < p){
        cout<<-1<<endl;
    }
    else{
        p/=g;
        w/=g;
        d/=g;
        y1=((p%w)*inverseModulo(d, w))%w;
        x1=(p-(y1*d))/w;
        if(x1+y1>n) cout<<-1<<endl;
        else if(x1<0) cout<<-1<<endl;
        else{
        z=n-(x1+y1);
        cout<<x1<<" "<<y1<<" "<<z;
    }
    }
}
