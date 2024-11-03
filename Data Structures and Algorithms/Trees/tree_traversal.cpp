/*
    Since trees are just special types of graphs, there are really just 2 ways to traverse them
    There are 4 logical ways to traverse a rooted tree (1 BFS, 3 DFS)
    -> Level Order Traversal (BFS)

    These traversals only make sense for a binary tree. For general n-ary tree there is only DFS
    -> Inorder Traversal (Left->Root->Right)
    -> Preorder Traversal (Root->Left->Right)
    -> Postorder Traversal (Left->Right->Root)
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void level_order(int root, vector< vector<int> >& adj, vector<int>& color){
    queue<int> proc;
    proc.push(root);
    color[root] = 1; // in queue

    while(!proc.empty()){
        int top = proc.front();
        proc.pop();

        color[top] = 2; // visited

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

    level_order(1, adj, color);


    return 0;
}