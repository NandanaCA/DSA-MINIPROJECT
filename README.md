# DSA-MINIPROJECT
SYNOPSIS:
This data structure project aims to perform a comprehensive comparative analysis of four fundamental graph algorithms: Dijkstra's algorithm, Bellman-Ford algorithm, Floyd-Warshall algorithm, and Breadth-First Search (BFS). The primary objective is to evaluate and compare the time complexities of these algorithms when applied to graphs represented as adjacency matrices.

1. Introduction:
   - Graph theory is a fundamental concept in computer science and various real-world applications, making it essential to understand and compare graph algorithms' performance.
   - The project focuses on analyzing Dijkstra's, Bellman-Ford, Floyd-Warshall, and BFS algorithms when operating on graphs with adjacency matrices.

2. Objectives:
   - Compare the time complexities of Dijkstra's, Bellman-Ford, Floyd-Warshall, and BFS algorithms.
   - Evaluate their performance on graphs with different sizes and structures.
   - Identify the strengths and weaknesses of each algorithm in the context of adjacency matrices.

3. Methodology:
   - Implement each algorithm in a consistent programming language.
   - Create a range of test cases with varying graph sizes and structures.
   - Generate adjacency matrices to represent these test cases.
   - Record the execution times of each algorithm on these matrices.
   - Analyze and compare the time complexities of the algorithms.

4. Algorithms to be Compared:
   a. Dijkstra's Algorithm:
      - Primarily used for finding the shortest path in a weighted graph.
      - Known for its efficiency on sparse graphs.
   b. Bellman-Ford Algorithm:
      - Designed to find the shortest path in a weighted graph, handling negative edge weights.
      - Useful when negative weight cycles are present.
   c. Floyd-Warshall Algorithm:
      - Computes all pairs of shortest paths in a weighted graph.
      - Suitable for dense graphs and graphs with both positive and negative edge weights.
   d. Breadth-First Search (BFS):
      - Unweighted graph traversal algorithm.
      - Used to explore all nodes reachable from a source node.
5. Conclusion:
   - The project aims to contribute to the field of data structures and algorithm analysis by providing a comprehensive comparison of Dijkstra's, Bellman-Ford, Floyd-Warshall, and BFS algorithms when applied to adjacency matrices. The outcomes will offer guidance on selecting the most appropriate algorithm for various scenarios, ultimately improving the efficiency and effectiveness of graph-based applications.
        

ADT:
GRAPH
An adjacency matrix is a representation of a graph where nodes (vertices) are represented as rows and columns of a matrix. The matrix cells store information about the existence of edges between nodes. 

FUNCTIONS included in the project:
1.Create_graph
2.Display_graph
3.Dijkstra
4.Bellman_ford
5.Floyd_warshall
6.BFS
7.Timing_weightedgraphs
8.Timing_unweightedgraphs



INSTRUCTIONS TO EXECUTE:
There are four test files for checking different scenarios.

test1.txt is used to test out dijksta, bellman-ford and floyd-warshall algorithms.
To execute this, type test1.txt.

test2.txt is used to test out bfs algorithm.
To execute this, type test2.txt.

test3.txt is used to display the runtime of algorithms for weighted graphs.
To execute this, type test3.txt.

test4.txt is used to display the runtime of algorithms for unweighted graphs.
To execute this, type test4.txt.

Thank you.
