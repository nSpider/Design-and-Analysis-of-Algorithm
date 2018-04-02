#include<stdio.h>
#include<stdlib.h>

struct Job{
	int profit;
	int deadline;
};

typedef struct Job job;


void heapify(job **a,int i,int n){
	int lc = 2*i + 1;
	int rc = 2*i + 2;
	int big = i;
	if (lc<n && (a[lc]->profit)<(a[big]->profit))
		big = lc;
	if (rc<n && (a[rc]->profit)<(a[big]->profit))
		big = rc;
	if (big!=i){
		job *temp = a[big];
		a[big] = a[i];
		a[i] = temp;
		heapify(a,big,n);
	}
}

void buildHeap(job **a,int n){
	int i = n-1;
	while(i >= 0){
		heapify(a,i,n);
		i--;
	}
}

void sort(job **a,int n){
	buildHeap(a,n);

	//pre build print
	int i;
	//printf ("Post build Printing:"); for (i=0;i<n;i++){ printf ("%d ",a[i]);} printf ("\n\n");


	job *temp;
	while(n>0){
		temp = a[0];
		a[0] = a[n-1];
		a[n-1] = temp;
		n--;
		heapify(a,0,n);
	}
}

int max (job **a,int n){
	int i,ma = -1;
	for (i =0;i<n;i++){
		if (a[i]->deadline > ma)
			ma = a[i]->deadline;
	}
	return ma;
}

int js (job **a,int n){
	int count = max(a,n);
	int i,k;
	sort(a,n);
	
	int *e = (int *)malloc(count*sizeof(int));
	for (i=0;i<n;i++) e[i]=-1;
	for (i = 0;i<n && count>0;i++){
		for(k = (a[i]->deadline)-1;k>=0;k--){
			if (e[k]==-1){
				e[k]=a[i]->profit;
				count--;
				break;
			}
		}
	}
	count = 0;
	for (i=0;i<n;i++){
		if (e[i]>-1){
			count+=e[i];
		}
	}
	return count;
}

int main(){
	printf ("Enter no of Jobs present:");
	int n,i;
	scanf ("%d",&n);
	job **a = (job **)malloc(n*sizeof(job *));
	printf ("Enter deadline and profit of jobs:");
	for (i=0;i<n;i++){
		a[i] =(job *) malloc (sizeof(job));
		scanf("%d %d",&(a[i]->deadline),&(a[i]->profit));
	}
	int jobs = js(a,n);
	printf ("Total profit possible by user :%d",jobs);
}