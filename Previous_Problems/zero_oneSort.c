#include<stdio.h>
void swap(int*,int*);
int* sort1(int *,int);
int* sort2(int*,int);
main()
{
    int length,flag;
    puts("Enter length for array");
    scanf("%d",&length);
    int *input=malloc(length*sizeof(int));
    int *result=malloc(length*sizeof(int));
    puts("Enter array of 0s and 1s");
    for(flag=0;flag<length;flag++)
    {
        scanf("%d",&input[flag]);
        if(input[flag]!=0 && input[flag]!=1)
        {
            puts("Invalid Input");
            exit(1);
        }
    }
    result=sort1(input,length);
    for(flag=0;flag<length;flag++)
        printf("%d ",result[flag]);
    result=sort2(input,length);
    for(flag=0;flag<length;flag++)
        printf("%d ",result[flag]);


}
void swap(int *num1,int *num2)
{
    *num1=*num1 + *num2;
    *num2=*num1 - *num2;
    *num1=*num1 - *num2;
}

int* sort1(int *input,int length)//bubble sort
{
    printf("***SORT 1***\n");
    int flag1,flag2,temp_for_input;
    int *result=malloc(length*sizeof(int));
    for(flag1=0;flag1<length;flag1++)
    {
        result[flag1]=input[flag1];
    }
    for(flag1=0;flag1<length-1;flag1++)
    {
        for(flag2=flag1;flag2<length;flag2++)
        {
           if(result[flag1]>result[flag2])
            swap(&result[flag1],&result[flag2]);
        }
    }
    return(result);
}

int* sort2(int* input, int length)
{
    printf("***SORT 2***\n");
    int flag1,sum=0;
    int *result=malloc(length*sizeof(int));
    for(flag1=0;flag1<length;flag1++)
    {
        sum+=input[flag1];
    }
    for(flag1=0;flag1<length-sum;flag1++)
        result[flag1]=0;
    for(;flag1<length;flag1++)
        result[flag1]=1;
    return(result);
}
