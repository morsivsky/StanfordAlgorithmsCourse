#include <stdio.h>
#include <stdlib.h>
#include "mergeSort.h"
#include "general.h"

int main()
{
    printf("Please enter array length..\n");
    int len;
    scanf("%d",&len);
    int * test1= readIntArr(len);
    printf("Sorting....\n");
    printf("result:\n");
    int* result = mergeSort(test1,len);

    printIntArr(result,len);
    return 0;
}
