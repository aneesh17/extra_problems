#include<stdio.h>
int numofDig(int);
int length(char *arr);
void dateToText(int,int,int);
void dateCheck(char *dateInput,int len);
Date(int);
Month(int);
Year(int);
main()
{
    char dateInput[15];
    puts("Enter date in dd/mm/yyyy format:");
    gets(dateInput);
    dateCheck(dateInput,length(dateInput));
}

dateCheck(char *dateInput,int len)
{
    int flag,place;
    int date=0,month=0,year=0;
    for(place=0,flag=len-1;dateInput[flag]!='/'&&flag>=0;flag--,place++)
    {
        year+=tenPow(place)*(dateInput[flag]-'0');
    }
    if(numofDig(year)!=4)
    {
        puts("Invalid format");
        exit(1);
    }
    place=0;
    for(place=0,flag=flag-1;dateInput[flag]!='/'&&flag>=0;flag--,place++)
    {
        month+=tenPow(place)*(dateInput[flag]-'0');
    }
    if(month<=0||month>12)
    {
        puts("Invalid Date");
        exit(1);
    }
    for(place=0,flag=flag-1;dateInput[flag]!='/'&&flag>=0;flag--,place++)
    {
        date+=tenPow(place)*(dateInput[flag]-'0');
    }
    switch(date)
    {
        case 0:
            printf("Invalid Format");
            exit(0);
        case 31:
            if (month == 4 || month == 6 || month == 9 || month == 11)
            {
                printf("Invalid Date");
                exit(0);
            }
        case 29:
        if (month == 2)
        {
            if(year%100==0)
            {
                if(year%400!=0)
                {
                    printf("Invalid Date");
                    exit(1);
                }
            }
            else if (year % 4 != 0 )
            {
                printf("Invalid Date");
                exit(1);
            }
        default:
            if(date>31)
            {
                printf("Invalid Format");
                exit(0);
            }
        }
    }
    Date(date);
    Month(month);
    if(year/100%10==0)
    {
        switch(year/1000)
        {
            case 1:
            printf(" One Thousand");
            break;
        case 2:
            printf(" Two Thousand");
            break;
        case 3:
            printf(" Three Thousand");
            break;
        case 4:
            printf(" Four Thousand");
            break;
        case 5:
            printf(" Five Thousand");
            break;
        case 6:
            printf(" Six Thousand");
            break;
        case 7:
            printf(" Seven Thousand");
            break;
        case 8:
            printf(" Eight Thousand");
            break;
        case 9:
            printf(" Nine Thousand");
            break;
        }
    }
    else
        Year(year/100);
    Year(year%100);
}

Date(int date)
{
    if(date>=20)
    {
        switch(date/10)
        {
        case 2:
            printf("Twenty ");
            break;
        case 3:
            printf("Thirty ");
            break;
        }
        date%=10;
     }
     switch(date)
    {
        case 1:
            printf("First");
            break;
        case 2:
            printf("Second");
            break;
        case 3:
            printf("Third");
            break;
        case 4:
            printf("Fourth");
            break;
        case 5:
            printf("Fifth");
            break;
        case 6:
            printf("Sixth");
            break;
        case 7:
            printf("Seventh");
            break;
        case 8:
            printf("Eighth");
            break;
        case 9:
            printf("Ninth");
            break;
        case 10:
            printf("Tenth");
            break;
        case 11:
            printf("Eleventh");
            break;
        case 12:
            printf("Twelfth");
            break;
        case 13:
            printf("Thirteenth");
            break;
        case 14:
            printf("Fourteenth");
            break;
        case 15:
            printf("Fifteenth");
            break;
        case 16:
            printf("Sixteenth");
            break;
        case 17:
            printf("Seventeenth");
            break;
        case 18:
            printf("Eighteenth");
            break;
        case 19:
            printf("Nineteenth");
            break;
    }
}

Month(int month)
{
    switch(month)
    {
        case 1:
            printf(" January");
            break;
        case 2:
            printf(" February");
            break;
        case 3:
            printf(" March");
            break;
        case 4:
            printf(" April");
            break;
        case 5:
            printf(" May");
            break;
        case 6:
            printf(" June");
            break;
        case 7:
            printf(" July");
            break;
        case 8:
            printf(" August");
            break;
        case 9:
            printf(" September");
            break;
        case 10:
            printf(" October");
            break;
        case 11:
            printf(" November");
            break;
        case 12:
            printf(" December");
            break;
    }
}

Year(int year)
{
    if(year>=20)
    {
        switch(year/10)
        {
        case 2:
            printf(" Twenty ");
            break;
        case 3:
            printf(" Thirty ");
            break;
        case 4:
            printf(" Fourty ");
            break;
        case 5:
            printf(" Fifty");
            break;
        case 6:
            printf(" Sixty");
            break;
        case 7:
            printf(" Seventy");
            break;
        case 8:
            printf(" Eighty");
            break;
        case 9:
            printf(" Ninty");
            break;
        }
        year%=10;
     }
     switch(year)
    {
        case 1:
            printf(" One");
            break;
        case 2:
            printf(" Two");
            break;
        case 3:
            printf(" Three");
            break;
        case 4:
            printf(" Four");
            break;
        case 5:
            printf(" Five");
            break;
        case 6:
            printf(" Six");
            break;
        case 7:
            printf(" Seven");
            break;
        case 8:
            printf(" Eight");
            break;
        case 9:
            printf(" Nine");
            break;
        case 10:
            printf(" Ten");
            break;
        case 11:
            printf(" Eleven");
            break;
        case 12:
            printf(" Twelve");
            break;
        case 13:
            printf(" Thirteen");
            break;
        case 14:
            printf(" Fourteen");
            break;
        case 15:
            printf(" Fifteen");
            break;
        case 16:
            printf(" Sixteen");
            break;
        case 17:
            printf(" Seventeen");
            break;
        case 18:
            printf(" Eighteen");
            break;
        case 19:
            printf(" Nineteen");
            break;
    }
}

int numofDig(int num)
{
    int flag;
    for(flag=0;num>0;num/=10)
        flag++;
    return(flag);
}

int tenPow(int num)
{
    if(num == 0)
        return 1;
    else
        return(10*tenPow(num-1));
}

int length(char *arr)
{
    int flag=0;
    while(arr[flag]!='\0')
        flag++;
    return(flag);
}
