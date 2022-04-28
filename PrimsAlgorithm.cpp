#include <cstring> //Header files
#include <iostream>
using namespace std;
#define INF 9999999
int main()
{
	int V;
	cout << "\nMaximum matrix/no of vertices you have to use in your program : ";
	cin >> V;
	cout << "\n\t\t\t\tMaximum matrix : " << V << " * " << V << " matrix" << endl; // for adjacency matrix to represent graph
	int G[V][V];
	int number_edges; // number of edge
	int minimum_CostPath = 0;
	int selected[V];
	// set selected false initially
	memset(selected, false, sizeof(selected));
	// memset function converts the value of character to unsigned character and copies it into each
	// of first n character of object pointed by given string
	number_edges = 0; // set number of edge to 0
	int i, j;
	cout << "\n\nEnter value of the total number of vertices : ";
	int V1;
	cin >> V1;
	cout << "\nEnter the adj.matrix for cost : \n";
	for (i = 0; i < V1; i++)
	{
		cout << "\n";
		for (j = 0; j < V1; j++)
		{
			cout << i << "->" << j << " : ";
			cin >> G[i][j];
		}
	}
	// choose 0th vertex and make it true
	selected[0] = true;
	int row; // row number
	int col; // col number
	cout << endl;
	// print for edge and weight
	cout << "Edge "
	     << " : "
	     << "Weight";
	cout << endl;
	while (number_edges < V1 - 1)
	{
		int min = INF;
		row = 0;
		col = 0;
		for (int i = 0; i < V1; i++)
		{
			// For every vertex in the set S, find the all adjacent vertices // , calculate the distance from the vertex selected.
			if (selected[i])
			{
				for (int j = 0; j < V1; j++)
				{
					if (!(selected[j]) && G[i][j])
					{ // not in selected and there is an edge
						if (min > G[i][j])
						{
							// if the vertex is already in the set S, discard it otherwise //choose another vertex nearest to selected vertex
							min = G[i][j];
							row = i;
							col = j;
						}
					}
				}
			}
		}
		cout << row << " - " << col << " : " << G[row][col];
		cout << endl;
		// We calculate total minimum edges cost
		minimum_CostPath = minimum_CostPath + G[row][col];
		selected[col] = true;
		number_edges++;
	}
	cout << "\n Minimum cost of path is : " << minimum_CostPath << endl;
	return 0;
}
