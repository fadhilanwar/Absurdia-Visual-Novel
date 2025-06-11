#include "graph.hpp"

#include <iostream>


Graph* Graph_Create(std::vector<Scene *> scenes)
{
    Graph *graph = new Graph();
    graph->scenes = scenes;

    return graph;
}

void Graph_AddConnection(Graph *graph, int fromScene, int toScene)
{
    graph->connections[fromScene].push_back(toScene);
}

void Graph_Print(Graph *graph) 
{
    for (int i = 0; i < graph->scenes.size(); i++) 
    {
        std::cout << "Scene no: " << i << ":";
        for (int neighbor : graph->connections[i]) 
        {
            std::cout << " -> " << neighbor;
        }
        std::cout << std::endl;
    }
} 

// std::vector<int> Graph_GetConnectedScenes(Graph *graph, int sceneNumber)
// {
//     return graph->connections[sceneNumber];
// }