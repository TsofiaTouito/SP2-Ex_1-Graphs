#include "Graph.hpp"

using std::vector;
using namespace std;
using namespace ariel;



void Graph::loadGraph(const vector<vector<int>> graph){
if(graph.empty()|| graph.size()!= graph[0].size()){

    throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
}

    this->Graph = graph; 
    this->vertices = graph.size();

    //check if the graph is symmetric / weighted
    for(int i = 0; i < this->vertices ; i++){
        for(int j = 0; j < this->vertices ; j++){
            if(Graph[i][j]!=Graph[j][i]){
                this->is_symmetric = false; // the graph is directed
            }
            if(Graph[i][j]!=0 && Graph[i][j]!=1){
                this->is_weighted = true; // the graph is weighted
            }
            if(Graph[i][j] < 0){
                this->neg_values = true;
            }
        }
    }
    this->is_loaded = true;
}



void Graph::printGraph(){

    if(!this->is_loaded){
        throw invalid_argument("The graph is not loaded");
    }

    int edges = 0;

     for(int i = 0; i < this->vertices ; i++){
        for(int j = 0; j < this->vertices ; j++){
            if(Graph[i][j]!= 0){
                edges++;
            }
        }
     }

    cout<< "Graph with " << this->vertices << " vertices and " << edges << " edges."<<endl;
}


vector<vector<int>> Graph::getGraph() const{
    return this->Graph;
}


bool Graph::isSymmetric() const {
    return this->is_symmetric;
 }


bool Graph::isWeighted()const {
    return this->is_weighted;
}


bool Graph::isLoaded() const{ 
    return this->is_loaded;
}

bool Graph::hasNegVal() const{
    return this->neg_values;
}
