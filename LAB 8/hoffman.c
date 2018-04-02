#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct hoff{
	struct hoff *lptr;
	struct hoff *rptr;
	int c;
	int f;
	char *s;
	int n;
};

typedef struct hoff hot;

void heapify(hot **a,int i,int n){
	int lc = 2*i + 1;
	int rc = 2*i + 2;
	int small = i;
	if (lc<n && (a[lc]->f)<(a[small]->f))
		small = lc;
	if (rc<n && (a[rc]->f)<(a[small]->f))
		small = rc;
	if (small!=i){
		hot* temp = a[small];
		a[small] = a[i];
		a[i] = temp;
		heapify(a,small,n);
	}
}

void buildHeap(hot **a,int n){
	int i = (n/2)-1;
	while(i >= 0){
		heapify(a,i,n);
		i--;
	}
}

hot* extract (hot **a,int *n){
	hot* temp= a[0];
	a[0] = a[(*n)-1];
	(*n)--;
	heapify(a,0,*n);
	return temp;
}

void insert (hot **a,hot *p, int *n){
	a[(*n)] = p;
	(*n)++;
	buildHeap(a,*n);
}

void preorder(hot *a){
	if (a){
		if (a->c >64){
			printf("%c %d ",(char)a->c,a->f);
			int i;
			for (i=0;i<(a->n);i++){
				printf ("%c",a->s[i]);
			}
			printf ("\n");
		}
		//else printf("# %d\n",a->f);
		preorder(a->lptr);
		preorder(a->rptr);
	}
}

int encodeLetter(hot *a,char x, char *c, int n){
	if (a){
		if (a->c == x || a->c == x-('a'-'A')){
			int i;
			a->s = (char *) malloc (n*sizeof(char));
			for (i = 0;i<n;i++){
				a->s[i] = c[i];
				printf("%c",c[i] );
			}
			a->n = n;
			return 1;
		}
		c[n] = '0';
		if (!encodeLetter(a->lptr,x,c,n+1)){
			c[n] = '1';
			return (encodeLetter(a->rptr,x,c,n+1));
		}
		return 0;
	}
}

int countFreq(char *s,int *f,int x){
	int i,count = 0;
	for (i=0;i<x;i++){
		if (s[i]>='A' && s[i]<='Z')
			f[s[i]-'A']++;
		if (s[i]>='a' && s[i]<='z')
			f[s[i]-'a']++;
	}
	for (i=0;i<26;i++){
		if (f[i]>0)
			count++;
	}
	return count;
}

int main(){
	int n,i,x,k;
	printf ("Enter the word to be encoded: ");
	char s[50];
	scanf("%s",s);
	x = strlen(s);
	int *f = (int *)malloc(26*sizeof(int));
	for (i=0;i<26;i++) f[i]=0;
	n = countFreq(s,f,x);
	hot **a = (hot**)malloc(n*sizeof(hot*));
	for (i = 0,k=0;i<26;i++){
		if (f[i]>0){
			a[k] = (hot *)malloc(sizeof(hot));
			a[k]->f = f[i];
			a[k]->c = 65 + i;
			a[k]->lptr = NULL;
			a[k]->rptr = NULL;
			k++;
		}
	}
	int hts = n;
	buildHeap(a,n);
	while(hts>1){
		hot *p1 = extract(a,&hts);
		hot *p2 = extract(a,&hts);
		hot *p = (hot *) malloc(sizeof(hot));
		p->lptr = p1;
		p->rptr = p2;
		p->f = p1->f + p2->f;
		p->c = 0;
		insert (a,p,&hts);
	}
	char *c = (char *)malloc(30*sizeof(char));
	int y = 0;
	printf("The encoded word:");
    for (i=0;i<x;i++){
        encodeLetter(a[0],s[i],c,y);
	}
	//encodeLetter(a[0],c,y);
	printf("\n");
	preorder(a[0]);
	//for (i = 0;i<n;i++){ printf ("%c %d\n",(char)a[i]->c,a[i]->f);}
	return 0;
}
