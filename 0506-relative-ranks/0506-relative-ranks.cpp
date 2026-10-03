class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        vector<int> temp = score;

        sort(temp.rbegin(), temp.rend());

        vector<string> ans;

        for(int i = 0; i < score.size(); i++) {

            int rank;

            for(int j = 0; j < temp.size(); j++) {

                if(score[i] == temp[j]) {
                    rank = j + 1;
                    break;
                }
            }

            if(rank == 1) {
                ans.push_back("Gold Medal");
            }
            else if(rank == 2) {
                ans.push_back("Silver Medal");
            }
            else if(rank == 3) {
                ans.push_back("Bronze Medal");
            }
            else {
                ans.push_back(to_string(rank));
            }
        }

        return ans;
    }

        
    
};