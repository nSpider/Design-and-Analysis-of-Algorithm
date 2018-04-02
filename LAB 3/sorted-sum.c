#include<stdio.h>
#include<stdlib.h>

int add (int a[],int l,int h){
	if (l==h)
		return a[l];
	if ((h-l)==a[h]-a[l])
		return (((a[h]*(a[h]+1))/2) - ((a[l]*(a[l]-1))/2));
	int mid = (l+h)/2;
	int s1 = add(a,l,mid);
	int s2 = add(a,mid+1,h);
	return (s1+s2);
	
}

int main(){
	int n;
	printf ("Enter number of elements:");
	scanf ("%d",&n);
	int *a =(int *) malloc (n*sizeof(int *));
	int i,flag = 0;
	for (i=0;i<n;i++){
		scanf ("%d",&a[i]);
		if (i>0){
			if (a[i]<a[i-1]){
				flag = 1;
			}
		}
	}
	if (flag){
		printf ("\nWarning!! Array is not sorted, this program may not work properly !!\n");
	}
	int sum;
	sum = add(a,0,n-1);
	printf ("\nResult of addition: %d\n\n",sum);
	return 0;
}