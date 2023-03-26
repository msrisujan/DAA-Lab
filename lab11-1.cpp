#include<bits/stdc++.h>
using namespace std;
#define N 1e9


pair<int,int> min_edge(vector<vector<int>>graph,vector<int>visited)
{
    vector<int>min_e;
    int min1=N;
    int x,y;
    for(int i=0;i<visited.size();i++)
    {
        int u=visited[i];
        for(int j=0;j<graph[u].size();j++)
        {
            auto it=find(visited.begin(),visited.end(),j);
            if(it==visited.end() && graph[u][j]<min1)
            {
                min1=graph[u][j];
                x=u;
                y=j;
            }
        }
    }
    return {x,y};
}

int main()
{
    int v;
    cout<<"Enter no of vertices :";
    cin>>v;
    vector<vector<int>>graph(v,vector<int>(v,N));
    int e;
    cout<<"Enter no of edges :";
    cin>>e;
    cout<<"Enter edge and their weights(vertices start from 0 to "<<v-1<<endl;
    int x=2;
    for(int i=0;i<e;i++)
    {
        int v1,v2,w;
        cin>>v1>>v2>>w;
        graph[v1][v2]=w;
        graph[v2][v1]=w;
    }
    vector<vector<int>>spantree(v,vector<int>(v,N));
    vector<int>visited;
    visited.push_back(0);
    int count=0;
    int weight=0;
    cout<<"Edges of min spanning tree"<<endl;
    while(count<v-1)
    {
        pair<int,int>a;
        a=min_edge(graph,visited);
        visited.push_back(a.second);
        cout<<a.first<<"-"<<a.second<<"  "<<graph[a.first][a.second]<<endl;
        weight+=graph[a.first][a.second];
        count++;
    }
    cout<<"Weight of minimum spanning tree"<<endl;
    cout<<weight<<endl;

    return 0;

}