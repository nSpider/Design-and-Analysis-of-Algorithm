
//one directional partitioning

#include<stdio.h>
#include<stdlib.h>

int partition(int *a,int l, int h){
	int i = l-1;
	int j = l;
	int p = h;
	for (j;j<h;j++){
		if (a[j]<a[p]){
			i++;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	i++;
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	return i;
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