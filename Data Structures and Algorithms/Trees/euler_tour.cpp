/*
    Euler Tour of a rooted tree
    -> Flatten a tree down to an array on which various algorithms can be applied
    -> Uses the concept of discovery_time(tin) and finish_time(tout) for every node in the tree
    -> O(n) time - a single DFS can create the euler tour
    -> O(n) space - the tin[] and tout[] arrays require linear space
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
    Lemma.
    For u,v in a rooted tree u is an ancestor of v iff tin[u] <= tin[v] <= tout[v] <= tout[u]

    Note.
    We cannot directly use the Euler tour of the tree to efficiently find the nodes in the subtree rooted at a given node
    For that we need to modify the euler tour so that we can directly get the above information
*/
void dfs(int root, vector< vector<int> >& adj, vector<int>& color, vector<int>& parent, vector<int>& tin, vector<int>& tout, int& tree_time){
    color[root] = 1;
    tin[root] = tree_time++;

    for(int j : adj[root]){
        if(color[j] == 0){
            parent[j] = root;
            dfs(j, adj, color, parent, tin, tout, tree_time);
        }
    }

    color[root] = 2;
    tout[root] = tree_time-1;
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
    vector<int> parent(n+1, 0);
    vector<int> tin(n+1, 0);
    vector<int> tout(n+1, 0);

    int tree_timer = 1;

    // ---

    dfs(1, adj, color, parent, tin, tout, tree_timer);

    for(int i=1 ; i<=n ; i++){
        cout << tin[i] << " ";
    }
    cout << endl;

    for(int i=1 ; i<=n ; i++){
        cout << tout[i] << " ";
    }
    cout << endl;

    return 0;
}


