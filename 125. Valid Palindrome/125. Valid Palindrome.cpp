class Solution {
public:
	bool isPalindrome(string s) {
		transform(s.begin(), s.end(), s.begin(), ::tolower);//tolower������ΪʲôҪ��::��remians
		auto left = s.begin(), right = prev(s.end());//����ָ�룬��string.at()Ҳ���ԣ���java��charAt����
		while (left < right) {
			if (!isalnum(*left)) advance(left, 1);//����++left;
												  //�����һ�����ֻ���ĸ��isalnum����������ط���ֵ������Ϊ0
			else if (!isalnum(*right)) advance(right, -1);//����++right;   ����right=prev(right,1)��
														  //advance(left,1)  vs  right=prev(right,1) ��������ע�⣺prev���޸�ָ��ԭֵ��ֻ�᷵��һ���µ�ָ�롣��advanceֱ���޸�ԭֵ��
			else if (*left != *right) return false;
			else { left++, right--; }
		}
		return true;
	}
};