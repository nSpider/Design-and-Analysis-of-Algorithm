#include<stdio.h>
#include<stdlib.h>

void heapify(int *a,int i,int n){
	int lc = 2*i + 1;
	int rc = 2*i + 2;
	int big = i;
	if (lc<n && a[lc]>a[big])
		big = lc;
	if (rc<n && a[rc]>a[big])
		big = rc;
	if (big!=i){
		int temp = a[big];
		a[big] = a[i];
		a[i] = temp;
		heapify(a,big,n);
	}
}

void buildHeap(int *a,int n){
	int i = n-1;
	while(i >= 0){
		heapify(a,i,n);
		i--;
	}
}


void heapSort(int *a,int n){
	buildHeap(a,n);

	//pre build print
	int i;
	printf ("Post build Printing:");
	for (i=0;i<n;i++){
		printf ("%d ",a[i]);
	}
	printf ("\n\n");


	int temp;
	while(n>0){
		temp = a[0];
		a[0] = a[n-1];
		a[n-1] = temp;
		n--;
		heapify(a,0,n);
	}
}


void insert(int *a,int *n){
	printf ("Enter the value to be inserted:");
	scanf("%d",&a[(*n)]);
	int i = *n;
	int j = (i-1)/2, temp;
	while(i>0){
		if (a[i]<a[j])
			break;
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		i = j;
		j = (i-1)/2;
	}
}

int main(){
	int n,i;
	printf ("Enter the number of array size:");
	scanf ("%d",&n);
	int a[100];
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

	//buildheap
	heapSort(a,n);
	
	//post sort print

	printf ("Post sort Printing:");
	for (i=0;i<n;i++){
		printf ("%d ",a[i]);
	}
	printf ("\n");
	return 0;
}