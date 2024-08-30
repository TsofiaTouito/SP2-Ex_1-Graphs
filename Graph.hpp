#include <iostream>
#include <vector>
#include <algorithm>

//#pragma once
using std::vector;



namespace ariel{

class Graph{

    private:
    vector<vector<int>> Graph;  
    int vertices;               // number of vertices
    bool is_symmetric {true};   //defult values
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

};

};