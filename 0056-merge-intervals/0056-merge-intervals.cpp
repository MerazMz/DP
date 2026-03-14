class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int st=nums[0][0],end=nums[0][1];

        for(int i=1;i<n;i++){
            if(nums[i][0] <= end){
                end = max(end,nums[i][1]);
            }else if(nums[i][0]>nums[i-1][1]){
                ans.push_back({st,end});
                st=nums[i][0];
                end = max(end,nums[i][1]);
            }
        }
        ans.push_back({st,end});
        return ans;
    }
};