#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>

struct timeval t1,t2,t3;

void main(){
        long int ab[10];
        int c=0;
        int n=10000;
        int i,j,k;
        for (n;n<=50000;n+=10000){
                int *a = (int *)malloc(n*sizeof(int));
                long int x=0,y=0,z;
                for (k = 0;k<1000;k++){
                        for (i=0;i<n;i++){
                                a[i] = (int)rand();
                        }
                        gettimeofday(&t1,NULL);

                        for (i=0;i<n;i++){
                        int x = 0;
                                for (j=0;j<n-1;j++){
                                        if (a[j]>a[j+1]){
                                                x++;
                                                int temp = a[j];
                                                a[j] = a[j+1];
                                                a[j+1] = temp;
                                        }
                                }
                                if (x==0)
                                        break;
                        }
                        gettimeofday(&t2,NULL);
                        t3.tv_sec = t2.tv_sec - t1.tv_sec;
                        t3.tv_usec = t2.tv_usec - t1.tv_usec;
                        x+= t3.tv_sec;
                        y+= t3.tv_usec;
                        printf ("\nstep %d div 1 is running %d out of 1000",(n/10000),k);
                }
                x/=1000;
                y/=1000;
                z = (x*1000000)+y;
                ab[c++]=z;
                for (k = 0;k<1000;k++){
                        gettimeofday(&t1,NULL);

                        for (i=0;i<n;i++){
                        int x = 0;
                                for (j=0;j<n-1;j++){
                                        if (a[j]>a[j+1]){
                                                x++;
                                                int temp = a[j];
                                                a[j] = a[j+1];
                                                a[j+1] = temp;
                                        }
                                }
                                if (x==0)
                                        break;
                        }
                        gettimeofday(&t2,NULL);
                        t3.tv_sec = t2.tv_sec - t1.tv_sec;
                        t3.tv_usec = t2.tv_usec - t1.tv_usec;
                        x+= t3.tv_sec;
                        y+= t3.tv_usec;
                        printf ("\nstep %d div 2 is running %d out of 1000 ",n/10000,k);
                }
                x/=1000;
                y/=1000;
                z = (x*1000000)+y;
                ab[c++]=z;
        }
        for (i=0;i<10;i+=2){
                printf ("\n%ld %ld",ab[i],ab[i+1]);
        }

}
