#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

struct Point{
    ll x, y;
};
struct Vect{
    ll x, y;
    Vect(Point a, Point b){
        x = b.x - a.x;
        y = b.y - a.y;
    }
};   
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n;
    cin>>n;
    vector<Point>polygon(n);
    for(auto& zz : polygon){
        cin>>zz.x>>zz.y;
    }
    if(n == 3){
        cout<<"YES";
        return 0;
    }
    ll nm = 7;
    bool fl = true;
    for(ll i = 0; i<n; i++){
        ll last = i-1;
        ll next = i+1;
        if(last == -1) last = n-1;
        if(next == n) next = 0;

        Vect a = Vect(polygon[last], polygon[i]);
        Vect b = Vect(polygon[next], polygon[i]);

        if(a.x*b.y - a.y*b.x == 0) continue;
        if(a.x*b.y - a.y*b.x > 0){
            if(nm == 7) nm = 1;
            else if(nm != 1){
                fl = false;
                break;
            }
        }
        else{
            if(nm == 7){
                nm = -1;
            }
            else if(nm != -1){
                fl = false;
                break;
            }
        }
    }
    if(fl) cout<<"YES";
    else cout<<"NO";
    return 0;
}
