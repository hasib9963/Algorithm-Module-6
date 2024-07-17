#include <bits/stdc++.h>
using namespace std;

// Constants
const int N = 1e5 + 5; // Maximum number of nodes

vector<pair<int, int>> v[N];// Adjacency list to represent the graph with weights

int dis[N]; // Array to store the shortest distance from the source node

bool vis[N]; // Array to mark visited nodes

// Dijkstra's algorithm to find the shortest path from the source node
void dijkstra(int s)
{
    // Priority queue to get the next node with the smallest distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s}); // Push the source node with distance 0
    dis[s] = 0; // Distance to the source node is 0

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top(); // Get the node with the smallest distance
        pq.pop();
        int parentNode = parent.second;

        // Skip the node if it has already been visited
        if (vis[parentNode])
        {
            continue;
        }

        vis[parentNode] = true; // Mark the node as visited
        int parentCost = parent.first;

        // Explore all adjacent nodes
        for (int i = 0; i < v[parentNode].size(); i++)
        {
            pair<int, int> child = v[parentNode][i];
            int childNode = child.first;
            int childCost = child.second;

            // Relaxation step: update the shortest distance to the child node
            if (parentCost + childCost < dis[childNode])
            {
                dis[childNode] = parentCost + childCost;
                pq.push({dis[childNode], childNode});
            }
        }
    }
}

int main()
{
    int n, e; // Number of nodes and edges
    cin >> n >> e;

    // Read the edges and build the graph
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w}); // Add the edge to the graph
        // v[b].push_back({a, w}); // Uncomment for an undirected graph
    }

    // Initialize distances to infinity (INT_MAX)
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    dijkstra(1); // Perform Dijkstra's algorithm starting from node 1

    // Print the shortest distance from node 1 to all other nodes
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": " << dis[i] << endl;
    }

    return 0;
}
