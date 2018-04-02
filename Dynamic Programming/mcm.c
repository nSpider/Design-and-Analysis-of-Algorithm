#include<stdio.h>
#include<stdlib.h>

void bt(int i, int j, int *b, int n){
	if (i<j){
		printf("(");
		bt (i,b[i*n+j],b,n);
		printf("*");
		bt (b[i*n+j]+1,j,b,n);
		printf(")");
	} else {
		printf(" %d ",i+1);
	}
}

void mcm(int *d, int n){
	int *m = (int *)malloc(n*n*sizeof(int));
	int *b = (int *)malloc(n*n*sizeof(int));
	int i,j,k;
	for (i=0;i<n;i++){
		m[i*n+j] = 0;
		b[i*n+j] = 0;
	}
	for (i=1;i<n;i++){
		for (j=0;j<n-i;j++){
			int min = 999,com;
			for (k=j;k<i+j;k++){
				com = m[j*n+k]+m[(k+1)*n+i+j]+(d[j]*d[k+1]*d[i+j+1]);
				if(com<min){
					min = com;
					b[j*n+i+j] = k;
				}
			}
			m[j*n+i+j] = min;
		}
	}
	for (i = 0; i < n; ++i){
		for (j = 0; j < n; ++j){
			printf("%2d ",m[i*n+j]);
		}
		printf("\n");
	}

	bt(0,n-1,b,n);
}

int main(){
	int n,i;
	scanf("%d",&n);
	int *d = (int *)malloc((n+1)*sizeof(int));
	for (i=0;i<=n;i++){
		scanf("%d",&d[i]);
	}
	mcm(d,n);
	return 0;
}