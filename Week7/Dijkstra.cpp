#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
vector<vector<int>> adjMatrix;
int minDistance(vector<int> dist,vector<bool> sptSet,int V)
{
    int min=INT_MAX,min_index;
    for(int v=0;v<V;v++)
    {
        if(sptSet[v]==false && dist[v]<=min)
            min=dist[v],min_index=v;
    }
    return min_index;
}
void printSol(vector<int> dist,int V)
{
    cout<<"Vertex\t Distance from Source"<<endl;
    for(int i=0;i<V;i++)
        cout<<i<<"\t\t"<<dist[i]<<endl;
}
void dijkstra(int src,int V)
{
    vector<int> dist(V,INT_MAX);
    vector<bool> sptSet(V,false);
    dist[src]=0;
    for(int count=0;count<V-1;count++)
    {
        int u=minDistance(dist,sptSet,V);
        sptSet[u]=true;
        for(int v=0;v<V;v++)
            if(!sptSet[v]&& adjMatrix[u][v] && dist[u]!=INT_MAX && dist[u]+adjMatrix[u][v]<dist[v])
                dist[v]=dist[u]+adjMatrix[u][v];
    }
    printSol(dist,V);
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
    int src;
    cin>>src;
    dijkstra(src,V);
}
/*Test 
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0 
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
*/
