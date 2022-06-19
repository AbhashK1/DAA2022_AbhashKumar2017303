/*Implement the previous problem using Kruskal's algorithm*/

#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> adjMatrix;
vector<pair<int,pair<int,int>>> adj;
const int MAX = 1e6-1;
vector<int> parent(MAX);
int find(int a)
{
    while(parent[a]!=a)
    {
        parent[a]=parent[parent[a]];
        a=parent[a];
    }
    return a;
}
void uni(int a,int b)
{
    int d=find(a);
    int e=find(b);
    parent[d]=parent[e];
}
void kruskal()
{
    sort(adj.begin(),adj.end());
    for(int i=0;i<MAX;i++)
        parent[i]=i;
    vector<pair<int,int>>tree_edges;
    int totalweight=0;
    for(auto x:adj)
    {
        int a=x.second.first;
        int b=x.second.second;
        int cost=x.first;
        if(find(a)!=find(b))
        {
            totalweight+=cost;
            uni(a,b);
            tree_edges.push_back({a,b});
        }
    }
    cout<<"Edges are : "<<endl;
    for(auto x:tree_edges)
        cout<<x.first<<" "<<x.second<<endl;
    cout<<"Total weight of MST = ";
    cout<<totalweight<<endl;
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
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(adjMatrix[i][j]>0)
            {
                adj.push_back({adjMatrix[i][j],{i,j}});
            }
        }
    }
    kruskal();
}
/*Test
5
0 2 0 0 0
0 0 3 0 1
0 0 0 3 0
0 0 0 0 0
0 0 2 1 0
*/
