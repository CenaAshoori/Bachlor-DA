#include <bits/stdc++.h>
using namespace std;
#define V 7

int find_min_cost(int min_weight[], bool mstSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && min_weight[v] < min)
			min = min_weight[v], min_index = v;

	return min_index;
}

void printMST(int parent[], int graph[V][V],int min_weight[V])
{
	cout<<"Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		//cout<<char('A' + parent[i])<<" -- "<<char('A' + i)<<" == "<<graph[i][parent[i]]<<" \n";
		cout<<char('A' + parent[i])<<" -- "<<char('A' + i)<<" == "<<min_weight[i]<<" \n";
}

void primMST(int graph[V][V])
{
	int parent[V];

	int min_weight[V];

	bool mstSet[V];

	for (int i = 0; i < V; i++)
		min_weight[i] = INT_MAX, mstSet[i] = false;

	min_weight[0] = 0;
	parent[0] = -1;

	for (int e = 0; e < V - 1; e++)
	{
		int u = find_min_cost(min_weight, mstSet);

		mstSet[u] = true;


		for (int v = 0; v < V; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < min_weight[v])
				parent[v] = u, min_weight[v] = graph[u][v];
	}

	printMST(parent, graph ,min_weight);
}

int tamrin9_prime()
{

                       // A, B, C, D, E, F, G
	int graph[V][V] = { { 0, 1, 6, 0, 0, 3, 10},//A
						{ 1, 0, 5, 0, 0, 0, 0 },//B
						{ 6, 5, 0, 9, 0, 2, 0 },//C
						{ 0, 0, 9, 0,11, 8, 0 },//D
						{ 0, 0, 0,11, 0, 4, 0 },//E
						{ 3, 0, 2, 8, 4, 0, 7 },//F
						{10, 0, 0, 0, 0, 7, 0 } //G
						};

	primMST(graph);

	return 0;
}
