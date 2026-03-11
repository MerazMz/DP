class Solution {
public:

    bool shouldSwap(vector<int>& nums, int start, int curr){
        for(int i=start;i<curr;i++){
            if(nums[i]==nums[curr])
                return false;
        }
        return true;
    }
    void rec(vector<int>& nums, int idx, vector<vector<int>>& ans){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(!shouldSwap(nums,idx,i)) continue;
            swap(nums[idx],nums[i]);
            rec(nums,idx+1,ans);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        rec(nums,0,ans);
        return ans;
    }
};