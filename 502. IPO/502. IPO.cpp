class Solution {
public:
	int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capitals) {

		multimap<int, int> map;
		for (int i = 0; i < Capitals.size(); ++i) {
			map.insert(make_pair(Capitals[i], Profits[i]));
		}

		priority_queue<int> prique;
		while (k--) {
			for (auto iter = map.begin(); iter != map.end(); iter++) {//map��key�Զ�������������
				if (iter->first <= W) {
					prique.push(iter->second);//���ȶ�����������available������ֵ
					map.erase(iter);
				}
				else break;
			}
			if (prique.empty()) break;
			W += prique.top();//���ȶ���top��������������.
			prique.pop();//�����ڶ��������µ�������һ�ּ���available
		}

		return W;
	}
};