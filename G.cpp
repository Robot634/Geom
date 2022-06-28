#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 100001;
const int K = 150;
ld x[N], v[N];
ld inf = 1e9+1;
ld get_dist(ld t, ll n){
    ld minx = inf;
    ld maxx = -inf;
    for(ll i = 0; i<n; i++){
        minx = min(minx, x[i]+v[i]*t);
        maxx = max(maxx, x[i]+v[i]*t);
    }
    return maxx-minx;
}
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n;
    cin>>n;
    for(ll i = 0; i<n; i++){
        cin>>x[i]>>v[i];
    }
    ld l = 0, r = inf-1;
    for(ll i = 0; i<K; i++){
        ld m1 = (2*l+r)/3;
        ld m2 = (l+2*r)/3;
        if(get_dist(m1, n)<get_dist(m2, n)){
            r = m2;
        }
        else l = m1;
    }
    ld t = (l+r)/2;
    cout<<fixed<<setprecision(10)<<t<<" "<<get_dist(t, n);
    return 0;
}
