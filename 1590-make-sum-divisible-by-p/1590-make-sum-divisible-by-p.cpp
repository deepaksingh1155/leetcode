class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) 
            total += x;
            int rem = total % p;
            if (rem == 0)
                return 0;
            unordered_map<int, int> mp;
            mp[0] = -1;
            int ans = nums.size();
            long long sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                int currem = sum % p;
                int target = (currem - rem + p) % p;
                if (mp.find(target) != mp.end()) {
                    ans = min(ans, i - mp[target]);
                }
                mp[currem] = i;
            }

            if (ans ==nums.size()) {
                return -1;
            }
            else{
            return ans;
            }
        
        }
    };