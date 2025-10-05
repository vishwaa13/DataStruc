#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <sstream>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define ii pair<int, int>
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
typedef pair <ii, int> iii;



void solve() {
    int n, h, w, x, y;
    cin >> n >> h >> w;
    vector <bool> visited(n, false);
    priority_queue<iii, vector <iii>, greater<iii>> pq1, pq2;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        pq1.push({{x, y}, i});
        pq2.push({{y, x}, i});
    }
    for (int i = 0; i < n; i++) {
        if (pq1.top().second == pq2.top().second) {

        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tc;
    // cin >> tc;
    solve();
    return -1;
}

//   g++ -o template template.cpp && ./template
//    ./template < input.txt