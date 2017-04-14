/**
 * bfs.cpp
 * Coded by: Andrew McBurney
 */

#include <queue>
#include <string>
#include <vector>

// Pointer to parent of vertex in graph
#define VertexPtr shared_ptr<Vertex>

using namespace std;

// Color enumeration
enum Color { white, gray, black };

// Graph Vertex representation (edges between adjacent verticies)
struct Vertex {
  Color color;
  VertexPtr parent;
  vector<VertexPtr> adjacent;
};

// Undirected graph representation (edges are pair of adjacent vertices)
struct Graph {
  vector<Vertex> verticies;
};

/**
 * Performs BFS on a unidirected graph, given a starting vertex in the Graph
 */
void BFS(Graph G, VertexPtr s) {
  // Queue of vertices to be visited
  queue<VertexPtr> Q;

  // Initialize the graph vertices
  for (auto &v : G.verticies) {
    v.color = white;
    v.parent = nullptr;
  }

  // Visit the starting node
  s->color = gray;
  Q.push(s);

  while (!Q.empty()) {
    VertexPtr u = Q.front();
    Q.pop();

    for (auto &v : u->adjacent) {
      /**
       * If the vertex is not visited yet (ie. white), add it to the queue of
       * vertices to be visited at a later time
       */
      if (v->color == white) {
        v->color = gray;
        v->parent = u;
        Q.push(v);
      }
    }

    // Finished visiting vertex
    u->color = black;
  }
}
