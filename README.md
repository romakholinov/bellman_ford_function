# bellman_ford_function
A function that implements Bellman-Ford algorithm for finding the shortest distances from a given vertex to all other vertices on a graph.

It accepths 6 objects:
-> vector<vector> graph - a vector where for every vertex there is a vector of verices to which an edge terminates.
-> vector<Edge> edges - a vector that holds edges with their weights.
-> vector<bool> negCycle - a vector where vertices that are in negative cycles are listed.
-> vector<long long>& dis - vector with distances. Remark: initialize it with 
all vertices' paths being equal to maxVal.
-> int target - initial point, from which we calculate the pathes.
-> int V - the number of vertices.

Also there is a dfs function that is needed for finding all vertices that belong to negative cycles. 

Remark 1: the variable "long long maxVal = (long long) 1e20 " should be global.
Remark 2: all stacks should contain indexes, not numbers of vertices. Do not forget to subtract 1 when using this function.
