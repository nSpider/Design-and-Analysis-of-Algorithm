#include<stdio.h>
#include<stdlib.h>

int add (int a[],int l,int h){
	if (l==h)
		return a[l];
	else {
		int mid = (l+h)/2;
		int s1 = add(a,l,mid);
		int s2 = add(a,mid+1,h);
		return (s1+s2);
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
	int sum;
	sum = add(a,0,n-1);
	printf ("\nResult of addition: %d\n\n",sum);
	return 0;
}