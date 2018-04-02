#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int x, int y){
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}

void heapify(int *a,int i,int l,int h){
	int lc = l + 2*(i-l) + 1;
	int rc = l + 2*(i-l) + 2;
	int big = i;
	if (lc<=h && a[lc]>a[big])
		big = lc;
	if (rc<=h && a[rc]>a[big])
		big = rc;
	if (big!=i){
		swap(a,i,big);
		heapify(a,big,l,h);
	}
}

void buildHeap(int *a,int l,int h){
	int i = (l+h-1)/2;
	while(i >= l){
		heapify(a,i,l,h);
		i--;
	}
}

void merge(int *a,int l,int m,int h){
	int *b = (int *)malloc(sizeof(int *)*(h-l+1));
	int i = l,j = m+1,k = 0;
	while(i<=m && j<=h){
		if (a[i]<a[j]){
			b[k] = a[i];
			i++;
			k++;
		} else {
			b[k] = a[j];
			j++;
			k++;
		}
	}

	while(i<=m){
		b[k] = a[i];
		i++;k++;
	}

	while(j<=h){
		b[k] = a[j];
		j++;k++;
	}
	i = l, k =0;
	while(i<=h){
		a[i] = b[k];
		i++;k++;
	}
}

void mixSort(int *a,int n,int l,int h){
	if ((h-l)<=(n-1)){
        int i;
        //printf ("HeapSort\n");
		buildHeap(a,l,h);
		int hi = h;
		while(h>l){
			swap(a,l,h);
			h--;
			heapify(a,l,l,h);
		}
	} else {
		int m = (l+h)/2;
		mixSort(a,n,l,m);
		mixSort(a,n,m+1,h);
		merge(a,l,m,h);
	}
}

int main(){
	int n,i,m;
	printf ("Enter the number of array size:");
	scanf ("%d",&n);
	printf("Maximum heap size:");
	scanf ("%d",&m);
	int *a = (int *)malloc(sizeof(int *)*n);
	printf ("Enter the values of array:");
	for (i = 0;i<n;i++){
		scanf ("%d",&a[i]);
	}

	//pre build print
	printf ("Pre build Printing:");
	for (i=0;i<n;i++){
		printf ("%d ",a[i]);
	}
	printf ("\n\n");

	//Mixsort
	mixSort(a,m,0,n-1);

	//post sort print
	printf ("Post build Printing:");
	for (i=0;i<n;i++){
		printf ("%d ",a[i]);
	}
	printf ("\n");
	return 0;
}
