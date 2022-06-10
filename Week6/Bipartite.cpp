#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<vector<int>> adjMatrix;
bool bipartite(int V,int start)
{
    vector<int> color(V,-1);
    color[start]=1;
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int w=q.front();
        q.pop();
        for(int v=0;v<V;v++)
        {
            if(adjMatrix[w][v] && color[v]==-1)
            {
                color[v]=1-color[w];
                q.push(v);
            }
            else if(adjMatrix[w][v] && color[v]==color[w])
                return false;
        }
    }
    return false;
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
    if(bipartite(V,0))
        cout<<"Bipartite Graph";
    else
        cout<<"Not a Bipartite Graph";
}
