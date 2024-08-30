#include "Algorithms.hpp"

using namespace ariel;
using namespace std;



void Algorithms::dfs(const Graph& g,vector<bool> &visited, int v){
    visited[v] = true;
    for(int i = 0; i< visited.size() ; i++){
        if(g.getGraph()[v][i]!=0 && !visited[i]){
            dfs(g ,visited, i);
        }
    }
}



void Algorithms::bfs(const Graph& g, int src, vector<int>& dist, vector<int>& prev, vector<string>& color){

    int vertices = g.getGraph().size();
    queue<int> queue;
    dist[src] = 0;            //initilize source vertex's values
    color[src] = "gray";             
    queue.push(src);
    int curr;

    while(!queue.empty()){
        curr = queue.front();
        queue.pop();
        
        for(int i = 0 ; i < vertices ; i++){
            if(g.getGraph()[curr][i]!=0 && color[i] == "white"){
                color[i] = "gray";            // visited 
                dist[i] = dist[curr] + 1;     
                prev[i] = curr;               //the parent of vertex i in the path is curr
                queue.push(i);
            }

        }
        color[curr] = "black";
    }
}



string Algorithms::findPath(int start, int end, vector<int>& dist, vector<int>& prev){
 //prev[i] = j , such that (i, j) is the last edge in the shortest path
    string path = "-1";
    int curr = end;

    if(dist[end] != numeric_limits<int>::infinity()){
    path = to_string(curr);
    curr = prev[curr];

        while(curr!=-1){
            path.insert(0, to_string(curr)+"->");
            curr = prev[curr];
        }
    }
return path;
}




bool Algorithms::isConnected(const Graph& g){

    if(!g.isLoaded()){
        throw std::invalid_argument("The graph is not loaded");
    }

    int n = g.getGraph().size();
    vector<bool> visited(n, false);  //Initialize the vector to represent the visited vertices

    dfs(g , visited, 0);
    
    bool allTrue = all_of(visited.begin(), visited.end(), [](bool b) { return b; });

    if(allTrue){
        return true; //for connected graph
    }

    return false; //for not connected graph
}



string Algorithms::shortestPath(const Graph& g, int start, int end){

    if(!g.isLoaded()){
        throw std::invalid_argument("The graph is not loaded");
    }

    int size = g.getGraph().size();
    vector<int> dist( size, numeric_limits<int>::infinity());    //dist[i] is the distance between vertex src to vertex i
    vector<int> prev( size, -1);                  //prev[i] = j , such that (i, j) is the last edge in the shortest path


    if(!g.isWeighted()){  //the graph is not weighted - use bfs
    
            vector<string> color( size, "white");                        //represent the state of the vertex 
            bfs(g, start, dist, prev, color);
    }

    else{    //the graph is weighted and has negative values - use Bellman-Ford
        if(BelmanFord(g, dist, prev)){
    

        }

    }
    
return findPath(start, end, dist, prev);

}


void Algorithms::relax(const Graph& g, int u, int v, vector<int>& dist, vector<int>& prev){

    if(g.getGraph()[u][v]!=0 && dist[u]!= numeric_limits<int>::infinity()){

        if(dist[v] > dist[u] + g.getGraph()[u][v]){
            dist[v] = dist[u] + g.getGraph()[u][v];
            prev[v] = u;
        }
    }
}

bool Algorithms::BelmanFord(const Graph& g, vector<int>& dist, vector<int>& prev){
int vertices = g.getGraph().size();

    for(int i = 0; i < vertices-1 ; i++){
        for(int u = 0 ; u < vertices; u++){
            for(int v = 0 ; v < vertices; v++){
                relax( g, u, v, dist, prev);
            }
        }
    }

    for(int u = 0 ; u < vertices; u++){
            for(int v = 0 ; v < vertices; v++){
                if(g.getGraph()[u][v] != 0 && dist[u]!=numeric_limits<int>::infinity() && dist[v] > dist[u] + g.getGraph()[u][v]){
                    cout<<"There is negative cycle"<<endl;
                    return false;
                }
            }
        }

return true;
}






/*
    int Algorithms::isContainsCycle(const Graph& g);

    int Algorithms::isBipartite(const Graph& g);

    int Algorithms::negativeCycle(const Graph& g);

*/

using namespace std;
int main(){

    Graph g;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 3 vertices and 4 edges."
    cout <<"hi \n"<< Algorithms::isConnected(g) << endl; 
    cout << Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2.


  cout<<"graph number 2"<<endl;
 vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).

    cout << g.isSymmetric() << endl;
    cout << g.isWeighted() << endl;
    
}

