#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>

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



void solve() {
    ll t1;
    cin >> t1;
   vector<string> array(t1);
    for (ll i = 0; i < t1; i++) {
        cin >> array[i];
    }
    ll cCountTot = 0;
    for (ll i = 0; i < t1; i++) {
        for (ll j = 0; j < array[i].size(); j++) {
            if (array[i][j] == 'C') {
                cCountTot += 1;
            }
        }
    }
    if (cCountTot & 1) {
        cout << "impossible";
        return;
    }
    ll aCount = 0, cCount = 0;
    vector<string> array2(t1);
    bool switchFlag = true;
    char addChar = 'A';
    // cout<< "CCountTot = " << cCountTot << endl;
    for (ll i = 0; i < t1; i++) {
        string s = "";
        for (ll j = 0; j < array[i].size(); j++) {
            if (array[i][j] == '#') {
                s += "#";
            }
            else if (array[i][j] == 'C') {
                cCount += 1;

                s+=addChar;
                if (cCount == cCountTot/2 && switchFlag) {
                    // cout<<"Switch loop"<<endl;
                    switchFlag = false;
                    addChar = 'B';
                }
            }
            else {
                s+=addChar;
            }
        }
        array2.push_back(s);
    }
    for (auto i: array2) {
        cout << i << endl;
    }
}
// int findIndex(string s, char c) {
//     for (int i = 0; i < s.length(); i++) {
//         if (s[i] == c)
//             return i;
//     }
//     return -1;
// }
// void solve() {
//     string s;
//     cin >> s;
//     map<string, int> M;
//     int ind = 0;
//     vector<string> days = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
//     for (string day : days)
//         M[day] = ind++;
//     int indexOfSpace = s.find(' ');
//     cout << indexOfSpace << endl;
// }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tc;
    // cin >> tc;
    solve();

}

//   g++ -o template template.cpp && ./template
//    ./template < input.txt