//call dijkstra to find single source(s) shortest path in positive edge directed or undirected graph(multi-edge and self loop also supported)
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
  vector<int> vis;
 
  graph(int n):n(n),g(n),cost(n), vis(n){}
 
  void add_edge(int u, int v, ll c){
    g[u].push_back(v);
    cost[u].push_back(c);
  }
 
  void dijkstra(int s){
    vis.assign(n, 0);
    dis.assign(n, 1e18);
    dis[s]=0;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, s});
   
    while (!pq.empty()){
      int u = pq.top().second;
      ll c = -pq.top().first;
      pq.pop();
      if(vis[u])  continue;
      vis[u]=1;
      for(int i=0; i<g[u].size(); i++){
        int v=g[u][i];
        dis[v] = min(dis[v], c+cost[u][i]);
        pq.push({-(c+cost[u][i]), v});
        
      }
    }
  }
};
