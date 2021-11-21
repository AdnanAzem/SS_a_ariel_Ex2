#include <stdio.h>
#include <limits.h>

#define N 10
#define MAX 100
#define TEMP 0
#define PERM 1
#define infinity 9999
#define NIL -1

int adj[N][N];
int predecessor[N];   /*predecessor of each vertex in shortest path*/
int pathLength[N];
int status[N];

int mat[N][N]

void buildGraph()
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d",mat[i][j]);
        } 
    }
}

void isThereConnection(){
    int x,y;
    scanf("%d%d",&x, &y);
    if(mat[x][y] != 0){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
}


void Dijkstra( int s)
{
        int i,current;

        /* Make all vertices temporary */
        for(i=0; i<N; i++)
        {
                predecessor[i] =  NIL;
                pathLength[i] = infinity;
                status[i] = TEMP;
        }
        /* Make pathLength of source vertex equal to 0 */
        pathLength[s] = 0;

        while(1)
        {
                /*Search for temporary vertex with minimum pathLength
                and make it current vertex*/
                current = min_temp( );

                if( current == NIL )
                        return;

                status[current] = PERM;

                for(i=0; i<n; i++)
                {
                        /*Checks for adjacent temporary vertices */
                        if ( adj[current][i] !=0 && status[i] == TEMP )
                                if( pathLength[current] + adj[current][i] < pathLength[i] )
                                {
                                        predecessor[i] = current;  /*Relabel*/
                                        pathLength[i] = pathLength[current] + adj[current][i];
                                }
                }
        }
}/*End of Dijkstra( )*/

void findPath(int s, int v )
{
        int i,u;
        int path[N];          /*stores the shortest path*/
        int shortdist = 0;      /*length of shortest path*/
        int count = 0;          /*number of vertices in the shortest path*/

        /*Store the full path in the array path*/
        while( v != s )
        {
                count++;
                path[count] = v;
                u = predecessor[v];
                shortdist += adj[u][v];
                v = u;
        }
        count++;
        path[count]=s;

        printf("%d\n", shortdist);
}/*End of findPath()*/

void shortPath(){
    int x,y;
    scanf("%d%d",&x,&y);
    Dijkstra(x);

    if(x == y){
        printf(-1);
    }
    else{
        findPath(x,y);
    }
  
}