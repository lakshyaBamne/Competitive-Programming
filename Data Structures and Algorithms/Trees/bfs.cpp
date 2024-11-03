/*
    Breadth First Search
    -> cannot be coded recursively
    -> useful to find out the level order traversal of a rooted tree
    -> O(n) time for trees
    -> O(n) space for trees
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(int root, vector< vector<int> >& adj, vector<int>& color){
    queue<int> proc;
    proc.push(root);
    color[root] = 1; // visited

    while(!proc.empty()){
        int top = proc.front();
        proc.pop();

        for(int j : adj[top]){
            if(color[j] == 0){
                color[j] = 1;
                proc.push(j);
            }
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

