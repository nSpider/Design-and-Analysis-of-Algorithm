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
	int n,c,t;
	scanf("%d",&t);
	while(t--){
    	scanf("%d",&n);
    	scanf("%d",&c);
    	int i,j;
    	itm *a = (itm *)malloc(n*sizeof(itm));
        for (i=0;i<n;i++){
            scanf("%d",&a[i].p);
        }
    	for (i=0;i<n;i++){
    		scanf("%d",&a[i].w);
    	}
    	int *m = (int *)malloc((c+1)*(n+1)*sizeof(int));
    	for (i=0;i<=n;i++){
    		for (j=0;j<=c;j++){
    			if (j==0 || i==0){
    				m[i*(c+1)+j] = 0;
    			} else if (a[i-1].w<=j){
    				int pc = m[(i-1)*(c+1)+(j-a[i-1].w)] + a[i-1].p;
    				int pp = m[(i-1)*(c+1)+j];
    				if (pc > pp){
    					m[i*(c+1)+j] = pc;
    				} else {
    					m[i*(c+1)+j] = pp;	
    				}
    			} else {
    				m[i*(c+1)+j] = m[(i-1)*(c+1)+j];
    			}
    			//printf ("%d ",x[i*(c+1)+j]);
    		}
    		//printf("\n");
    	}
    	printf("%d\n",m[n*(c+1)+c]);
	}

	//printf("\n");
	//find(n,c,c+1,x,a);
	return 0;
}