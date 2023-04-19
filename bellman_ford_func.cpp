using namespace std;

long long maxVal = (long long) 1e20;

//use dfs for getting all the verices which parent is from negative cycle
void dfs(int v, vector< vector<int> >& graph, vector<bool>& negCycle)
{
    negCycle[v] = true;
    for (int i = 0; i < graph[v].size(); ++i) {
        int x = graph[v][i];
        if (!negCycle[x])
            dfs(x, graph, negCycle);
    }
}
//struct for edge: point from, point to, weight
struct Edge
{
    int first, second;
    long long weight;
    Edge(int f, int s, long long w) : first(f), second(s), weight(w) {}
};



void bellman_ford(vector< vector<int> >& graph, vector<Edge>& edges, vector<bool>& negCycle, vector<long long>& dis, int target, int V)
{
    //Step 1: getting the distances
    dis[target] = 0;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < edges.size(); ++j) {
            int x = edges[j].first;
            int y = edges[j].second;
            if ((dis[x] < maxVal) && (dis[y] > dis[x] + edges[j].weight))
                dis[y] = dis[x] + edges[j].weight;
        }
    }

    //Step 2: looking for negative cycles.
    //If one point belongs to it => all points to which
    //it addresses should also belong to negative cycle
    //(we get them through dfs algo)
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < edges.size(); ++j) {
            int x = edges[j].first;
            int y = edges[j].second;
            if ((dis[x] < maxVal) && (dis[y] > dis[x] + edges[j].weight) && !negCycle[y])
                dfs(y, graph, negCycle);
        }
    }
    //Step 3: output. If it is impossible to get from target to
    //some point, we output *. If there is no shortest way (negative cycle),
    //we put -.
    for (int i = 0; i < V; ++i) {
        if (dis[i] == maxVal)
            cout << "*" << endl;
        else if (negCycle[i])
            cout << "-" << endl;
        else
            cout << dis[i] << endl;
    }
}
