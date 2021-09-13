package dsa;

import java.util.*;

public class Graph {
	static void addEdge(ArrayList<ArrayList<Integer> > adj,int u, int v)
	{
		adj.get(u).add(v);
        adj.get(v).add(u);
}
	static void printGraph(ArrayList<ArrayList<Integer> > adj)
    {
        for (int i = 0; i < adj.size(); i++) {
            System.out.println("\nAdjacency list of vertex" + i);
            System.out.print("head");
            for (int j = 0; j < adj.get(i).size(); j++) {
                System.out.print(" -> "+adj.get(i).get(j));
            }
            System.out.println();
        }
    }
static void delEdge(ArrayList<ArrayList<Integer> > adj,
            int u, int v)
{
// Traversing through the first vector list
// and removing the second element from it
  for (int i = 0; i < adj.get(u).size(); i++)
{
   if (adj.get(u).get(i) == v)
{
    adj.get(u).remove(i);
    break;
}
}

// Traversing through the second vector list
// and removing the first element from it
for (int i = 0; i < adj.get(v).size(); i++)
{
if (adj.get(v).get(i) == u)
{
    adj.get(v).remove(i);
    break;
}
}
}

//function to convert list to matrix
public static void matrix(ArrayList<ArrayList<Integer>>adj,int V) {
	int[][]mat=new int[V][V];
	for(int i=0;i<V;i++) {
		for(int j:adj.get(i)) {
			mat[i][j]=1;
		}
	}
	for(int i=0;i<V;i++) {
		for(int j=0;j<V;j++) {
			System.out.print(mat[i][j]+" ");
		}
		System.out.println();
	}
	
	
}




public static void main(String[] args)
{
    // Creating a graph with 5 vertices
    int V = 5;
    ArrayList<ArrayList<Integer> > adj 
                = new ArrayList<ArrayList<Integer> >(V);
      
    for (int i = 0; i < V; i++)
        adj.add(new ArrayList<Integer>());//to need one more array list within a array list

    // Adding edges one by one
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    
    printGraph(adj);
    delEdge(adj,0,4);
    printGraph(adj);
    matrix(adj,V);
}



}
