//
// Created by fortune on 17/11/2019.
//

#include <iostream>
#include "Mtx.h"
#include "Algorithm.h"
#include <sstream>
#include <stdio.h>
#include<queue>
#include<vector>
#include <fstream>
#include <string>
#include<climits>

struct Graph{

    int v;

    bool **adj;

public:

    Graph(int vcount);

    void addEdge(int u,int v);

    void deleteEdge(int u,int w);

    std::vector<int> DFS(int s);

    void DFSUtil(int s,std::vector<int> &dfs,std::vector<bool> &visited);

};

Graph::Graph(int vcount) {

    this->v = vcount;
    this->adj=new bool*[vcount];
    for(int i=0;i<vcount;i++)
        this->adj[i]=new bool[vcount];
    for(int i=0;i<vcount;i++)
        for(int j=0;j<vcount;j++)
            adj[i][j]=false;
}

void Graph::addEdge(int u, int w) {
    this->adj[u][w]=true;
    this->adj[w][u]=true;
}

void Graph::deleteEdge(int u, int w) {
    this->adj[u][w]=false;
    this->adj[w][u]=false;

}

std::vector<int> Graph::DFS(int s) {
    std::vector<bool> visited(this->v);
    std::vector<int> dfs;
    DFSUtil(s,dfs,visited);
    return dfs;
    return std::vector<int>();
}

void Graph::DFSUtil(int s, std::vector<int> &dfs, std::vector<bool> &visited) {
    visited[s]=true;
    dfs.push_back(s);
    for(int i=0;i<this->v;i++){
        if(this->adj[s][i]==true && visited[i]==false)
            DFSUtil(i,dfs,visited);
    }
}
