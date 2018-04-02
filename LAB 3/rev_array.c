#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
	int c = (*a);
	(*a) = (*b);
	(*b) = c;
}

void rev (int a[],int l,int h){
	if (l==h)
		return;
	int mid = (l+h)/2,i,j;
	rev(a,l,mid);
	rev(a,mid+1,h);
	for (i=l,j=mid+1;i<=mid,j<=h;i++,j++){
		swap(&a[i],&a[j]);
	}	
}

int main(){
	int n;
	printf ("Enter number of elements:");
	scanf ("%d",&n);
	int *a =(int *) malloc (n*sizeof(int *));
	int i;
	for (i=0;i<n;i++){
		scanf ("%d",&a[i]);
	}
	rev(a,0,n-1);
	printf ("Reversed array is: ");
	for (i=0;i<n;i++){
		printf ("%d ",a[i]);
	}
	printf ("\n");
	return 0;
}