class Solution {
public:
	int minCut(string s) {
		const int n = s.size();
		int f[n + 1];//f(i)=����[i, n-1]֮����С��cut��
		bool p[n][n];//�ж�[i,j]�Ƿ��ǻ���
		fill_n(&p[0][0], n * n, false);
		//fill_n�����������ǣ��������� : һ����������һ���������Լ�һ��ֵ���ú����ӵ�����ָ���Ԫ�ؿ�ʼ����ָ��������Ԫ������Ϊ������ֵ��

		//the worst case is cutting by each char.
		//the worst case�ĳ�ʼ��
		for (int i = 0; i <= n; i++) {
			f[i] = n - 1 - i; // ���һ��f[n]=-1
		}

		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j < n; j++) {
				if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) {//��ôP[i][j]ҲΪ����
					p[i][j] = true;
					f[i] = min(f[i], f[j + 1] + 1);
				}
			}
		}
		return f[0];
	}
};