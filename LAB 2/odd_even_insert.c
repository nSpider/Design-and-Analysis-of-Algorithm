#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>

int main(){
        int c=0;
        int n=10;
        int i,j,k,temp;
        for (k = 0;k<10;k++){
            int *a = (int *)malloc(n*sizeof(int));
        	printf ("Part %d :\n",k+1);
            for (i=0;i<n;i++){
                    a[i] = (int)rand()%1000;
                    printf ("%d ",a[i]);
            }
            printf ("\n");


            for (i=1;i<n;i=i+2){
                temp = a[i];
                j = i-2;
                while(j>=0 && a[j]<temp){
                        a[j+2] = a[j];
                        j=j-2;
                }
                a[j+2] = temp;
            }

            for (i=2;i<n;i=i+2){
                temp = a[i];
                j = i-2;
                while(j>=0 && a[j]>temp){
                        a[j+2] = a[j];
                        j=j-2;
                }
                a[j+2] = temp;
            }

		    for (i=0;i<n;i++){
                    printf ("%d ",a[i]);
            }
            printf ("\n");
            n++;
		}
	return 0;
}