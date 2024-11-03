/*
    Depth First Search
    -> can be coded recursively and quickly
    -> used to build inorder, preorder and postorder traversal of a tree
    -> O(n) time for trees
    -> O(n) space for trees
*/

#include<iostream>
#include<vector>

using namespace std;

// Basic DFS implementation
void dfs(int root, vector< vector<int> >& adj, vector<int>& color){
    color[root] = 1; // visited
    for(int j : adj[root]){
        if(color[j] == 0){
            dfs(j, adj, color);
        }
    }
}

// DFS implementation to also create a dfs tree from the root using the parent arrays
void dfs(int root, vector< vector<int> >& adj, vector<int>& color, vector<int>& parent){
    color[root] = 1;
    for(int j : adj[root]){
        if(color[j] == 0){
            parent[j] = root;
            dfs(j, adj, color, parent);
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector< vector<int> > adj(n+1, vector<int>(0));
    for(int i=1 ; i<=n-1 ; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n+1, 0);

    // ---


    return 0;
}


