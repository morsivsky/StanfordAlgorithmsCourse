#include <stdio.h>
#include <stdlib.h>
#include "mergeSort.h"
#include "quickSort.h"
#include "general.h"

int main()
{
    printf("Please enter array length..\n");
    int len;
    scanf("%d",&len);

    int * test1= readIntArr(len);
    printf("Sorting....\n");
    printf("result:\n");
    quickSort(test1,0,len);
    printIntArr(test1,len);

    return 0;
}

