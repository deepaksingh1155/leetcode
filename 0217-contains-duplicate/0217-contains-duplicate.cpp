class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // if(nums.size()==1) 
        // return false;
        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i]==nums[i+1]) return true;
        // }
        // return false; 
          unordered_map<int,int> mp;
            for(int x:nums){
                mp[x]++;
                if(mp[x]>1){
                    return true;
                }
            }
            return false;
    }
    
};