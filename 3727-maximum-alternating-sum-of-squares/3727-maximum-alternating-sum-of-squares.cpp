class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n= nums.size();
       vector< long long> ans(n);
        for(int i=0; i<n; i++){
            ans[i]=1LL*nums[i]*nums[i];
        }
        sort(ans.begin(), ans.end());
        long long sum=0;
        int k=n/2;
        for(int i=0; i<k; i++){
            sum-=ans[i];
        }
        for(int i=k; i<n; i++){
            sum+=ans[i];

        }
        return sum;
        
    }
};