#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
        unordered_map<int,list<int>> adj;
    
        void addEdge(int u, int v, bool direction){
            adj[u].push_back(v);
            //means graph is undirected
            if(direction == 0){
                adj[v].push_back(u);
            }
        }
        void printGraph(){
            for(auto i: adj){
                cout<<i.first<<"->";
                for(auto j:i.second){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
};

int main(){
    graph g;
     
     // Number of nodes
     int n;
     cout << "Enter number of nodes: ";
     cin >> n;
 
     // Number of edges
     int m;
     cout << "Enter number of edges: ";
     cin >> m;
 
     // Taking input for edges
    cout << "Enter the edges (u, v): " << endl;
    for(int i=0;i<m; i++){
        int u, v;
        cin>>u >> v;
        g.addEdge(u,v,1);
    }
    g.printGraph();
    return 1;
}