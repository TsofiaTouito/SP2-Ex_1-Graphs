Tsofia touito
tsofiatouito2@gmail.com

Here is the `README.md` file for your project:

---

# Graph Algorithms and Operations - Assignment 1

This project involves the implementation of a graph class and various algorithms that operate on graphs. The program supports both directed and undirected graphs, as well as weighted graphs. The graph is represented using an adjacency matrix. Several graph algorithms and operators are implemented, allowing various manipulations and analysis of graphs.

## Project Structure

The project is organized into the following files:

- **Graph.cpp**: Contains the implementation of the `Graph` class, which represents a graph and provides various methods to manipulate and query the graph.
- **Graph.hpp**: The header file for the `Graph` class, defining its members and functions.
- **Algorithms.cpp**: Contains implementations of algorithms that operate on graphs, such as checking for connectivity, finding the shortest path, detecting cycles, and checking for bipartite graphs.
- **Algorithms.hpp**: The header file for the algorithms implemented in `Algorithms.cpp`.
- **Test.cpp**: Contains unit tests to validate the functionality of the `Graph` class and the implemented algorithms.
- **TestCounter.cpp**: Additional tests or a testing utility for the graph operations.
- **doctest.h**: A header-only testing framework used for unit testing.
- **Demo.cpp**: The main file that demonstrates the functionality of the program with example inputs and outputs.
- **Makefile**: A script that compiles the program and manages the build process.

## Features

### Graph Class (`Graph.cpp`)

- The graph is represented using a square adjacency matrix.
- The `Graph` class includes methods such as:
  - **loadGraph**: Load a graph from a given adjacency matrix.
  - **printGraph**: Print the graph in a user-friendly format.
- Arithmetic and comparison operators are overloaded to work with graphs:
  - Addition (`+`), Subtraction (`-`), Multiplication (`*`), and their compound versions (e.g., `+=`, `-=`).
  - Comparison operators (`==`, `!=`, `>`, `<`, `>=`, `<=`) based on graph structure and edges.
  - Increment (`++`) and decrement (`--`) operators to increase or decrease edge weights.
  - Multiplication by a scalar to scale the weights of the graph.

### Graph Algorithms (`Algorithms.cpp`)

- **isConnected**: Determines if the graph is connected.
- **shortestPath**: Finds the shortest path between two vertices. For unweighted graphs, this is the shortest path in terms of edges; for weighted graphs, it uses the weights.
- **isContainsCycle**: Detects and prints a cycle in the graph, if any.
- **isBipartite**: Checks if the graph can be divided into two disjoint sets such that no two vertices within the same set are adjacent.
- **negativeCycle**: Finds a negative-weight cycle in the graph, if it exists.

### Testing

- The project includes extensive unit tests in `Test.cpp` and `TestCounter.cpp` to validate the functionality of the graph operations and algorithms.
- The tests can be run separately using the `make` command.

## How to Build and Run

1. **Compile the program**:
   ```bash
   make
   ```

2. **Run the program**:
   - To run the main demo:
     ```bash
     ./demo
     ```

   - To run the unit tests:
     ```bash
     ./test
     ```

## Example Usage

The `Demo.cpp` file contains examples that demonstrate how to load a graph, print it, and apply various algorithms and operations. You can modify the `Demo.cpp` file to try different graphs and algorithms.

## Graph Operations

The following operators are supported for graph manipulation:

- **Addition and Subtraction**: Add or subtract two graphs with the same size.
- **Comparison**: Compare two graphs based on their adjacency matrices and edge counts.
- **Multiplication**: Multiply graphs or scale graph weights using a scalar.
- **Increment and Decrement**: Increase or decrease the weight of all edges in a graph.

## Graph Algorithms

- **Connectivity**: Check if the graph is connected.
- **Shortest Path**: Find the shortest or easiest path between two vertices.
- **Cycle Detection**: Check if the graph contains a cycle and print it.
- **Bipartite Graph Check**: Determine if the graph can be divided into two sets with no intra-set edges.
- **Negative Cycle Detection**: Find and report any negative-weight cycles in the graph.

