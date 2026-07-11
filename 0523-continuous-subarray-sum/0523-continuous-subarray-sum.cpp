class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
            unordered_set<int> s;

        int prevVal = 0;
        int currVal = 0;

        for(int i = 0; i < nums.size(); i++){
            currVal = (currVal + nums[i]) % k;

            if(s.count(currVal)) return true;

            s.insert(prevVal);
            prevVal = currVal;
        }

        return false;

        
    }
};