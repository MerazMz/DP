class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int prefix = 0;
        for(int num:nums) {
            prefix = (prefix * 2 + num) % 5; //increase one bit ahead
            ans.push_back(prefix == 0);
        }

        return ans;
    }
};