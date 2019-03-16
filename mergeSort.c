#include "mergeSort.h"

int* merge(int* arr1,int len1,int* arr2,int len2)
{
    int* finalArr = (int*) malloc(sizeof(int) *(len1+len2));

    int i=0;
    int j=0;
    int k=0;
    while ( i < len1 + len2 && j <len1 && k < len2 )
    {
        while (j <len1 && k < len2 && arr1[j] <= arr2[k]  )
        {
            finalArr[i]= arr1[j];
            i++;
            j++;
        }
        while (j <len1 && k < len2 && arr1[j] > arr2[k] )
        {
            finalArr[i]= arr2[k];
            i++;
            k++;
        }
    }
    while (i < len1 + len2 && j >= len1 && k <len2)
    {
        finalArr[i]= arr2[k];
        i++;
        k++;
    }
    while(i < len1 + len2 && j < len1 && k >= len2)
    {
        finalArr[i]= arr1[j];
        i++;
        j++;
    }
    return finalArr;
}
int* mergeSort(int* arr,int length)
{
    if (length ==1)
        return arr;

    int* arr1 = (int*) malloc(sizeof(int) * (length /2));
    int* arr2 = (int*) malloc(sizeof(int) * ( length -(length /2)));

    int i;
    for(i=0;i<length /2 ;i++)
    {
       arr1[i]=arr[i];
    }

    int y;
    for (y=0 ;i <length ; y++)
    {
        arr2[y]= arr[i];
        i++;
    }

    arr1= mergeSort(&arr1[0],(length /2));
    arr2= mergeSort(&arr2[0],length -(length /2));

    int* sorted=(int*) merge(arr1,length /2,arr2,length -(length /2)) ;
    return sorted;
}
