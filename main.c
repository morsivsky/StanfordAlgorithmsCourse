#include <stdio.h>
#include <stdlib.h>
#include "mergeSort.h"
#include "general.h"

int main()
{
    printf("Please enter array length..\n");
    int len;
    int invCount=0;
    scanf("%d",&len);
    int * test1= readIntArr(len);
    printf("Sorting....\n");
    printf("result:\n");
    int* result = mergeSort(test1,len,&invCount);

    printIntArr(result,len);
    printf("\n\n %d",invCount);
    return 0;
}
/*
5
2
4
1
3
5
*/
