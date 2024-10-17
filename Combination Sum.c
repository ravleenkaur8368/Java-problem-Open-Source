auto init = []{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
};
class Solution {
public:
    void Solve(vector<int> &nums, int target, int i, vector<int> &temp, vector<vector<int>> &ans){
        int n = nums.size();
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(i >= n){
            return;
        }
        for(int idx = i; idx<n; idx++){
            if(idx > i && nums[idx] == nums[idx-1]){
                continue;
            }
            if(nums[idx] > target){
                break;
            }
            temp.push_back(nums[idx]);
            Solve(nums, target - nums[idx], idx+1, temp, ans);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> ans; 
        sort(nums.begin(), nums.end());
        Solve(nums, target, 0, temp, ans);
        return ans;
    }
};
