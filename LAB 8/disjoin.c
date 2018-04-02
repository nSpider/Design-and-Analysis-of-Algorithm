#include<stdio.h>
#include<stdlib.h>

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

int find (int *a, int i){
	if (a[i]<0)
		return i;
	a[i] = find (a, a[i]);
	return a[i];
}

int main(){
	int a[10],n = 10,i,c,x,y;
	for (i = 0;i<n;i++){
		a[i] = -1;
	}
	while(1){
		printf ("Press 1 to join\nPress 2 to find\nPress 3 to Exit\n");
		scanf("%d",&c);
		switch(c){
			case 1: printf ("Enter two data to join:");
					scanf ("%d %d",&x,&y);
					join(a,x,y);
					break;
			case 2: printf("Enter a data to find:");
					scanf ("%d",&x);
					printf ("Data found in %d\n",find(a,x));
					break;
			case 3: exit(0);
		}
	}
	return 0;
}