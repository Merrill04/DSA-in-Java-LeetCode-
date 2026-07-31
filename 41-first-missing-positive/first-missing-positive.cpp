class Solution {
    void swap(int& a, int& b) {
        int p = a;
        a = b;
        b = p;
    }

public:
    int firstMissingPositive(vector<int>& nums) {
        int res = -1;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                while (nums[i] >= 1 && nums[i] <= n &&
                       nums[i] != nums[nums[i] - 1]) {
                    swap(nums[i], nums[nums[i] - 1]);
                }
            }
        }

        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;

        return n + 1;
    }
};