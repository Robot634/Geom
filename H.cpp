#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<ld>v;
ld inf = 1e9+1;
ld zero = 0;
struct dick{
    ld x1, x2;
};
vector<dick>c;
ld check(ld mid){
    ld a = -inf, b = inf;
    for(ll i = 0; i<c.size(); i++){
        a = max(c[i].x1+v[i]*mid, a);
        b = min(c[i].x2+v[i]*mid, b);
    }
    return max(b-a, zero);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ld n;
    cin>>n;
    v.resize(n);
    c.resize(n);
    for(ll i = 0; i<n; i++){
        cin>>c[i].x1>>c[i].x2;
        cin>>v[i];
    }
    ld l = 0, r = inf-1;
    for(ll i = 0; i<150; i++){
        ld m1 = (2*l+r)/3;
        ld m2 = (l+2*r)/3;
        if(check(m1)<check(m2)){
            l = m1;
        }
        else r = m2;
    }
    ld t = (r+l)/2;
    cout<<fixed<<setprecision(10)<<check(t);
    return 0;
}
