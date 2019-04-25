void quickSort(int* arr,int start,int max)
{
    if(start >= max)
        return;

    int newIdx = start;

    int i;
    for(i=start;i<max + 1 ;i++)
    {
        if(arr[i] < arr[start])
        {
            int temp = arr[i];
            arr[i] =arr[newIdx +1];
            arr[newIdx +1] =temp;
            newIdx++;
        }
    }

    int temp1=arr[newIdx];
    arr[newIdx]=arr[start];
    arr[start]=temp1;

    quickSort(arr,start, newIdx -1);
    quickSort(arr,newIdx +1,max);
}
//order statistics select
int RandomSelect(int* arr, int start, int maxIdx, int* orderStatistic)
{
	if (start >= maxIdx)
		return arr[start];

	int newIdx = start;

	int i;
	for (i = start; i < maxIdx; i++)
	{
		if (arr[i] < arr[start])
		{
			int temp = arr[i];
			arr[i] = arr[newIdx + 1];
			arr[newIdx + 1] = temp;
			newIdx++;
		}
	}

	int temp1 = arr[newIdx];
	arr[newIdx] = arr[start];
	arr[start] = temp1;

	if (newIdx == *orderStatistic)
	{
		*orderStatistic = newIdx;
		return arr[newIdx];
	}

	else if (newIdx > *orderStatistic)
	{
		return RandomSelect(arr, start, newIdx -1 , orderStatistic);
	}
	else
	{
		return RandomSelect(arr, newIdx +1 , maxIdx, orderStatistic);
	}
}
