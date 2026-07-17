class Solution {
public:
    int firstUniqChar(string s) {
         int n = s.size();
        vector<int>temp(26,0);

        for(int i=0; i<n; i++){
            temp[s[i]-'a']++;
        }

        for(int i=0; i<n; i++){
            if(temp[s[i]-'a'] == 1){
                return i;
            }
        }

        return -1;
    }
};