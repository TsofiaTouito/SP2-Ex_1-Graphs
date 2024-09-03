//tsofiatouito2@gmail.com
//id-324953900
#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::ostream;
using std::vector;
using std::string;

namespace ariel {

class Graph {

    private:
    vector<vector<int>> adjMat;  
    int vertices;               // number of vertices
    bool is_symmetric {true};   // default values
    bool is_weighted {false};
    bool is_loaded {false};
    bool neg_values {false};

    
    public:
    void loadGraph(vector<vector<int>> graph);
    void printGraph();
    vector<vector<int>> getGraph() const;
    bool isSymmetric() const;
    bool isWeighted() const;
    bool isLoaded() const;
    bool hasNegVal() const;

    // operators 
    ariel::Graph& operator+();                            // Graph+
    ariel::Graph operator+(const ariel::Graph& other);    // Graph+other
    ariel::Graph& operator+=(const ariel::Graph& other);  // Graph+=other

    ariel::Graph& operator-();                            // Graph  
    ariel::Graph operator-(const ariel::Graph& other);    // Graph-other
    ariel::Graph& operator-=(const ariel::Graph& other);  // Graph-=other

    Graph& operator*=(const double scalar);               // Graph*=scalar
    Graph& operator*=(const Graph& other);                // Graph*=other
    Graph& operator/=(const double scalar);               // Graph/=scalar
   

    ariel::Graph& operator--();                                  // --Graph
    ariel::Graph operator--(int);                                // Graph--
    ariel::Graph& operator++();                                  // ++Graph
    ariel::Graph operator++(int);                                // Graph++

    ariel::Graph& operator*(int scalar);                   // Graph*scalar
    ariel::Graph operator*(const ariel::Graph& other);     // Graph*other
    bool operator==(const ariel::Graph& other) const;            // Graph==other
    bool operator!=(const ariel::Graph& other) const;            // Graph!=other
    bool operator<(const ariel::Graph& other) const;             // Graph<other
    bool operator<=(const ariel::Graph& other) const;            // Graph<=other
    bool operator>(const ariel::Graph& other) const;             // Graph>other
    bool operator>=(const ariel::Graph& other) const;            // Graph>=other

    // helper functions
    bool isContained(const ariel::Graph& other) const;   // is Graph contains other
    bool sizeCheck(const ariel::Graph& , const ariel::Graph&) const;       // check that both graph is n*n
    int numEdges(const ariel::Graph&) const;

    friend ostream& operator<<(ostream& stream, const Graph& g){ // <<Graph 

    if (!g.is_loaded) {
        throw invalid_argument("The graph isn't loaded .");
    }

    const vector<vector<int>> &graph = g.adjMat;

    for(size_t row = 0 ; row< graph.size() ; row++){
        stream<<"[";
            for(size_t col = 0 ; col < graph.size() ; col++){
            stream<< graph[row][col];
                if(col < graph.size()-1){
                stream<<", ";
                }
            }
        stream<<"]";
        if(row < graph.size()-1){
            stream<<", ";
        }   
    }
    stream<<endl;

    return stream;
    }

};

} 
