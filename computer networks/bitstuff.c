#include<stdio.h>
void main()
{
    int a[15];
    int i, j, k, n, c=0, pos=0;
    printf("Enter the number of bits : ");
    scanf("%d",&n);
    printf("Enter the bits in 0s and 1s : ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        {
            if(a[i]==1)
                {
                    c++;
                    if(c==5)
                        {
                            pos=i+1;
                            c=0;
                            for(j=n-1;j>=pos;j--)
                                {
                                    k=j+1;
                                    a[k]=a[j];
                                }
                            a[pos]=0;
                            n=n+1;
                        }
                }
             else
            c=0;
        }
    printf("Data after stuffing");
    printf("01111110");
    for(i=0;i<n;i++)
    printf("%d",a[i]);
    printf("01111110");
}