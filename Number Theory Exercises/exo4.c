#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,j,count=0;
    printf("enter the number: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        arr[i]=1;
    }
    for(i=2;i*i<=n;i++)
    {
        if(arr[i]==1)
        {
            for(j=i*i;j<=n;j=j+i)
            {
                arr[j]=0;
            }
        }
    }
    printf("the prime numbers are: ");
    for(i=2;i<=n;i++)
    {
        if(arr[i]==1)
        {
            printf("%d ",i);
        }
    }
    return 0;
}