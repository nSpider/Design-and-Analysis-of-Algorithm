#include<stdio.h>
#include<stdlib.h>

typedef struct item{
	int w;
	int p;
}itm;

void find(int i,int c,int n,int *x,itm *a){
	if (i>=0 && c>=0){
		if (x[i*n+c]){
			find (i-1,c-a[i-1].w,n,x,a);
			printf("%d ",i-1);
		} else {
			find (i-1,c,n,x,a);

		}
	}
}

int main(){
	int n,c;
	printf ("Enter number of items present:");
	scanf("%d",&n);
	printf ("Enter total capacity of knapsack:");
	scanf("%d",&c);
	int i,j;
	itm *a = (itm *)malloc(n*sizeof(itm));
	for (i=0;i<n;i++){
		printf("Weight of element %d:",i);
		scanf("%d",&a[i].w);
	}
	for (i=0;i<n;i++){
		printf("Profit of element %d:",i);
		scanf("%d",&a[i].p);
	}
	int *m = (int *)malloc((c+1)*(n+1)*sizeof(int));
	int *x = (int *)malloc((c+1)*(n+1)*sizeof(int));
	printf("\n");
	for (i=0;i<=n;i++){
		for (j=0;j<=c;j++){
			if (j==0 || i==0){
				m[i*(c+1)+j] = 0;
			} else if (a[i-1].w<=j){
				int pc = m[(i-1)*(c+1)+(j-a[i-1].w)] + a[i-1].p;
				int pp = m[(i-1)*(c+1)+j];
				if (pc > pp){
					m[i*(c+1)+j] = pc;
					x[i*(c+1)+j] = 1;
				} else {
					m[i*(c+1)+j] = pp;	
					x[i*(c+1)+j] = 0;
				}
			} else {
				m[i*(c+1)+j] = m[(i-1)*(c+1)+j];
				x[i*(c+1)+j] = 0;
			}
			printf ("%d ",x[i*(c+1)+j]);
		}
		printf("\n");
	}

	printf("\n");
	find(n,c,c+1,x,a);
	return 0;
}