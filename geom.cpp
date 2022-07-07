#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct Point{
    ll x{0}, y{0};
};
struct Vector{
    ll x, y;
    Vector(Point a, Point b){ // vector size
        x = b.x-a.x;
        y = b.y-a.y;
    }
};
ld cross(Point a, Point b){
    return a.x*b.y-b.x*a.y;
}
ld prod(Point a, Point b){
    return a.x*b.x+a.y*b.y;
}
ld dist(Point a, Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
ld angle_between(Point a, Point b){
    return atan2(cross(a, b), prod(a, b));
}
ld area(Point a, Point b, Point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
bool check(ll a, ll b, ll c, ll d){
    if(a>b)swap(a, b);
    if(c>d)swap(c, d);
    return max(a, c) <= min(b, d);
}
bool intersect(Point a, Point b, Point c, Point d){
    return check(a.x, b.x, c.x, d.x) and check(a.y, b.y, c.y, d.y) and area(a, b, c)*area(a, b, d)<=0 and area(c, d, a)*area(c, d, b)<=0;
}
ld poly_ass(vector<Point>poly){
    ld ass = 0;
    for(ll i = 0; i<poly.size(); i++){
        Point p1 = i?poly[i-1]:poly.back();
        Point p2 = poly[i];
        ass+=(p1.x-p2.x)*(p1.y+p2.y);
    }
    return fabs(ass)/2;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
