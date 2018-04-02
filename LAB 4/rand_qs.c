#include<stdio.h>
#include<stdlib.h>

int partition(int *a,int l, int h){
	int d = l;
	int u = h;
	int pi = l + rand()%(h-l+1);
	int temp = a[pi];
	a[pi] = a[l];
	a[l] = temp;
	int p = a[l];
	while(1){
		while (a[d]<=p && d<u)
			d++;
		while (a[u]>p)
			u--;
		if (d<u){
			int temp = a[u];
			a[u] = a[d];
			a[d] = temp;
		} else {
			int temp = a[u];
			a[u] = a[l];
			a[l] = temp;
			return u;
		}
	}
}

void qs(int *a,int l,int h){
	if (l<h){
		int p = partition(a,l,h);
		qs(a,l,p-1);
		qs(a,p+1,h);
	}
}

int main(){
	int n,i;
	scanf ("%d",&n);
	int* a = (int *)malloc (sizeof(int*)*n);
	for (i = 0;i<n;i++){
		scanf ("%d",&a[i]);
	}
	qs (a,0,n-1);
	for (i = 0;i<n;i++){
		printf ("%d ",a[i]);
	}
	printf ("\n");
	return 0;
} 