class Solution {
public:
    void rec(vector<int>& nums, vector<int> & subset, int idx, vector<vector<int>>& ans){
        if(idx>=nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[idx]); //include the current digit
        rec(nums,subset,idx+1,ans); // call for next digit for inclusion

        subset.pop_back(); //exclue that included digit 

        int skip = idx+1; // next index for exclusion call 
        while(skip<nums.size() and nums[skip]==nums[skip-1]){ // skip the duplicate
            skip++;
        }
        rec(nums,subset,skip,ans); // call for next digit for exclusion
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        rec(nums,subset,0,ans);
        return ans;
    }
};