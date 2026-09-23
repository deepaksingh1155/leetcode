class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       vector<vector<int>> temp;

    // 2. Purane saare intervals add
    for (auto interval : intervals) {
        temp.push_back(interval);
    }

    // 3. New interval bhi add
    temp.push_back(newInterval);

    // 4. Sort
    sort(temp.begin(), temp.end());

    // 5. Merge
    vector<vector<int>> ans;

    int start1 = temp[0][0];
    int end1 = temp[0][1];

    for (int i = 1; i < temp.size(); i++) {

        int start2 = temp[i][0];
        int end2 = temp[i][1];

        if (end1 >= start2) {
            end1 = max(end1, end2);
        }
        else {
            ans.push_back({start1, end1});

            start1 = start2;
            end1 = end2;
        }
    }

    ans.push_back({start1, end1});

    return ans;
    }
};