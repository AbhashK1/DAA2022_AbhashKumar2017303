/*Assume that a project of road construction to connect some cities is given to your friend. Map of these cities and roads which will connect them (after construction) 
is provided to him in the form of a graph. Certain amount of rupees is associated with construction of each road. Your friend has to calculate the minimum budget 
required for this project. The budget should be designed in such a way that the cost of connecting the cities should beminimum and number of roads required to connect
all the cities should beminimum (if there are N cities then only N-1 roads need to be constructed). He asks you for help. Now, you have to help your friend by 
designing an algorithm which will find minimum cost required to connect these cities. (use Prim's algorithm)*/


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
