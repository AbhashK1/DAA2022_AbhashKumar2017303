/*Given a (directed/undirected) graph, design an algorithm and implement it using a program to
find if a path exists between two given vertices or not. (Hint: use DFS)*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> adjMatrix;
vector<int> sol;
void dfs(int start,vector<bool>& visited)
{
    sol.push_back(start);
    visited[start]=true;
    for(int i=0;i<adjMatrix[start].size();i++)
    {
        if(adjMatrix[start][i]==1 && (!visited[i]))
        {
            dfs(i,visited);
        }
    }
}
int main()
{
    int V;
    cin>>V;
    adjMatrix = vector<vector<int>>(V,vector<int>(V,0));
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cin>>adjMatrix[i][j];
        }
    }
    int src,dest;
    cin>>src>>dest;
    src=src-1;
    dest=dest-1;
    vector<bool> visited(V,false);
    dfs(src,visited);
    if(find(sol.begin(),sol.end(),dest)!=sol.end())
        cout<<"Path Exists";
    else
        cout<<"Path dosen't Exist";
}
