
//both directional partitioning using linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
	int x;
	struct node* next;
	struct node* prev;
};

typedef struct node nd;

nd* partition(nd *l,nd *h){
	nd *d = l;
	nd *u = h;
	int p = l->x;
	while(1){
		while((d->x)<= p && (d != h)){
			d = d->next;
		}
		while ((u->x) > p){
			u = u->prev;
		}
		if ((d != u) && (d != (u->next))){
			int temp = d->x;
			d->x = u->x;
			u->x = temp;
		} else {
			int temp = l->x;
			l->x = u->x;
			u->x = temp;
			return u;
		}
	}
}

void qs(nd *l,nd *h){
	if (((l->prev) != h) && (l != h)) {
		nd* p = partition(l,h);
		printf ("%d\t",p->x);
		qs(l,(p->prev));
		qs((p->next),h);
	}
}

int main(){
	int n,i;
	nd *a,*e;
	scanf ("%d",&n);
	for (i = 0;i<n;i++){
		nd *t = (nd*)malloc(sizeof(nd));
		scanf ("%d",&(t->x));
		t->next = NULL;
		if (a == NULL){
			a = t; e = t;
			t->prev = NULL;
		} else {
			e->next = t;
			t->prev = e;
			e = t;
		}
	}
	//qs (a,e);
	nd* t = a;
	while(t){
		printf ("%d ",t->x);
		t = t->next;
	}
	t = e;
	printf("\n");
	/*while(t){
		printf ("%d ",t->x);
		t = t->prev;
	}*/
	printf ("\n");
	return 0;
}
