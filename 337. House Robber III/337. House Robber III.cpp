/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
/*��root����0�㣩Ϊ�������ȡ��0��Ľڵ㣬���1��Ľڵ㲻��ȡ
�������ȡ��0��Ľڵ㣬���1��Ľڵ��ȡ�ɲ�ȡ��
����������Ҫ��¼��ÿ���ڵ�ȡ�벻ȡʱ�ܹ���ȡ�����Ǯ��
��ͨ��������ȱ��������������ȡroot�ڵ㷵�ص�������ֵ�д�ľͿ����ˡ�*/
class Solution {
	typedef pair<int, int> nodeMax;//nodeMax.first��������node��max��second������node��max
public:
	int rob(TreeNode* root) {
		nodeMax res = getMoney(root);
		return max(res.first, res.second);
	}
private:
	nodeMax getMoney(TreeNode* root) {
		nodeMax cur = make_pair(0, 0);
		if (!root) return cur;

		nodeMax l = getMoney(root->left);
		nodeMax r = getMoney(root->right);

		cur.first = max(l.first, l.second) + max(r.first, r.second);//�������˵㣬��ô������������ȡ���Ե����ֵ
		cur.second = root->val + l.first + r.first;//�����˵㣬��ô��һ�㲻��ȡ��ֻ��ȡ�������������������ֵ

		return cur;
	}
};