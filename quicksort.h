#ifndef QUICKSORT
#define QUICKSORT

int hoareP(int* arr, int l, int r)
{
    while(l < r)
    {
        if(arr[l] <= arr[0])
        {
            l++;
        }
        else if(arr[r] >= arr[0])
        {
            r--;
        }
        else
        {
            std::swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }

    if(arr[0] > arr[r])
        std::swap(arr[0], arr[r]);
    else
        std::swap(arr[0], arr[--r]);

    return r;
}

void quick_sort(int* arr, int len)
{
    if(len - 1 > 0)
    {
        int pivot = hoareP(arr, 1, len - 1);
        quick_sort(arr, pivot);
        quick_sort(arr + pivot + 1, len - (pivot + 1));
    }
}

#endif // QUICKSORT
