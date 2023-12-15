#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    vector<int> streaks;

    int currentStreak = 0;
    int totalCount = 0;
    int zeroCount = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ++currentStreak;
            ++totalCount;
        } else {
            streaks.push_back(currentStreak);
            currentStreak = 0;
            ++zeroCount;
        }
    }

    streaks.push_back(currentStreak);
    ++zeroCount;

    int maxStreak = *max_element(streaks.begin(), streaks.end());

    int ans = maxStreak;

    for (int i = 1; i < streaks.size() - 1; ++i) {
        int currStreak = streaks[i];
        int nextStreak = streaks[i + 1];

        int totalStreak = currStreak + nextStreak;
        if (currStreak == maxStreak) {
            --m;
        }
        ans = max(ans, totalStreak);
    }

    if (maxStreak == n) {
        ans = n;
    } else if (k <= zeroCount) {
        if (m > 0) {
            ans = max(ans, maxStreak + 1);
        } else {
            ans = max(ans, maxStreak);
        }
    } else {
        ans = -1;
    }

    cout << ans << endl;

    return 0;
}
