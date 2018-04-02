#include<stdio.h>
#include<stdlib.h>

int min(int a, int b){
	return (a < b) ? a : b ; 
}

void find(int **a,int s, int d){
	if (a[s][d] != -1){
		find(a,s,a[s][d]);
		printf("%d->",a[s][d]);
		find(a,a[s][d],d);
	}
}

int main(){
	int n;
	scanf ("%d",&n);
	int ***a = (int ***)malloc((n+1)*sizeof(int **));
	for(int i=0;i<n;i++){
		a[i] = (int **)malloc((n)*sizeof(int *));
		a[0][i] = (int *)malloc((n)*sizeof(int));
		for (int j = 0;j<n;j++){
			a[0][i][j] = 9999;
		}
		a[0][i][i] = 0;
		while(1){
			printf("Do any more adjacency node present for node %d ?(0/1)",i);
			int c;
			scanf ("%d",&c);
			if (c){
				int x,w;
				scanf("%d%d",&x,&w);
				a[0][i][x] = w;
			} else 
				break;
		}
	}
	a[n] = (int **)malloc((n)*sizeof(int *));
	int ** b = (int **)malloc(n*sizeof(int *));

	for(int i=0;i<n;i++){
		b[i] = (int *)malloc(n*sizeof(int));
		for (int j = 0; j < n; ++j){
			b[i][j] = -1;
			printf("%4d ",a[0][i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 1; i <= n; ++i){
		for (int j = 0; j<n;j++){
			a[i][j] = (int *)malloc((n)*sizeof(int));
			for (int k = 0;k<n;k++){
				if (j!=k){
					a[i][j][k] = min ((a[i-1][j][i-1]+a[i-1][i-1][k]),(a[i-1][j][k]));
					if (a[i][j][k] != a[i-1][j][k])
						b[j][k] = i-1;
				}
				printf("%4d ",a[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	int s,d;
	printf("Enter the source and destination:");
	scanf("%d%d",&s,&d);
	printf("Cost: %d\nPath: %d->",a[n][s][d],s);
	find(b,s,d);
	printf("%d\n",d);
}