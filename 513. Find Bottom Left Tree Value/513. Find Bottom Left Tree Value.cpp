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
	int findBottomLeftValue(TreeNode* root) {
		int res;
		if (!root) return NULL;

		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			const int curLen = q.size();//�ֲ�const����������һ�־ͻᱻ����
			for (int i = 0; i < curLen; ++i) {
				TreeNode* cur = q.front();
				if (i == 0) res = cur->val;
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
				q.pop();//std::queue ֻ��������ʹ�ã��������Ա�ڴ��ͷţ����Կ���pop֮��ʹ��front���Ǹ�ָ�롣����Ϊ�˲����������������˴������pop��
			}
		}

		return res;
	}
};