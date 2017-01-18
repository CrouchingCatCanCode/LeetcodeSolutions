class Solution {
	/*�������鵱ǰ���Ա�ʾ�ķ�ΧΪ[1, total)�ڵ��������֣�
	��ô�����������Ԫ��add���Խ���ʾ��Χ������[1, total + add)��
	����add��total�����ҽ���add=totalʱȡ����Χ����[1, 2 * total)��
	����������С�ڵ���add��Ԫ��ʱ�������������е�Ԫ�ء�
	��û�У��������Ԫ��add��*/
public:
	int minPatches(vector<int>& nums, int n) {
		long total = 1;
		int count = 0;

		for (int i = 0; total <= n;) {
			if (i<nums.size() && nums[i] <= total) {
				total += nums[i++];
			}
			else {
				total <<= 1;
				count++;
			}
		}

		return count;
	}
};