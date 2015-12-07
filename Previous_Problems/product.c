#include<stdio.h>
void product(int*,int*);
main()
{
    int length,flag,mult=1;
    puts("Enter length of array");
    scanf("%d",&length);
    int *input=malloc(length*sizeof(int));
    int *result=malloc(length*sizeof(int));
    result[length-1]=input[length-1];
    for(flag=0;flag<length;flag++)
    {
        scanf("%d",&input[flag]);
    }

    if(input[length-1]!=0)
        result[length-1]=input[length-1];

    for(flag=length-2;flag>=0;flag--)
    {
        if(input[flag]!=0)
        result[flag]=result[flag+1]*input[flag];
    }
    for(flag=1;flag<length;flag++)
        if(input[flag]!=0)
        input[flag]*=input[flag-1];

    for(flag=1;flag<length-1;flag++)
    {
        if(input[flag]!=0)
            result[flag]=input[flag-1]*result[flag+1];
    }
    if(input[flag]!=0)
    result[length-1]=input[length-2];

    for(flag=0;flag<length;flag++)
        printf("%d %d\n",input[flag],result[flag]);
    free(input);
    free(result);
}
