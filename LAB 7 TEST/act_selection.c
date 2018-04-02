#include<stdio.h>
#include<stdlib.h>

struct Act{
	int s;
	int e;
};

typedef struct Act act;


void heapify(act **a,int i,int n){
	int lc = 2*i + 1;
	int rc = 2*i + 2;
	int big = i;
	if (lc<n && (a[lc]->e)>(a[big]->e))
		big = lc;
	if (rc<n && (a[rc]->e)>(a[big]->e))
		big = rc;
	if (big!=i){
		act *temp = a[big];
		a[big] = a[i];
		a[i] = temp;
		heapify(a,big,n);
	}
}

void buildHeap(act **a,int n){
	int i = n-1;
	while(i >= 0){
		heapify(a,i,n);
		i--;
	}
}

void sort(act **a,int n){
	buildHeap(a,n);

	//pre build print
	int i;
	//printf ("Post build Printing:"); for (i=0;i<n;i++){ printf ("%d ",a[i]);} printf ("\n\n");


	act *temp;
	while(n>0){
		temp = a[0];
		a[0] = a[n-1];
		a[n-1] = temp;
		n--;
		heapify(a,0,n);
	}
}

int as (act **a,int n){
	int count = (n>0);
	int i;
	sort(a,n);
	int ch = 0;
	//for (i=0;i<n;i++) printf("%d %d\n",(a[i]->s),(a[i]->e));
	for (i = 1;i<n;i++){
		if ((a[ch]->e)<=(a[i]->s)){
			ch = i;
			count++;
		}
	}
	return count;
}

int main(){
	printf ("Enter no of Activity present:");
	int n,i;
	scanf ("%d",&n);
	act **a = (act **)malloc(n*sizeof(act *));
	printf ("Enter starting and ending time of activities:");
	for (i=0;i<n;i++){
		a[i] =(act *) malloc (sizeof(act));
		scanf("%d %d",&(a[i]->s),&(a[i]->e));
	}
	int acti = as(a,n);
	printf ("Total activities possible by user :%d",acti);
}