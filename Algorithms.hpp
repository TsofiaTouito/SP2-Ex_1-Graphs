#include "Graph.hpp"
#include <iostream>
//#include <unordered_set>
#include <vector>
#include <limits> 
#include <queue>
#include <string>

using std::vector;
using std::string;
using std::pair;
using namespace ariel;
using namespace std;

namespace ariel{

class Algorithms{
    public:

    static void dfs(const Graph&, vector<bool>&, int v);

    static void bfs(const Graph& , int, vector<int>&, vector<int>&, vector<string>&);

    static string findPath(int , int , vector<int>&, vector<int>&);

    static void relax(const Graph&, int ,int, vector<int>&, vector<int>&);
    
    static bool BelmanFord(const Graph&, int ,  vector<int>& , vector<int>& );

    static bool isConnected(const Graph&);

    static string shortestPath(const Graph& , int, int);
/*
    static int isContainsCycle(const Graph&);

    static int isBipartite(const Graph&);

    static int negativeCycle(const Graph&);
*/


};
};