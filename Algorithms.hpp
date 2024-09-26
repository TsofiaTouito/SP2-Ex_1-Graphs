//tsofiatouito2@gmail.com
//id-324953900
#pragma once
#include "Graph.hpp"
#include <iostream>
#include <set>
#include <vector>
#include <limits> 
#include <queue>
#include <stack>
#include <string>
#include <climits>
#include <sstream>

using namespace ariel;
using namespace std;

using std::vector;
using std::string;
using std::pair;

namespace ariel{

class Algorithms{
    

    private:

    //help functions
    static string findPath(int ,size_t , size_t , vector<int>&, vector<int>&);
    
    static void dfs(const Graph&, vector<bool>&, size_t v);

    static void bfs(const Graph& , size_t, vector<int>&, vector<int>&, vector<string>&);
    
    static void relax(const Graph&, size_t ,size_t, vector<int>&, vector<int>&);

    static string dfsUtil(const Graph& , vector<bool>&, size_t, int);

    static void dfsColor(const Graph& ,vector<bool>&, vector<string>&, size_t);

    public:

    static bool BelmanFord(const Graph&, size_t, vector<int>& , vector<int>& );

    static bool isConnected(const Graph&);

    static string shortestPath(const Graph& , size_t, size_t);

    static string isContainsCycle(const Graph&);

    static string isBipartite(const Graph&);


    static bool negativeCycle(const Graph&);


};
}
