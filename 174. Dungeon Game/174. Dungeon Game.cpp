class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		if (dungeon.empty() || dungeon[0].empty())
			return 1;
		int m = dungeon.size();
		int n = dungeon[0].size();
		vector<vector<int> > minHP(m, vector<int>(n, 0));//��ʾ(i,j)���յ�(m-1,n-1)��Ҫ����С����ֵ
		for (int i = m - 1; i >= 0; i--)//�����¿�ʼ��һ·������
		{
			for (int j = n - 1; j >= 0; j--)
			{
				if (i == m - 1 && j == n - 1)
					minHP[i][j] = max(1, 1 - dungeon[i][j]);//ÿ�����ٱ��ִ��ڵ���1
				else if (i == m - 1)
					minHP[i][j] = max(1, minHP[i][j + 1] - dungeon[i][j]);
				else if (j == n - 1)
					minHP[i][j] = max(1, minHP[i + 1][j] - dungeon[i][j]);
				else
					minHP[i][j] = max(1, min(minHP[i + 1][j] - dungeon[i][j], minHP[i][j + 1] - dungeon[i][j]));
			}
		}
		return minHP[0][0];
	}
};