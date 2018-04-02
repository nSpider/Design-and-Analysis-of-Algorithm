#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>

struct timeval t1,t2,t3;

void main(){
        long long int ab[10];
        int c=0;
        int n=10000;
        int i,j,k,temp;
        for (n;n<=50000;n+=10000){
                int *a = (int *)malloc(n*sizeof(int));
                long long int x=0,y=0,z;
                for (k = 0;k<50;k++){
                        for (i=0;i<n;i++){
                                a[i] = (int)rand();
                        }
                        gettimeofday(&t1,NULL);

                        // Sorting Code Starts Here

                        for (i=1;i<n;i++){
                                temp = a[i];
                                j = i-1;
                                while(j>0 && a[j]>temp){
                                        a[j+1] = a[j];
                                        j--;
                                }
                                a[j+1] = temp;
                        }

                        // Sorting Code Ends Here

                        gettimeofday(&t2,NULL);
                        t3.tv_sec = t2.tv_sec - t1.tv_sec;
                        t3.tv_usec = t2.tv_usec - t1.tv_usec;
                        t3.tv_usec += (t3.tv_sec * 1000000l);
                        t3.tv_sec = t3.tv_usec / 1000000;
                        t3.tv_usec = t3.tv_usec % 1000000;
                        x+= t3.tv_sec;
                        y+= t3.tv_usec;
                        printf ("\nstep %d div 1 is running %d out of 50\t%ld\t%ld",(n/10000),k+1,t3.tv_sec,t3.tv_usec);
                }
                //x/=50;
                //y/=50;
                z = (x*1000000l)+y;
                z = z/50;
                ab[c++]=z;
                x=0;y=0;
                for (k = 0;k<50;k++){
                        gettimeofday(&t1,NULL);

                        // Sorting Code Starts Here

                        for (i=1;i<n;i++){
                                temp = a[i];
                                j = i-1;
                                while(j>0 && a[j]>temp){
                                        a[j+1] = a[j];
                                        j--;
                                }
                                a[j+1] = temp;
                        }

                        // Sorting Code Ends Here

                        gettimeofday(&t2,NULL);
                        t3.tv_sec = t2.tv_sec - t1.tv_sec;
                        t3.tv_usec = t2.tv_usec - t1.tv_usec;
                        t3.tv_usec += (t3.tv_sec * 1000000l);
                        t3.tv_sec = t3.tv_usec / 1000000;
                        t3.tv_usec = t3.tv_usec % 1000000;
                        x+= t3.tv_sec;
                        y+= t3.tv_usec;
                        printf ("\nstep %d div 2 is running %d out of 50\t%ld\t%ld",(n/10000),k+1,t3.tv_sec,t3.tv_usec);
                }
                //x/=50;
                //y/=50;
                z = (x*1000000l)+y;
                z = z/50;
                ab[c++]=z;
        }
        for (i=0;i<10;i+=2){
                printf ("\n%lld %lld",ab[i],ab[i+1]);
        }

}

