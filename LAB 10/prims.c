#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int v;
	int w;
	struct node* next;
}nd;

typedef struct adjacent{
	int c;
	int w;
	int p;
	int i;
}adj;

void heapify(adj **a,int* sup,int i,int n){
	int lc = 2*i + 1;
	int rc = 2*i + 2;
	int small = i;
	if (lc<n && (a[sup[lc]]->w)<(a[sup[small]]->w))
		small = lc;
	if (rc<n && (a[sup[rc]]->w)<(a[sup[small]]->w))
		small = rc;
	if (small!=i){
		int temp = sup[small];
		sup[small] = sup[i];
		sup[i] = temp;
		a[sup[i]]->i = i;
		a[sup[small]]->i = small;
		heapify(a,sup,small,n);
	}
}

void buildHeap(adj **a,int* sup,int n){
	int i = (n/2)-1;
	while(i >= 0){
		heapify(a,sup,i,n);
		i--;
	}
}

int extract(adj** a,int *s,int *n){
	int r = s[0];
	a[s[0]]->c = 1;
	s[0] = s[(*n)-1];
	s[(*n)-1] = r;
	(*n)--;
	heapify(a,s,0,*n);
	return r;
}

void dec_prio(adj** a,int* s,int t){
	if(t>0){
		int n = (t-1)/2;
		if (a[s[n]]->w > a[s[t]]->w){
			int temp = s[t];
			s[t] = s[n];
			s[n] = temp;
			a[s[t]]->i = t;
			a[s[n]]->i = n;
			dec_prio(a,s,n);
		}
	}
}

void prims(nd** a,adj** s,int* sup,int n){
	buildHeap(s,sup,n);
	int t = n;
	int hts = n;
	while(t--){
		int u = extract(s,sup,&hts);
		nd* p = a[u];
		while(p){
			if ((s[p->v]->c == 0) && (p->w < s[p->v]->w)){
				s[p->v]->w = p->w;
				s[p->v]->p = u;
				dec_prio(s,sup,s[p->v]->i);
			}
			p=p->next;
		}
	}
}

int main(){
	int n,i,c;
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
	adj** s = (adj **)malloc(n*sizeof(adj *));
	int* sup = (int *)malloc(n*sizeof(int));
	for(i = 0;i<n;i++){
		nd *p = a[i];
		s[i] = (adj *)malloc(sizeof(adj));
		s[i]->c = 0;
		s[i]->w = 9999;
		s[i]->p = -1;
		s[i]->i = i;
		sup[i] = i;
	}
	printf("Generated!\n");
	
	s[0]->w = 0;
	//ks(s,n,t);
	prims(a,s,sup,n);

	printf("\n");
	for (i=0;i<n;i++){
		if (i)
			printf(",");
		printf("|%d|%d|%d|%d| ",s[i]->c,s[i]->w,s[i]->p,s[i]->i );
	}

	//for (i=0;i<n;i++) printf("%d ,",sup[i]);

	return 0;
}