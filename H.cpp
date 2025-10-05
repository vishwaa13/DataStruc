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
    int n;
    cin >> n;
    vector<string> array;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        array.push_back(s);
    }
    int cTot = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<2 * n -1; j++) {
            if (array[i][j] == 'C') {
                cTot++;
            }
        }
    }
    if (cTot & 1) {
        cout << "impossible";
        return;
    }
    char addChar = 'A';
    int cCount = 0;
    bool flag = true;
    vector<string> ans(n);
    for (int i=0;i<n; i++) {
        string s;
        for (int j =0 ;j < 2*n-1; j++) {
            if (array[i][j] == '#') {
                s += '#';
            }
            else if (array[i][j] == '.') {
                s += addChar;
            }
            else {
                s+=addChar;
                cCount += 1;
                if (cCount == cTot/2 && flag) {
                    flag = false;
                    addChar = 'B';
                }
            }
        }
        ans.push_back(s);
    }
    cCount = 0;flag = true;
    for (int i=0;i<n; i++) {
        string s;
        for (int j =0 ;j < 2*n-1; j++) {
            if (array[i][j] == 'C') {
                cCount += 1;
            }
            if (cCount == cTot/2) {
                if ((j == n -(i+1) || j == array[i].size() - 1 -  n -(i+1)) && i == array[i].size() - 1) {
                    cout << "impossible";
                    return;
                }
                if (j == n -(i+1) || j == array[i].size() - 1 -  n -(i+1)) {
                    flag = false;
                }
                if ((j == n -(i+1) || j == array[i].size() - 1 -  n -(i+1))) {
                    if (j == n -(i+1)) {
                        if (array[i][j + 1] == 'C') {
                            swap(ans[i][j], ans[i][j+1]);
                            flag = true;
                        }
                    }
                    if (j == array[i].size() - 1 -  n -(i+1)) {
                        if (array[i][j -1] == 'C') {
                            swap(ans[i][j], ans[i][j-1]);
                            flag = true;
                        }
                    }
                    if (!flag) {
                        cout << "impossible";
                        return;
                    }
                }
            }
        }
    }
    for (auto i: ans) {
        cout << i << endl;
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