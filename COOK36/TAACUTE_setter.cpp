#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <complex>
#include <cassert>

#define REP(i,n)               for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n)              for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b)             for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b)            for (int i = (a), _b = (b); i >= _b; i--)
#define FORN(i,a,b)            for(int i=a;i<b;i++)
#define FOREACH(it,c)          for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x)             memset (c, x, sizeof (c))

#define PI                     acos(-1)
#define sqr(x)                 ((x) * (x))
#define PB                     push_back
#define MP                     make_pair
#define F                      first
#define S                      second
#define Aint(c)                (c).begin(), (c).end()
#define SIZE(c)                (c).size()

#define DEBUG(x)               { cerr << #x << " = " << x << endl; }
#define PR(a,n)                {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n)               {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define PR1(a,n)               {REP(_,n) cerr <<#a<<"["<<_<<"]" a[_] <<endl; cerr << endl;}
#define LL long long

#define maxn

using namespace std;

// struct Point {
//     int x, y;

//     Point() {
//         x = y = 0;
//     }

//     Point (int a, int b) {
//         x = a;
//         y = b;
//     }

//     //vector between two points
//     Point operator - (Point p) {
//         return Point (x  - p.x, y - p.y);
//     }

//     //cross product
//     int operator * (Point p) {
//         return x * p.y - y * p.x;
//     }

//     //dot product
//     int operator + (Point p) {
//         return x * p.x + y * p.y;
//     }
// };


// int pos(Point a) {
//     if (a.y >= 0 && a.x > 0) return 1;
//     if (a.x <= 0 && a.y >= 0) return 2;
//     if (a.y < 0 && a.x <= 0) return 3;
//     return 4;
// }

// bool cmp(Point a, Point b) {
//     int x = pos(a);
//     int y = pos(b);
//     if (x != y) return x < y;
//     return a * b > 0;
// }

// bool cmp_2(Point a, Point b) {
//     if (a.x != b.x) return a.x < b.x;
//     return a.y < b.y;
// }

// int N;
// Point a[2222], b[4222];
// int cnt[2222];

// //return n choose 3
// long long C3(long long x) {
//     return x * (x - 1) * (x - 2) / 6;
// }

// long long calc_1(int root) {
//     long long res = 0;
//     //sort all the points base on the anti-clockwise angle from Ox to the vector from the origin to each point
//     sort (b + 1, b + N, cmp);

//     //double the array
//     for (int i = 1; i <= N; i++)
//         b[i + N - 1] = b[i];

//     int pr = 1;
//     for (int pos = 1; pos <= N - 1; pos++) {
//             int L = pos, R = pos + N - 2, u = 0;

//             //Find u so that for all the point P amongst the points b[pos + 1], b[pos + 2], ..., b[u], the anti-clockwise angle b[pos]OP will be less than 180 degree
//             //when b[pos] * b[mid] > 0 the angle b[pos] O b[mid] may equal to 180 degree or 0 degree
//             //we elimintate all the points that give us the latter case (0 degree) so that the binary search will work
//             if (pr < pos) pr = pos;
//             while ((b[pos] * b[pr + 1]) == 0 && (b[pos] + b[pr + 1]) > 0 && pr <= R) pr++;
//             L = pr + 1;

//             while (L <= R) {
//                 int Mid = (L + R) / 2;
//                 if (b[pos] * b[Mid] > 0) {
//                     u = Mid;
//                     L = Mid + 1;
//                 }
//                 else R = Mid - 1;
//             }

//             if (!u) continue;

//             //find the first point P from b[pos] to b[u] such that the anti-clockwist angle b[pos]OP is equal to or larger than 90 degree
//             L = pos + 1;
//             R = u;
//             int v = 0;

//             while (L <= R) {
//                 int Mid = (L + R) / 2;
//                 if (b[pos] + b[Mid] <= 0) {
//                     v = Mid;
//                     R = Mid - 1;
//                 }
//                 else L = Mid + 1;
//             }
//             //we have (u - v + 1) triangles that is not acute
//             if (v)
//                 res += u - v + 1;
//     }

//     return res;
// }

// void calc_2() {
//         //edit the point so that if A and B are in the same line with the orgin then A = B
//         for (int i = 1; i <= N - 1; i++) {
//             if (b[i].y < 0) {
//                 b[i].y = - b[i].y;
//                 b[i].x = - b[i].x;
//             }

//             if (b[i].y == 0) b[i].x = 1;
//             else if (b[i].x == 0) b[i].y = 1;
//             else {
//                 long long g = __gcd(abs(b[i].x), b[i].y);
//                 b[i].x /= g;
//                 b[i].y /= g;
//             }
//         }

//         sort(b + 1, b + N, cmp_2);

//         int tmp = 1;

//         //find the groups of points that lies on the same line
//         //note that one point is moved to the origin
//         for (int i = 2; i <= N - 1; i++)
//             if (b[i].x != b[i - 1].x || b[i].y != b[i - 1].y) {
//                 cnt[tmp + 1] ++;
//                 tmp = 1;
//             }
//             else tmp++;
//         cnt[tmp + 1] ++;
// }

int main() {

    int tony[] = {1,2,3,4,5};
    PR1(tony,5);
    // cin >> N;
    // for (int index = 1; index <= N; index ++)
    //     cin >> a[index].x >> a[index].y;

    // long long res = C3(N);
    // long long type_1 = 0;

    // for (int root = 1; root <= N; root ++) {
    //     for (int i = 1; i <= N; i++)
    //         b[i] = a[i];

    //     swap(b[N], b[root]);
    //     //move a[root] back to the origin
    //     for (int i = 1; i < N; i++)
    //         b[i] = b[i] - b[N];

    //     type_1 += calc_1(root);
    //     calc_2();
    // }

    // res -= type_1;
    // long long type_2 = 0;

    // //if a specific line D contains exactly k points then it will be counted k times in cnt[k]
    // for (int i = 3; i <= N; i++)
    //     type_2 += cnt[i]/i * C3(i);

    // res -= type_2;

    // cout << res;
    // return 0;
}
