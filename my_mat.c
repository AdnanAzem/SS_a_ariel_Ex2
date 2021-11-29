
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 10
int adj[N][N];


int min(int a, int b) {
	if (a<b) return a;
	else 
		return b;
}

void floydWarshalle(int mat[][N]) {
	
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (mat[i][j]&&mat[i][k] != 0 &&mat[k][j] != 0) {
					mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
				}
				else if(i!=j&&mat[i][j]==0&&mat[i][k]!=0&&mat[k][j]!=0){
                        mat[i][j]=mat[i][k]+mat[k][j];
				}
			}
		}
	}
}

void buildGraph(){
        int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &adj[i][j]);
		}
	}

    floydWarshalle(adj);

}


void shortPath(){
    int x,y;
    scanf("%d",&x);
    scanf("%d",&y);

    if(adj[x][y] == 0){
        printf("-1\n");
    }
    else{
        printf("%d\n",adj[x][y]);
    }
  
}

void isThereConnection(){
    int x,y;
    scanf("%d",&x);
    scanf("%d",&y);

    if (adj[x][y] != 0){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
}
        
