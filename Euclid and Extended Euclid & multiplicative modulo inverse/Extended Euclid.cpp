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
int lcm(int a, int b){
    return a*b/gcd(a, b);
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
// Assume inverse exists
int inverseModulo(int a, int m){
    extendedEuclid(a, m);
    return (x+m)%m; // adding m to make solution positive
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("in4.txt", "r", stdin);
        freopen("out4.txt", "w", stdout);
    #endif
    
    // extendedEuclid(18, 30);
    // cout<<x<<" "<<y<<endl;
        cout<<inverseModulo(6, 7)<<endl;
}
