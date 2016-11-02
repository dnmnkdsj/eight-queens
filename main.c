#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count=0;

int position_judge (int row,int column,int *a)
{
    int judge=1;
    for (int line_count=0; line_count<row; line_count++)
    {
        if (column==a[line_count])
            judge=0;
        else if (abs(column-a[line_count])==abs(row-line_count))
            judge=0;
    }
    return judge;
}

void position_print (int n,int *a)
{
    for (int row=0; row<n; row++)
    {
        for (int column=0; column<a[row]; column++)
            printf("__");
        printf("%c",36);
        for (int column=a[row]+1; column<n; column++)
            printf("__");
        printf("\n");
    }
    printf("\n\n");
}

void find_next (int n,int row,int *a)
{
    row++;
    for (int column=0; column<n; column++)
        if (position_judge(row,column,a)==1)
        {
            a[row]=column;
            if (row<n-1)
                find_next(n,row,a);
            else if (position_judge(row,column,a)==1)
            {
                position_print(n,a);
                count ++;
            }
        }
}

int main()
{
    int n=8,row,column;
    printf("请输入棋盘的边长n:\n");
    scanf ("%d",&n);
    int a[n];
    for (int z=0; z<n; z++)
        a[z]=0;

    row=0;
    for (column=0; column<n; column++)
    {
        a[row]=column;
        find_next(n,row,a);
    }
    printf("在棋盘边长为n的情况下共有%d种解。\n",count);

    return 0;
}
