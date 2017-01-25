class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty()) return 0;
		// f[i]��ʾ��i��β������������еĳ���
		vector<int> f(nums.size(), 1);
		int global = 1;
		for (int j = 1; j < nums.size(); ++j) {
			for (int i = 0; i < j; ++i) {
				if (nums[i] < nums[j]) {
					f[j] = max(f[j], f[i] + 1);
				}
			}
			global = max(global, f[j]);
		}
		return global;
	}
};