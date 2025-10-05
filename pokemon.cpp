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

vector <int> gameAssignment;
void DFS(int v, vector <bool> &visited, vector < vector<int> > &M, int &curr, int K){
    visited[v] = true;
    if (curr != K) curr++;
    gameAssignment[v] = curr;
    for(auto it = M[v].begin(); it != M[v].end(); it++){
        if(!visited[*it])
            DFS(*it, visited, M, curr, K);
    }
}

void ConnectedComponents(int V, int &K, vector < vector <int> > &M){
    gameAssignment.resize(V);
    vector <bool> visited(V, false);
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            int curr = 0;
            DFS(i, visited, M, curr, K);
            if (curr != K) {
                cout << "impossible";
                K = 100001;
                break;
            }
        }
    }
    visited.clear();
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector < vector <int> > M(n);
    int x, y;
    while(m--) {
        cin >> x >> y;
        M[x - 1].push_back(y - 1);
        M[y - 1].push_back(x - 1);
    }
    ConnectedComponents(n, k, M);
    if (k != 100001) {
        for (int i = 0; i< gameAssignment.size(); i++) {
            if (i == gameAssignment.size() - 1) {
                cout << gameAssignment[i];
            }
            else {
                cout<< gameAssignment[i] << " ";
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tc;
    // cin >> tc;
    solve();
}

//   g++ -o template template.cpp && ./template
//    ./template < input.txt