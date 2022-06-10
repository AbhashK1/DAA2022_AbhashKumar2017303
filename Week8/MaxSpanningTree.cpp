#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> adjMatrix;
int findMaxVertex(vector<bool> visited, vector<int> weights,int V)
{
    int index = -1;
    int maxW = INT_MIN;
    for (int i = 0; i < V; i++) 
    {
        if (visited[i] == false && weights[i] > maxW) 
        {
            maxW = weights[i];
            index = i;
        }
    }
    return index;
}

void printMaxSpanningTree(vector<int> parent,int V)
{
    int MST = 0;
    for (int i = 1; i < V; i++) 
    {
        MST += adjMatrix[i][parent[i]];
    }
    cout << "Weight of the maximum Spanning-tree "<< MST << '\n'<< '\n';
    cout << "Edges \tWeight\n";
    for (int i = 1; i < V; i++) 
    {
        cout << parent[i] << " - " << i << " \t"<<adjMatrix[i][parent[i]] << " \n";
    }
}

void maxSpanningTree(int V)
{
    vector<bool> visited(V,false);
    vector<int> weights(V,INT_MIN);
    vector<int> parent(V);
 
    weights[0] = INT_MAX;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++) 
    {
        int maxVertexIndex = findMaxVertex(visited, weights,V);
        visited[maxVertexIndex] = true;
 
        for (int j = 0; j < V; j++) 
        {
            if (adjMatrix[j][maxVertexIndex] != 0 && visited[j] == false) 
            {
                if (adjMatrix[j][maxVertexIndex] > weights[j]) 
                {
                    weights[j] = adjMatrix[j][maxVertexIndex];
                    parent[j] = maxVertexIndex;
                }
            }
        }
    }
    printMaxSpanningTree(parent,V);
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
    maxSpanningTree(V);
}
/*Test
5
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
*/
