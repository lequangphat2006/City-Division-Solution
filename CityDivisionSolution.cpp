include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> subtree_size;
int n;

void dfs(int u, int parent) {
    subtree_size[u] = 1;
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            subtree_size[u] += subtree_size[v];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    adj.resize(n + 1);
    subtree_size.resize(n + 1);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int min_diff = INT_MAX;
    
    // Try each node as root
    for (int root = 1; root <= n; root++) {
        // Calculate subtree sizes with this root
        dfs(root, -1);
        
        // Collect all subtree sizes (excluding root)
        vector<int> sizes;
        function<void(int, int)> collect = [&](int u, int parent) {
            if (u != root) {
                sizes.push_back(subtree_size[u]);
            }
            for (int v : adj[u]) {
                if (v != parent && subtree_size[v] < subtree_size[u]) {
                    collect(v, u);
                }
            }
        };
        collect(root, -1);
        
        // Try all pairs of subtrees to separate
        for (int i = 0; i < sizes.size(); i++) {
            for (int j = i + 1; j < sizes.size(); j++) {
                int comp1 = sizes[i];
                int comp2 = sizes[j];
                int comp3 = n - comp1 - comp2;
                
                if (comp3 > 0) {
                    int max_comp = max({comp1, comp2, comp3});
                    int min_comp = min({comp1, comp2, comp3});
                    min_diff = min(min_diff, max_comp - min_comp);
                }
            }
        }
    }
    
    cout << min_diff << endl;
    return 0;
}