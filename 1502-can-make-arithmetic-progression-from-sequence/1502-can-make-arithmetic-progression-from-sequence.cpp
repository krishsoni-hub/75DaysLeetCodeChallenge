#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        int mn = *min_element(arr.begin(), arr.end());
        int mx = *max_element(arr.begin(), arr.end());

        if ((mx - mn) % (n - 1) != 0) return false;

        int d = (mx - mn) / (n - 1);
        unordered_set<int> s(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            if (!s.count(mn + i * d))
                return false;
        }

        return true;
    }
};