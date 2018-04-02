#include<stdio.h>
#include<stdlib.h>

struct Item{
	float q;
	float p;
};

typedef struct Item item;

void merge(item **a,int l,int m, int h){
	item **b = (item **)malloc((h-l+1)*sizeof(item **));
	int i=l,j=m+1,k=0;
	while(i<=m && j<=h){
		if (((a[i]->p)/(a[i]->q))>((a[j]->p)/(a[j]->q))){
			b[k] = a[i];
			k++;i++;
		} else {
			b[k] = a[j];
			k++;j++;
		}
	}

	while(i<=m){
		b[k] = a[i];
		k++;i++;
	}

	while(j<=h){
		b[k] = a[j];
		k++;j++;
	}

	i = l, k = 0;
	while(i<=h){
		a[i] = b[k];
		i++;k++;
	}
}

void sort (item **a,int l,int h){
	if (l<h){
		int m = (l+h)/2;
		sort (a,l,m);
		sort (a,m+1,h);
		merge (a,l,m,h);
	}
}

float knapsack (item **a,int n, float w){
	sort (a,0,n-1);
	int i;
	//for (i=0;i<n;i++){ printf("%f %f\n",(a[i]->q),(a[i]->p)); }
	float tf = 0;
	for(i=0;i<n && w>0;i++){
		if (a[i]->q < w){
			w = w - (a[i]->q);
			tf += (a[i]->p);
		} else {
			tf += (a[i]->p)*(w/(a[i]->q));
			w = 0;
		}
	}
	return tf;
}

int main(){
	printf ("Enter the maximum weight of knapsack:");
	float w;
	scanf("%f",&w);
	printf ("Enter no of items present:");
	int n,i;
	scanf ("%d",&n);
	item **a = (item **)malloc(n*sizeof(item *));
	printf ("Enter values of items:");
	float xx,yy;
	for (i=0;i<n;i++){
		a[i] =(item *) malloc (sizeof(item));
		scanf("%f %f",&xx,&yy);
		a[i]->q = xx;
		a[i]->p = yy;
	}
	float profit = knapsack(a,n,w);
	printf ("Profit is :%0.2f",profit);
}