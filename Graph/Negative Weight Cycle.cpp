// Approach : Bellman's Ford Algorithm
// TC : O(V * E)
// SC : O(V)

class Solution {
	public:
	bool isNegativeWeightCycle(int V, vector<vector<int>> & edges) {
		// code here
		vector<int> dist(V, 0);
		for (int i=0; i<V - 1; i++) {
		    bool f = false;
			for (const auto &it : edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];
				if (dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
					f = true;
				}
			}
			if(!f) break;
		}
		
		for (const auto &it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] + wt < dist[v]) {
				return true;
			}
		}
		
		return false;
	}
};
