#include<stdio.h>
#include<stdlib.h>

void minmax (int a[],int l,int h,int *min,int *max){
	if (l==h)
		(*min) = (*max) = a[l];
	else {
		int mid = (l+h)/2;
		int min1,min2,max1,max2;
		minmax(a,l,mid,&min1,&max1);
		minmax(a,mid+1,h,&min2,&max2);
		(*min) = (min1<min2)?min1:min2;
		(*max) = (max1>max2)?max1:max2;
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
	int min,max;
	minmax(a,0,n-1,&min,&max);
	printf ("\nMinimum element: %d\nMaximum Element: %d\n",min,max);
	return 0;
}