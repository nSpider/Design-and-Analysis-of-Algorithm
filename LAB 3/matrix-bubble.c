#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int x1,int y1,int x2,int y2,int m,int n){
    int temp;

    temp = a[x1*m+y1];
    a[x1*m+y1] = a[x2*m+y2];
    a[x2*m+y2] = temp;

    temp = a[x1*m + y1 + 1];
    a[x1*m + y1 + 1] = a[x2*m + y2 + 1];
    a[x2*m + y2 + 1] = temp;

    temp = a[(x1+1)*m + y1];
    a[(x1+1)*m + y1] = a[(x2+1)*m + y2];
    a[(x2+1)*m + y2] = temp;

    temp = a[(x1+1)*m + y1 + 1];
    a[(x1+1)*m + y1 + 1] = a[(x2+1)*m + y2 + 1];
    a[(x2+1)*m + y2 + 1] = temp;
}

void bubble(int *a,int m,int n){
    int i,j;
	int xy = (m*n)/4;
	for (i=0;i<xy;i++){
        int x = 0;
        for (j=0;j<xy-1;j++){
        	int x1 = ((2*(j+1))/m)*2;
        	int y1 = ((j+1)%(m/2))*2;
        	int xj = ((2*j)/m)*2;
        	int yj = (j%(m/2))*2;
        	int s1 = a[x1*m + y1] + a[x1*m + y1 + 1] + a[(x1+1)*m + y1] + a[(x1+1)*m + y1 +1];
        	int sj = a[xj*m + yj] + a[xj*m + yj + 1] + a[(xj+1)*m + yj] + a[(xj+1)*m + yj +1];
        	//printf ("%d %d\n",xj,yj);
            if (sj>s1){
                    x++;
                    swap (a,x1,y1,xj,yj,m,n);
            }
        }
        if (x==0)
            break;
    }

}

int main(){
	int m,n,i,j;
	scanf ("%d %d",&m,&n);
	int *a = (int *)malloc(m*n*sizeof(int *));
	for (i=0;i<(m*n);i++){
		a[i] = (int)rand() % 100;
	}
	for (i = 0;i<n;i++){
		for (j = 0;j<m;j++){
			printf ("%d ",a[(i*m) + j]);
		}
		printf ("\n");
	}

    printf("\n");

    bubble(a,m,n);

    for (i = 0;i<n;i++){
        for (j = 0;j<m;j++){
            printf ("%d ",a[(i*m) + j]);
        }
        printf ("\n");
    }
}
