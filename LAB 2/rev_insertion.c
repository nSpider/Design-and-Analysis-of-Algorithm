#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>

int main(){
        int c=0;
        int n=10;
        int i,j,k,temp;
        int *a = (int *)malloc(n*sizeof(int));
        for (k = 0;k<10;k++){
        	printf ("Part %d :\n",k+1);
            for (i=0;i<n;i++){
                    a[i] = (int)rand();
                    printf ("%d ",a[i]);
            }
            printf ("\n");
			for (i=n-2;i>=0;i--){
		        temp = a[i];
		        j = i+1;
		        while(j<n && a[j]>temp){
		                a[j-1] = a[j];
		                j++;
		        }
		        a[j-1] = temp;
		    }
		    for (i=0;i<n;i++)
                    printf ("%d ",a[i]);
            printf ("\n");
		}
	return 0;
}