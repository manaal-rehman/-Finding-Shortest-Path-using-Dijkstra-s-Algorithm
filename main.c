#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "node.h"
#include "stack_functions.h"

#define NUM_VERTICES 10
/** This function takes a pointer to the
    adjacency matrix of a Graph and the
    size of this matrix as arguments and
    prints the matrix
*/
void print_graph(int * graph, int size);

/** This function takes a pointer to the
    adjacency matrix of a Graph, the size
    of this matrix, the source and dest
    node numbers along with the weight or
    cost of the edge and fills the adjacency
    matrix accordingly.
*/
void add_edge(int * graph, int size, int src, int dst, int cost);

/** This function takes a pointer to the adjacency matrix of
    a graph, the size of this matrix, source vertex number
    and a pointer to an array for holding the computed shortest
    distances as arguments.
*/
void find_shortest_paths( int * graph, int size, int src, int * dist_array);

int main()
{
    int my_graph[NUM_VERTICES][NUM_VERTICES];   /// An adjacency matrix representation of graph
    memset(my_graph,-1,NUM_VERTICES * NUM_VERTICES * sizeof(int));     /// Initiallize with -1 representing infinte cost.

    for(int i=0; i<NUM_VERTICES; i++)
        add_edge(&my_graph[0][0], NUM_VERTICES, i, i, 0);

    add_edge(&my_graph[0][0], NUM_VERTICES, 0, 3, 13);
    add_edge(&my_graph[0][0], NUM_VERTICES, 1, 4, 14);
    add_edge(&my_graph[0][0], NUM_VERTICES, 1, 5, 6);
    add_edge(&my_graph[0][0], NUM_VERTICES, 2, 3, 9);
    add_edge(&my_graph[0][0], NUM_VERTICES, 2, 9, 10);
    add_edge(&my_graph[0][0], NUM_VERTICES, 3, 0, 13);
    add_edge(&my_graph[0][0], NUM_VERTICES, 3, 8, 9);
    add_edge(&my_graph[0][0], NUM_VERTICES, 4, 1, 14);
    add_edge(&my_graph[0][0], NUM_VERTICES, 4, 6, 8);
    add_edge(&my_graph[0][0], NUM_VERTICES, 5, 1, 6);
    add_edge(&my_graph[0][0], NUM_VERTICES, 5, 2, 7);
    add_edge(&my_graph[0][0], NUM_VERTICES, 5, 6, 12);
    add_edge(&my_graph[0][0], NUM_VERTICES, 6, 4, 8);
    add_edge(&my_graph[0][0], NUM_VERTICES, 6, 7, 15);
    add_edge(&my_graph[0][0], NUM_VERTICES, 7, 6, 15);
    add_edge(&my_graph[0][0], NUM_VERTICES, 8, 5, 11);
    add_edge(&my_graph[0][0], NUM_VERTICES, 9, 8, 23);

    print_graph(&my_graph[0][0], NUM_VERTICES);


    int shortest_dists[NUM_VERTICES];

    for(int i=0; i<NUM_VERTICES; i++)
    {
        shortest_dists[i] = -1;
    }

    find_shortest_paths(&my_graph[0][0], NUM_VERTICES, 5, shortest_dists);

    printf("\n Cost to vertices: ");
    for(int i=0; i<NUM_VERTICES; i++)
    {
        printf("\t%d", shortest_dists[i]);
    }
    printf("\n");
    getchar();
    return 0;
}

void add_edge(int * graph, int size, int src, int dst, int cost)
{
    *(graph+(src*size+dst)) = cost;
}

void print_graph(int * graph, int size)
{
    //char vertices[size];
    for(int i=0; i<size; i++)
    {
        //vertices[i] = 'A'+i;
        //printf("\t%c", vertices[i]);
        printf("\t%d", i);
    }
    printf("\n\n");
    for(int x=0; x<size; x++)
    {
        //printf("%c\t", vertices[x]);
        printf("%d\t", x);
        for(int y=0; y<size; y++)
            printf("%d\t", *(graph+(x*size+y)));
        printf("\n");
    }
}


void find_shortest_paths( int * graph, int size, int src, int * dist_array)
{

    /*** Complete this function ***/

}
