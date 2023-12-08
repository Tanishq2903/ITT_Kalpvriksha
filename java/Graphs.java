import java.util.*;
 class Graphs {
   static class Edge{
        int src;
        int dest;
        public Edge(int src,int dest){
            this.src = src;
            this.dest = dest;
        }
    }
 public static void main(String[] args) {
    int V = 4;
    ArrayList<Edge> graph[] = new ArrayList[V];
   insert(graph);
    boolean visited[] = new boolean[V];
    for(int i = 0 ; i < visited.length;i++){
        if(visited[i] == false)bfs(visited,graph,i);
        System.out.println();
        dfs(visited,graph,i);
    }

}
public static void bfs(  boolean visited[] ,ArrayList<Edge>[] graph ,int start){
 //   boolean visited[] = new boolean[V];
    Queue<Integer>queue = new LinkedList<>();
    queue.add(start);
    while(!queue.isEmpty()){
        int curr = queue.poll();
       if(visited[curr] == false){
        System.out.print(curr + " ");
        visited[curr] = true;
        for(int i = 0 ; i  < graph[curr].size();i++){
            Edge e = graph[curr].get(i);
            queue.add(e.dest);
        }
       }
    }
   
}
 
private static void insert(ArrayList<Edge>[] graph) {
for(int i = 0 ; i < graph.length ; i++){
    graph[i] = new ArrayList<Edge>();
}
graph[0].add(new Edge(0,2));

graph[1].add(new Edge(1,2));
graph[1].add(new Edge(1,3));

graph[2].add(new Edge(2,0));
graph[2].add(new Edge(2,1));
graph[2].add(new Edge(2,3));


graph[3].add(new Edge(3,1));
graph[3].add(new Edge(3,2));

}





public static void dfs( boolean visited[] ,ArrayList<Edge>[] graph ,int curr){
System.out.print(curr + " ");
visited[curr] = true;
for(int i = 0 ; i < graph[curr].size();i++){
   if(visited[i] == false){ Edge e = graph[curr].get(i);
    dfs(visited,graph,e.dest);}
}
}
}
