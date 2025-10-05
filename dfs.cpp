#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h, w;
    cin >> n >> h >> w;

    vector<pair<int, int>> books(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i].first >> books[i].second;  // height, thickness
    }
    for (int mask = 1; mask < (1 << n) - 1; mask++) {
        vector<int> upright, stacked;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                upright.push_back(i);
            } else {
                stacked.push_back(i);
            }
        }

        int uprightWidth = 0;
        bool validUpright = true;

        for (int i : upright) {
            if (books[i].first > h) {
                validUpright = false;
                break;
            }
            uprightWidth += books[i].second;
        }

        if (!validUpright) continue;

        vector<pair<int, int>> stackedBooks;
        for (int i : stacked) {
            stackedBooks.push_back({books[i].first, i});
        }

        sort(stackedBooks.begin(), stackedBooks.end(), greater<pair<int, int>>());

        int stackThickness = 0;
        for (auto [height, idx] : stackedBooks) {
            stackThickness += books[idx].second;
        }

        if (stackThickness > h) continue;
        int stackWidth = stackedBooks[0].first;


        if (uprightWidth + stackWidth <= w) {

            cout << "upright";
            sort(upright.begin(), upright.end());
            for (int i : upright) {
                cout << " " << (i + 1);
            }
            cout << "\n";

            cout << "stacked";
            for (auto [height, idx] : stackedBooks) {
                cout << " " << (idx + 1);
            }
            cout << "\n";

            return 0;
        }
    }

    cout << "impossible\n";
    return 0;
}
