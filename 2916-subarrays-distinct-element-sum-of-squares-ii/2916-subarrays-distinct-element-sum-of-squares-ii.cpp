
class Solution {
public:
    static const int MOD = 1e9 + 7;

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        vector<long long> sum(4 * n, 0);
        vector<long long> sq(4 * n, 0);
        vector<long long> lazy(4 * n, 0);

        unordered_map<int, int> last;
        long long ans = 0;

        function<void(int, int, int, int, int)> update =
        [&](int node, int start, int end, int l, int r) {
            if (r < start || end < l)
                return;

            if (l <= start && end <= r) {
                long long len = end - start + 1LL;

                sq[node] = (sq[node]
                    + 2LL * sum[node] % MOD
                    + len) % MOD;

                sum[node] = (sum[node] + len) % MOD;
                lazy[node] = (lazy[node] + 1) % MOD;

                return;
            }

            int mid = (start + end) / 2;

            if (lazy[node] != 0) {
                long long v = lazy[node];

                for (int child : {node * 2, node * 2 + 1}) {
                    long long len = (child == node * 2)
                        ? mid - start + 1LL
                        : end - mid;

                    sq[child] = (sq[child]
                        + 2LL * v % MOD * sum[child] % MOD
                        + len * v % MOD * v % MOD) % MOD;

                    sum[child] =
                        (sum[child] + len * v) % MOD;

                    lazy[child] =
                        (lazy[child] + v) % MOD;
                }

                lazy[node] = 0;
            }

            update(node * 2, start, mid, l, r);
            update(node * 2 + 1, mid + 1, end, l, r);

            sum[node] =
                (sum[node * 2] + sum[node * 2 + 1]) % MOD;

            sq[node] =
                (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        };

        for (int i = 0; i < n; i++) {
            int p = 0;

            if (last.find(nums[i]) != last.end()) {
                p = last[nums[i]] + 1;
            }

            update(1, 0, n - 1, p, i);

            last[nums[i]] = i;

            ans = (ans + sq[1]) % MOD;
        }

        return ans;
    }
};
