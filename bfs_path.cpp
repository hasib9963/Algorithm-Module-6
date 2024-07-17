#include <bits/stdc++.h>
using namespace std;

// Constants
const int N = 1e5 + 5; // Maximum number of nodes

// Arrays to store distance, visited status, and parent of each node
int dis[N];
bool vis[N];
int par[N];

// Adjacency list to represent the graph
vector<int> v[N];

// BFS function to explore the graph and find the shortest path
void bfs(int s)
{
    queue<int> q;  // Queue to hold nodes to visit
    q.push(s);     // Push the starting node
    dis[s] = 0;    // Distance to the start node is 0
    par[s] = -1;   // Start node has no parent
    vis[s] = true; // Mark start node as visited

    // Process nodes in the queue
    while (!q.empty())
    {
        int parent = q.front(); // Get the front node
        q.pop();                // Remove it from the queue

        // Explore all adjacent nodes
        for (int child : v[parent])
        {
            if (!vis[child]) // If the child node is not visited
            {
                q.push(child);                // Push the child node to the queue
                par[child] = parent;          // Set the parent of the child node
                dis[child] = dis[parent] + 1; // Set the distance to the child node
                vis[child] = true;            // Mark the child node as visited
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
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs(1); // Perform BFS starting from node 1

    // Print the parent of each node
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << " parent is: " << par[i] << endl;
    }

    int d; // Destination node
    cin >> d;

    if (vis[d]) // If the destination node is reachable
    {
        vector<int> path;
        int x = d;

        // Trace the path from destination to start node
        while (x != -1)
        {
            path.push_back(x);
            x = par[x];
        }

        reverse(path.begin(), path.end()); // Reverse to get the path from start to destination

        // Print the path
        cout << "The Shortest Path is: ";
        for (int val : path)
        {
            cout << val << " ";
        }
    }
    else
    {
        cout << "No Shortest Path" << endl; // If the destination is not reachable
    }

    return 0;
}
