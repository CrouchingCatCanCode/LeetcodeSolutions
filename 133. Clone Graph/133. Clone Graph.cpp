/**
* Definition for undirected graph.
* struct UndirectedGraphNode {
*     int label;
*     vector<UndirectedGraphNode *> neighbors;
*     UndirectedGraphNode(int x) : label(x) {};
* };
*/

//��queueʵ�ֹ����������
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == nullptr) return nullptr;//std::nullptr_t ��c++��ָ�����͵����֣�nullptr.��c++11�������

		unordered_map<int, UndirectedGraphNode *> copied;

		queue<const UndirectedGraphNode *> q;
		q.push(node);
		copied[node->label] = new UndirectedGraphNode(node->label);//newһ���ķ���ֵ��ָ��

		while (!q.empty()) {
			const UndirectedGraphNode *cur = q.front();//forntȡ���еĵ�һ��
			q.pop();

			for (UndirectedGraphNode *nbr : cur->neighbors) {

				if (copied.find(nbr->label) == copied.end()) {  //not exist
					copied[nbr->label] = new UndirectedGraphNode(nbr->label);
					copied[cur->label]->neighbors.push_back(copied[nbr->label]);
					q.push(nbr);
				}
				else {                                       //exist
					copied[cur->label]->neighbors.push_back(copied[nbr->label]);
				}
			}
		}
		return copied[node->label];
	}
};