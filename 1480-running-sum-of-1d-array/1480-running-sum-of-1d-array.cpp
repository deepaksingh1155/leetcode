class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        // vector<int>prefix(n);
        // prefix[0]=nums[0];
        // for(int i=1; i<n; i++){
        //     prefix[i]=prefix[i-1]+nums[i];
        // }
        // return prefix;
        for(int i=0; i<n; i++){
            int  sum=0;
            for(int j=0; j<=i; j++){
                sum+=nums[j];
            }
            ans[i]=sum;
        }
        return ans;
    }
};