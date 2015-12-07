#include<stdio.h>
int toBinary(int,int[]);
int twoPow(int);
int multiply(int *multiplicand,int* multiplier, int counter);
main()
{
    int num1,num2,flag,counter=8,sign=0,result;
    int multiplicand[8]={0},multiplier[8]={0};
    puts("Enter the two numbers");
    scanf("%d%d",&num1,&num2);
    if(num1<0)
    {
        sign++;
        num1*=-1;
    }
    if(num2<0)
    {
        sign--;
        num2*=-1;
    }
    toBinary(num1,multiplicand);
    toBinary(num2,multiplier);
    result=multiply(multiplicand,multiplier,counter);
    if(sign!=0)
        result*=-1;
    printf("Product=%d",result);
}
int toBinary(int num,int *multi)
{
    int flag=0;
    while(num>0)
    {
        multi[flag++]=num%2;
        num/=2;
    }
    return(flag);
}

int multiply(int *multiplicand,int* multiplier, int counter)
{
    int flag,flag1,extend=0,extend1=0,flag2,result=0;
    int add[8]={0};
    for(flag=0;flag<counter;flag++)
    {
        if(multiplier[0]==1)
        {
            for(flag1=0;flag1<counter;flag1++)
            {
                extend=(add[flag1]&multiplicand[flag1])|((add[flag1]^multiplicand[flag1])&extend1);
                add[flag1]=(add[flag1]^multiplicand[flag1])^extend1;
                extend1=extend;
            }
        }
        shift(extend1,add,multiplier,(counter-1));
        extend=0;
        extend1=0;
}
    for(flag=0;flag<counter;flag++)
        if(multiplier[flag]==1)
        result+=twoPow(flag);
    for(flag=0;flag<counter;flag++)
        if(add[flag]==1)
        result+=twoPow(counter+flag);
    return(result);
}

shift(int extend,int *add,int *multiplier,int counter)
{
    int flag;
    for(flag=1;flag<=counter;flag++)
    {
        multiplier[flag-1]=multiplier[flag];
    }
    multiplier[counter]=add[0];
    for(flag=1;flag<=counter;flag++)
    {
        add[flag-1]=add[flag];
    }
    add[counter]=extend;
}
int twoPow(int num)
{
    if(num == 0)
        return 1;
    else
        return(2*twoPow(num-1));
}
