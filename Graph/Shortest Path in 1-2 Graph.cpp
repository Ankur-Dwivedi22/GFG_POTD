class Solution
{
public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges)
    {
        // code here
        int extra = V;
        vector<vector<int>> adj(V + edges.size());

        for (auto it : edges)
        {
            int u = it[0], v = it[1], wt = it[2];
            if (wt == 1)
            {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            else
            {
                adj[u].push_back(extra);
                adj[extra].push_back(u);

                adj[extra].push_back(v);
                adj[v].push_back(extra);
                extra++;
            }
        }

        vector<int> dist(extra, -1);
        queue<int> q;

        q.push(src);
        dist[src] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            if (node == dest)
            {
                return dist[dest];
            }

            for (int adjNode : adj[node])
            {
                if (dist[adjNode] == -1)
                {
                    dist[adjNode] = 1 + dist[node];
                    q.push(adjNode);
                }
            }
        }

        return -1;
    }
};