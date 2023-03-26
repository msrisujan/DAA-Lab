#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

vector<pair<int,int>> prims(vector<vector<int>> &graph,int n)
{
    vector<pair<int,int>>mst;
    int w=0;
    vector<int>visited;
    visited.push_back(0);
    while(mst.size()<n-1)
    {
        int min=INF;
        int v1,v2;
        for(int i=0;i<visited.size();i++)
        {
            int u=visited[i];
            for(int j=0;j<graph[u].size();j++)
            {
                auto it=find(visited.begin(),visited.end(),j);
                if(it==visited.end() && graph[u][j]<min)
                {
                    min=graph[u][j];
                    v1=u;
                    v2=j;
                }
            }
        }
        w+=min;
        visited.push_back(v2);
        pair<int,int>e(v1,v2);
        mst.push_back(e);
    }
    cout<<w<<endl;
    return mst;
}
int main()
{
    int n,m;
    cout<<"Enter no of vertices :";
    cin>>n;
    vector<vector<int>>graph(n,vector<int>(n,INF));
    cout << "Enter the number of edges: ";
    cin >> m;
    cout << "Enter 'vertex1 vertex2 weight': eg. '0 1 3' " << endl;
    for(int i=0;i<m;m++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v]=w;
        graph[v][u]=w;
    }
    vector<pair<int,int>>mst=prims(graph,n);
    for (auto edge : mst)
    {
        cout << edge.first << " " << edge.second << endl;
    }

}