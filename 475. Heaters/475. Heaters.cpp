class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(heaters.begin(), heaters.end(), less<int>());//greater<int>()�ǴӴ�С��less�Ǵ�С���󣬲�С�ļǻ���
		int res = 0;
		for (int i = 0; i<houses.size(); ++i) {
			if (!binary_search(heaters.begin(), heaters.end(), houses[i])) {//binary_search����ֵbool
				auto index = upper_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();//upperbound���ص�һ�����ڵģ�lowerbound���ص�һ�����ڻ��ߴ��ڵ�
				int right = (index<heaters.size() ? heaters[index] - houses[i] : INT_MAX);
				int left = (index - 1 >= 0 ? houses[i] - heaters[index - 1] : INT_MAX);
				res = max(res, min(right, left));
			}
		}
		return res;
	}
};