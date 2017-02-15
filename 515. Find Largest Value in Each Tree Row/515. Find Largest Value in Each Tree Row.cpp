/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<int> largestValues(TreeNode* root) {
		vector<int> res;
		if (!root) return res;

		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			int curMax = INT_MIN;
			const int curLen = q.size();//�ֲ�const����������һ�־ͻᱻ����
			for (int i = 0; i < curLen; ++i) {
				TreeNode* cur = q.front();
				curMax = max(curMax, cur->val);
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
				q.pop();//std::queue ֻ��������ʹ�ã��������Ա�ڴ��ͷţ����Կ���pop֮��ʹ��front���Ǹ�ָ�롣����Ϊ�˲����������������˴������pop��
			}
			res.push_back(curMax);
		}

		return res;
	}
};