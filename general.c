int* readIntArr(int len)
{
    int* arr = malloc(sizeof(int)* len);
    int i;
    for(i = 0; i < len; i++)
        scanf("%d",arr + i);

    return arr;
}

void printIntArr(int* arr,int len)
{
    if (!arr || len == 0)
        return;

    int i;
    for (i=0;i< len;i++)
        printf("%d\n",arr[i]);

    printf("---*** Done ***---");
}
