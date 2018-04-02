#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int v;
	int w;
	struct node* next;
}nd;

typedef struct adjacent{
	int s;
	int d;
	int w;
}adj;

void heapify(adj **a,int i,int n){
	int lc = 2*i + 1;
	int rc = 2*i + 2;
	int small = i;
	if (lc<n && (a[lc]->w)>(a[small]->w))
		small = lc;
	if (rc<n && (a[rc]->w)>(a[small]->w))
		small = rc;
	if (small!=i){
		adj* temp = a[small];
		a[small] = a[i];
		a[i] = temp;
		heapify(a,small,n);
	}
}

void buildHeap(adj **a,int n){
	int i = (n/2)-1;
	while(i >= 0){
		heapify(a,i,n);
		i--;
	}
}

void heapSort(adj** a,int n){
	buildHeap(a,n);

	//pre build print
	int i;
	//printf ("Post build Printing:");for (i=0;i<n;i++){printf ("%d ",a[i]);}printf ("\n\n");


	adj* temp;
	while(n>0){
		temp = a[0];
		a[0] = a[n-1];
		a[n-1] = temp;
		n--;
		heapify(a,0,n);
	}
}

int find (int *a, int i){
	if (a[i]<0)
		return i;
	a[i] = find (a, a[i]);
	return a[i];
}

void join (int *a, int i, int j){
	while(a[i]>=0){
		i = a[i];
	}
	while(a[j]>=0){
		j = a[j];
	}
	int w = a[i]+a[j];
	if (a[i]<a[j]){
		a[j] = i;
		a[i] = w;
	} else {
		a[i] = j;
		a[j] = w;
	}
}

void ks(adj** s,int v, int e){
	adj** out = (adj **)malloc((v-1)*sizeof(adj *));
	int i,j = 0;
	int *ds = (int *)malloc(v*sizeof(int));
	for (i=0;i<v;i++)
		ds[i] = -1;
	heapSort(s,e);
	int k = 0;
	while(k<e){
		int x = find(ds,s[k]->s);
		int y = find(ds,s[k]->d);
		if(x!=y){
			join(ds,x,y);
			out[j] = s[k];
			j++;
			if (j==v)
				break;
		}
		k++;
	}
	
	for (i=0;i<j;i++){
		if (i)
			printf(",");
		printf("|%d|%d|%d| ",out[i]->s,out[i]->d,out[i]->w );
	}
}

int main(){
	int n,i,c,t=0;
	printf("Enter number of nodes:");
	scanf("%d",&n);
	nd** a = (nd **)malloc(n*sizeof(nd *));
	for (i = 0;i<n;i++){
		a[i] = NULL;
		while(1){
			printf ("Does node %d has anymore adjacent nodes?(0/1):",i);
			scanf("%d",&c);
			if (c==0){
				break;
			} else {
				t++;
				nd *p = (nd *)malloc(sizeof(nd));
				p->next = a[i];
				printf ("Enter the node and weight:");
				scanf("%d",&p->v);
				scanf("%d",&p->w);
				a[i] = p;
			}
		}
	}

	for (i = 0;i<n;i++){
		nd *p = a[i];
		printf ("%d ",i);
		while(p){
			printf ("->");
			printf("|%d|",p->v);
			printf("%d|",p->w);
			p = p->next;
		}
		printf("\n");
	}
	t = t/2;
	printf ("%d\n",t);
	int j = 0;
	adj** s = (adj **)malloc(t*sizeof(adj *));
	for(i = 0;i<n;i++){
		nd *p = a[i];
		while(p){
			if (p->v > i){
				s[j] = (adj *)malloc(sizeof(adj));
				s[j]->s = i;
				s[j]->d = p->v;
				s[j]->w = p->w;
				j++;
			}
			p = p->next;
		}
	}
	printf("Generated!\n");
	
	ks(s,n,t);
	printf("\n");
	for (i=0;i<t;i++){
		if (i)
			printf(",");
		printf("|%d|%d|%d| ",s[i]->s,s[i]->d,s[i]->w );
	}

	return 0;
}