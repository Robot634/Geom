#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point{
    ll x, y;
};
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<Point>polygon(n);
    for(ll i = 0; i<n; i++)cin>>polygon[i].x>>polygon[i].y;
    double res = 0;
    for(ll i = 0; i<n; i++){
        Point p1 = i?polygon[i-1]:polygon.back();
        Point p2 = polygon[i];
        res += (p1.x-p2.x)*(p1.y+p2.y);
    }
    cout<<abs(res)/2;
    return 0;
}
