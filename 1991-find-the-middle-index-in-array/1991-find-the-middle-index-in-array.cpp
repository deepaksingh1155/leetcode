class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        int i;
        int sum=0;
        for(i=0; i<n; i++){
            sum+=nums[i];
        }
            int left=0;
            for( i=0; i<n; i++){
                int right=sum-left-nums[i];
                if(right==left)
                 return i;
                 left+=nums[i];
            
        }
        return -1;
    }
};