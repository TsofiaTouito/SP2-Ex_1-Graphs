//tsofiatouito2@gmail.com
//id-324953900

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"


using namespace std;

TEST_CASE("Test graph operator + graph")
{
    ariel::Graph graph1;
    vector<vector<int>> data1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph1.loadGraph(data1);

    ariel::Graph graph2;
    vector<vector<int>> data2 = {
        {0, 1, 1},
        {1, 0, 4},
        {1, 5, 0}};
    graph2.loadGraph(data2);

    ariel::Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {0, 2, 1},
        {2, 0, 5},
        {1, 6, 0}};
    expectedGraph.loadGraph(expectedData);
    ariel::Graph resultGraph = graph1 + graph2;
    CHECK(resultGraph == expectedGraph);
}

TEST_CASE("Test graph operator - graph"){
    ariel::Graph graph1;
    vector<vector<int>> data1 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    graph1.loadGraph(data1);

    ariel::Graph graph2;
    vector<vector<int>> data2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    graph2.loadGraph(data2);

    ariel::Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    expectedGraph.loadGraph(expectedData);
    ariel::Graph resultGraph = graph1 - graph2;
    CHECK(expectedGraph == resultGraph);
}

TEST_CASE("Test graph operator += graph"){
    ariel::Graph graph1;
    vector<vector<int>> data1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph1.loadGraph(data1);

    ariel::Graph graph2;
    vector<vector<int>> data2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 4, 0}};
    graph2.loadGraph(data2);

    ariel::Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 5, 0}};
    expectedGraph.loadGraph(expectedData);
    graph1 += graph2;
    CHECK(expectedGraph == graph1);
}

TEST_CASE("Test print graph to ostream with operator"){
    ariel::Graph graph;
    vector<vector<int>> data = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(data);
    std::cout<<"Test print graph to ostream with operator"<<std::endl;
    CHECK_NOTHROW(cout<<++graph<<endl); // add 1 to all edges
    CHECK_NOTHROW(cout<<graph--<<endl); // subtract 1 from all edges but won't be seen in the next print
    CHECK_NOTHROW(cout<<graph<<endl); // now the edges are back to the original
}

TEST_CASE("Test graph operator * "){
    ariel::Graph graph1;
    vector<vector<int>> data1 = {
        {0, 1, 0, 8},
        {1, 0, 1, 0},
        {0, 1, 0, 2},
        {0, 1, 0, 3}};
    graph1.loadGraph(data1);
    
    ariel::Graph graph2;
    vector<vector<int>> data2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    graph2.loadGraph(data2);
    
    CHECK_THROWS_WITH(graph1*graph2, "The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
}

TEST_CASE("Test graph operator * scalar"){
    ariel::Graph graph1;
    vector<vector<int>> data = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph1.loadGraph(data);
    
    ariel::Graph resultGraph = graph1 * 5;
    vector<vector<int>> expectedData = {
        {0, 5, 0},
        {5, 0, 5},
        {0, 5, 0}};
    
    ariel::Graph expectedGraph;
    expectedGraph.loadGraph(expectedData);
    CHECK(resultGraph == expectedGraph);
}

TEST_CASE("Testing Graph::operator>") {
    Graph g1;
    g1.loadGraph({{0, 1, 0}, {1, 0, 1}, {0, 1, 0}}); // 3 vertices, 2 edges


    // Test if graphs with same edges and size are equal
    Graph g3;
    g3.loadGraph({{0, 1, 0}, {1, 0, 1}, {0, 1, 0}}); // identical to g1
    SUBCASE("g1 == g3") {
        CHECK(!(g1 > g3));
        CHECK(g1 >= g3);
        CHECK(g1 <= g3);
    }
}

TEST_CASE("Testing Graph::operator<") {
    Graph g1;
    g1.loadGraph({{0, 1, 0}, {1, 0, 0}, {0, 0, 0}}); // 2 vertices, 1 edge

    Graph g2;
    g2.loadGraph({{0, 1, 0}, {1, 0, 1}, {0, 1, 0}}); // 3 vertices, 2 edges

    SUBCASE("g1 < g2") {
        CHECK(g1 < g2);
    }

    SUBCASE("g2 > g1") {
        CHECK(g2 > g1);
    }
}

TEST_CASE("Testing Graph::isContained") {
    Graph g1;
    g1.loadGraph({{0, 1, 0}, {1, 0, 1}, {0, 1, 0}}); // 3 vertices, 2 edges

    Graph g2;
    g2.loadGraph({{0, 1}, {1, 0}}); // 2 vertices, 1 edge

    SUBCASE("g1 not contained in g2") {
        CHECK(g1.isContained(g2));
    }

    Graph g3;
    g3.loadGraph({{0, 1, 0}, {1, 0, 0}, {0, 0, 0}}); // 3 vertices, 1 edge

    SUBCASE("g1 not contained in g3") {
        CHECK(g1.isContained(g3));
    }
}

TEST_CASE("Testing Graph::sizeCheck") {
    Graph g1;
    g1.loadGraph({{0, 1}, {1, 0}}); // 2 vertices, 1 edge

    Graph g2;
    g2.loadGraph({{0, 1}, {1, 0}}); // 2 vertices, 1 edge

    SUBCASE("Graphs of equal size") {
        CHECK(g1.sizeCheck(g1, g2) == true);
    }

    Graph g3;
    g3.loadGraph({{0, 1, 0}, {1, 0, 1}, {0, 1, 0}}); // 3 vertices

    SUBCASE("Graphs of different size") {
        CHECK(g1.sizeCheck(g1, g3) == false);
    }
}

TEST_CASE("Testing Graph::numEdges") {
    Graph g;
    g.loadGraph({{0, 1, 0}, {1, 0, 1}, {0, 1, 0}}); // 3 vertices, 2 edges

    SUBCASE("Correct number of edges in g") {
        CHECK(g.numEdges() == 4); // Each edge counted twice in undirected graph
    }

    Graph g2;
    g2.loadGraph({{0, 1}, {1, 0}}); // 2 vertices, 1 edge
    SUBCASE("Correct number of edges in g2") {
        CHECK(g2.numEdges() == 2); // Each edge counted twice
    }
}

TEST_CASE("Testing Graph::hasNegVal") {
    Graph g;
    g.loadGraph({{0, 1, 0}, {1, 0, 1}, {0, 1, 0}}); // 3 vertices, 2 edges

    SUBCASE("No negative values") {
        CHECK(g.hasNegVal() == false);
    }

    Graph g2;
    g2.loadGraph({{0, -1}, {-1, 0}}); // 2 vertices, 1 negative edge
    SUBCASE("Has negative values") {
        CHECK(g2.hasNegVal() == true);
    }
}


TEST_CASE("Test graph operator postfix--"){
    ariel::Graph g1;
    vector<vector<int>> matrix1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix1);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1 != g2--);
    CHECK(g1 == g2);
}

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    // Test #1
    vector<vector<int>> matrix1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(matrix1);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    --g;
    CHECK(ariel::Algorithms::isConnected(g) == false);

    // Test #2
    ariel::Graph g1;
    vector<vector<int>> matrix2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g1.loadGraph(matrix2);

    ariel::Graph g2;
    vector<vector<int>> matrix3 = {
        {0, 5, 1, 0, 0},
        {1, 0, 7, 0, 0},
        {1, 5, 0, -4, 0},
        {0, 0, 10, 0, 0},
        {-9, 0, 0, 0, 0}};
    g2.loadGraph(matrix3);
    CHECK(ariel::Algorithms::isConnected(g2) == false);

    
} 

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;

    // Test #6
    vector<vector<int>> matrix1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(matrix1);
    CHECK(ariel::Algorithms::shortestPath(g, 2, 0) == "2->1->0");
    ariel::Graph g5 = g*5;
    CHECK(ariel::Algorithms::shortestPath(g, 2, 0) == "2->1->0");

    // Test #7
    ariel::Graph g21;
    vector<vector<int>> matrix2 = {
        {0, 5, 1, 0, 0},
        {15, 0, 1, 0, 0},
        {1, 18, 0, 5, 0},
        {0, 0, 6, 0, 0},
        {0, 0, 0, 0, 0}};
    g21.loadGraph(matrix2);

    ariel::Graph g2;
    vector<vector<int>> matrix3 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g2.loadGraph(matrix3);
    CHECK(ariel::Algorithms::shortestPath(g2, 0, 4) == "-1");

    ariel::Graph g212 = g21-g2;
    CHECK(ariel::Algorithms::shortestPath(g212, 0, 4) == "-1");


    // Test #8 #9 #10 #11 #12
    ariel::Graph g3;
    vector<vector<int>> matrix4 = {
        {0, 5, 0, 0},
        {0, 0, 1, 0},
        {-3, 0, 0, 0},
        {0, 0, -2, 0}};
    g3.loadGraph(matrix4);
    CHECK(ariel::Algorithms::shortestPath(g3, 0, 2) == "0->1->2");
    CHECK(ariel::Algorithms::shortestPath(g3, 2, 1) == "2->0->1");
    CHECK(ariel::Algorithms::shortestPath(g3, 2, 0) == "2->0");
    CHECK(ariel::Algorithms::shortestPath(g3, 1, 3) == "-1");

    ariel::Graph g33;
    vector<vector<int>> matrix5 = {
        {0, 5, 0, 0},
        {0, 0, 1, 0},
        {6, 0, 0, 0},
        {0, 0, 4, 0}};
    g33.loadGraph(matrix5);
    ariel::Graph g333 = g33 +g3;
    CHECK(ariel::Algorithms::shortestPath(g333, 1, 3) == "-1");
    

    // Test #13 #14
    ariel::Graph g4;
    vector<vector<int>> matrix6 = {
        {0, -5, 0, 0},
        {0, 0, 0, 0},
        {-3, 0, 0, -8},
        {-6, 0, 0, 0}};
    g4.loadGraph(matrix6);

     //Negative path
    CHECK(ariel::Algorithms::shortestPath(g4, 1, 0) == "-1");
    
    ariel::Graph g44 = -g4;
    CHECK(ariel::Algorithms::shortestPath(g44, 1, 0) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g44, 3, 1) == "3->0->1"); // no negative path anymore
    
}

TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> matrix1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(matrix1);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");
    ariel::Graph g0;
    vector<vector<int>> matrix2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g0.loadGraph(matrix2);
    ariel::Graph g01 = g0+g;
    CHECK(ariel::Algorithms::isContainsCycle(g01) == "The cycle is: 0->2->1->0");
   
    ariel::Graph g2;
    vector<vector<int>> matrix3 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g2.loadGraph(matrix3);
    CHECK(ariel::Algorithms::isContainsCycle(g2) == "The cycle is: 0->2->1->0");
    
    ariel::Graph g3;
    vector<vector<int>> matrix4 = {
        {0, 0, 1, 1, 0},
        {10, 0, 10, 0, 0},
        {1, 10, 0, 5, 2},
        {1, 12, 1, 0, 0},
        {0, 0, 2, 0, 0}};
    g3.loadGraph(matrix4);
    CHECK(ariel::Algorithms::isContainsCycle(g3)=="The cycle is: 0->1->2->0");

}


TEST_CASE("Cycle Detection Test") {
    ariel::Graph g4;
    vector<vector<int>> matrix5 = {
        {0, -4, 0, 0},
        {0, 0, 1, 1},
        {-3, 0, 0, -8},
        {-6, 0, 0, 0}};
    g4.loadGraph(matrix5);
    CHECK(ariel::Algorithms::isContainsCycle(g4) == "The cycle is: 0->2->1->0");
    
    // Increment the graph
    g4++;
    g4++;
    g4++;
    g4++;
    
    CHECK(ariel::Algorithms::isContainsCycle(g4) == "The cycle is: 0->3->2->1");
}


TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> matrix1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(matrix1);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0,2}, B={1}");

    vector<vector<int>> matrix2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(matrix2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> matrix1 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(matrix1));
    
    ariel::Graph g1;
    vector<vector<int>> matrix2 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0}};
    g1.loadGraph(matrix2);
    ariel::Graph g2;
    vector<vector<int>> matrix3 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}};    
    g2.loadGraph(matrix3);
    CHECK_THROWS(g1+=g2);
}

TEST_CASE("Test negative cycle in the graph")
{
    ariel::Graph g;
    vector<vector<int>> matrix1 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(matrix1);
    CHECK(ariel::Algorithms::negativeCycle(g) == false);
    g=g*(-1);
    CHECK(ariel::Algorithms::negativeCycle(g) == true);

    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 5, 8, 0},
        {1, 0, 1, 0},
        {3, -3, 0, 0},
        {0, 0, 0, 0}};
    g2.loadGraph(matrix2);
    CHECK(ariel::Algorithms::negativeCycle(g2) == true);
    g2=-g2;
    CHECK(ariel::Algorithms::negativeCycle(g2) == true);
    
    ariel::Graph g3;
    vector<vector<int>> matrix3 = {
        {0, -2, 0, 0}, 
        {0, 0, 1, 0}, 
        {0, 0, 0, -5}, 
        {-2, 0, 0, 0}} ;

    g3.loadGraph(matrix3);
    CHECK(ariel::Algorithms::negativeCycle(g3) == true);
}
