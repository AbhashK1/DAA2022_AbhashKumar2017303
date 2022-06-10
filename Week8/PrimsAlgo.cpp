#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> adjMatrix;
int minKey( vector<int> key, vector<bool> mstSet,int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}
void print(vector<int> parent,int V)
{
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout<<parent[i]<<" - "<<i<<" \t"<<adjMatrix[i][parent[i]]<<" \n";
}
void prim(int V)
{
    vector<int> parent(V);
    vector<int> key(V,INT_MAX);
    vector<bool> mstSet(V,false);
    key[0]=0;
    parent[0]=-1;
    for(int count=0;count<V-1;count++)
    {
        int u=minKey(key,mstSet,V);
        mstSet[u]=true;
        for(int v=0;v<V;v++)
        {
            if(adjMatrix[u][v] && mstSet[v] == false && adjMatrix[u][v] < key[v])
                parent[v]=u, key[v] = adjMatrix[u][v];
        }
    }
    print(parent,V);
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
    prim(V);
}
