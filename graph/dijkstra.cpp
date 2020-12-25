//call dijkstra to find single source(s) shortest path in positive edge directed or undirected graph
//0-based index
//if only one destination(t), after pop up destination(t) from pq you can return.
//O(E logV)
//Tested: https://cses.fi/problemset/result/1430351/

typedef long long ll;
 
struct graph {
  int n;
  vector<vector<int>> g;
  vector<vector<ll>> cost;
  vector<ll> dis;
 
  graph(int n):n(n),g(n),cost(n){}
 
  void add_edge(int u, int v, ll c){
    g[u].push_back(v);
    cost[u].push_back(c);
  }
 
  void dijkstra(int s, int t=-1){
    dis.assign(n, 1e18);
    dis[s]=0;
    auto comp = [&](int i, int j){return dis[i]==dis[j]? i<j: dis[i]>dis[j]; };
    priority_queue <ll, vector<ll>, decltype(comp)> pq(comp);
    pq.push(s);
    while (!pq.empty()){
      int u = pq.top(); pq.pop();
      if(u == t) return;
      for(int i=0; i<g[u].size(); i++){
        int v=g[u][i];
        if(dis[u] + cost[u][i] < dis[v]){
          pq.push(v);
          dis[v] = dis[u] + cost[u][i];
        }
      }
    }
  }
};
