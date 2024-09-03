//tsofiatouito2@gmail.com
//id-324953900

#include "Algorithms.hpp"

using namespace ariel;
using namespace std;
using std::vector;
using std:: to_string;



void Algorithms::dfs(const Graph& g,vector<bool> &visited, size_t v){
    visited[v] = true;
    for(size_t i = 0; i< visited.size() ; i++){
        if(g.getGraph()[v][i]!=0 && !visited[i]){
            dfs(g ,visited, i);
        }
    }
}



void Algorithms::bfs(const Graph& g, size_t src, vector<int>& dist, vector<int>& prev, vector<string>& color){

    size_t vertices = g.getGraph().size();
    queue<size_t> queue;
    dist[src] = 0;            //initilize source vertex's values
    color[src] = "gray";             
    queue.push(src);
    size_t curr;

    while(!queue.empty()){
        curr = queue.front();
        queue.pop();
        
        for(size_t i = 0 ; i < vertices ; i++){
            if(g.getGraph()[curr][i]!=0 && color[i] == "white"){
                color[i] = "gray";            // mark as visited visited 
                dist[i] = dist[curr] + 1;     
                prev[i] = curr;               //the parent of vertex i in the path is curr
                queue.push(i);
            }
        }
        color[curr] = "black";
    }
}



//prev[i] = j , such that (i, j) is the last edge in the shortest path
string Algorithms::findPath(int flag, size_t start, size_t end, vector<int>& dist, vector<int>& prev) {
    
if((flag == 1 && dist[end] == INT_MAX) || (flag == 0 && dist[end] == numeric_limits<int>::infinity())){
    return "-1";
}

std::stringstream path;
size_t curr = end;

while (curr != static_cast<size_t>(-1)){
    path << curr;
    curr = static_cast<size_t>(prev[curr]);
        if(curr != static_cast<size_t>(-1)) {
            path << "->";
        }
    }

    return path.str();
}



bool Algorithms::isConnected(const Graph& g){

    if(!g.isLoaded()){
        throw std::invalid_argument("The graph is not loaded");
    }

    size_t n = g.getGraph().size();
    vector<bool> visited(n, false);  //Initialize the vector to represent the visited vertices

    dfs(g , visited, 0);
    
    bool allTrue = all_of(visited.begin(), visited.end(), [](bool b) { return b; });

    if(allTrue){
        return true; //for connected graph
    }

    return false; //for not connected graph
}



string Algorithms::shortestPath(const Graph& g, size_t start, size_t end){

if(!g.isLoaded()){
    throw std::invalid_argument("The graph is not loaded");
}

size_t size = g.getGraph().size();
vector<int> prev( size, -1);                  //prev[i] = j , such that (i, j) is the last edge in the shortest path
int flag;

if(!g.isWeighted()){  //the graph is not weighted - use bfs
    flag = 0;
    vector<int> dist( size, numeric_limits<int>::infinity());    //dist[i] is the distance between vertex src to vertex i
    vector<string> color( size, "white");  //represent the state of the vertex 
    bfs(g, start, dist, prev, color);
        return findPath(flag, start, end, dist, prev);
}

else{    //the graph is weighted and has negative values - use Bellman-Ford
    flag = 1;
    vector<int> dist( size, INT_MAX);    //dist[i] is the distance between vertex src to vertex i
        if(BelmanFord(g, start,dist, prev)){
            return findPath(flag, start, end, dist, prev);
        }
    }

return "-1";
}


void Algorithms::relax(const Graph& g, size_t u, size_t v, vector<int>& dist, vector<int>& prev){

    int weight =  g.getGraph()[u][v];
    if(weight!=0 && dist[u]!=INT_MAX && dist[v] > dist[u] + weight){
            dist[v] = dist[u] + weight;
            prev[v] = u;
        }
}

bool Algorithms::BelmanFord(const Graph& g,size_t src, vector<int>& dist, vector<int>& prev){

dist[src] = 0;
size_t vertices = g.getGraph().size();

    for(size_t i = 0; i < vertices-1 ; i++){
        for(size_t u = 0 ; u < vertices; u++){
            for(size_t v = 0 ; v < vertices; v++){
                relax( g, u, v, dist, prev);
            }
        }
    }

    for(size_t u = 0 ; u < vertices; u++){
            for(size_t v = 0 ; v < vertices; v++){
                if(g.getGraph()[u][v] != 0 && dist[v] > dist[u] + g.getGraph()[u][v]){
                    cout<<"There is negative cycle"<<endl;
                    return false;
                }
            }
        }

return true;
}


string Algorithms::isContainsCycle(const Graph& g) {
size_t vertices = g.getGraph().size();  
vector<bool> visited(vertices, false);  //track visited vertices

for (size_t u = 0; u < vertices; u++) {
    if(!visited[u]) {    //if vertex u is not visited, start DFS from it
       string cycle = dfsUtil(g, visited, u, -1);  //-1 represents no parent
            if (!cycle.empty()) {
                return cycle; //return the cycle path if found
            }
        }
    }
    return "0"; //no cycle is found
}



string Algorithms::dfsUtil(const Graph& g, vector<bool> &visited, size_t u, int parent) {
visited[u] = true; 

for (size_t i = 0; i < g.getGraph().size(); i++) {    //explore all adjacent vertices of u
    if (g.getGraph()[u][i] != 0) {             //check for an edge between u and i
            if (!visited[i]) {
                string cycle = dfsUtil(g, visited, i, u); 
                if (!cycle.empty()) {
                    return to_string(u) + "->" + cycle;   //construct the cycle path
                }
            }
            else if (i != parent) {
                return to_string(u) + "->" + to_string(i);   //if a back edge is found -> cycle detected
            }
        }
    }
return "";   //no cycle found in this path
}



string Algorithms::isBipartite(const Graph& g) {
if (!g.isLoaded()) {
    throw invalid_argument("The graph isn't loaded.");
}

set<int> A;
set<int> B;
string elemA, elemB, ans; //convert sets A and B to strings

size_t size = g.getGraph().size();
vector<string> color(size, "None");   // Represents the color of vertices
vector<bool> visited(size, false);    // Track visited vertices

dfsColor(g, visited, color, 0);

for(size_t i = 0; i < size; i++){
    if(color[i] == "Pink") {
        A.insert(i);
    }
    else if(color[i] == "Red"){
        B.insert(i);
    }

    for (size_t j = 0; j < size; j++) {
        if (g.getGraph()[i][j] != 0) {
            if (i != j && color[i] == color[j]) {
                return "0";
            }
        }
    }
}

for(int element : A){
    elemA += std::to_string(element) + ",";
}

for (int element : B) {
    elemB += std::to_string(element) + ",";
}

//remove trailing commas
if(!elemA.empty()){elemA.pop_back();}  
if(!elemB.empty()){elemB.pop_back();}

ans = "The graph is bipartite: A={" + elemA + "}, B={" + elemB + "}";
return ans;
}

void Algorithms::dfsColor(const Graph& g, vector<bool>& visited, vector<string>& color, size_t v) {
    visited[v] = true;

    if (color[v] == "None") {
        color[v] = "Pink";
    }

    for (size_t i = 0; i < g.getGraph().size(); i++) {
        if (g.getGraph()[v][i] != 0 && !visited[i]) {
            if (color[i] == "None") {
                color[i] = (color[v] == "Pink") ? "Red" : "Pink";
            }
            dfsColor(g, visited, color, i);
        }
    }
}


bool Algorithms::negativeCycle(const Graph& g){

size_t size = g.getGraph().size();
vector<int> dist(size, INT_MAX);
vector<int> prev(size, -1);

return !(BelmanFord(g, 0, dist, prev)); //return true if a negative cycle exists
}



