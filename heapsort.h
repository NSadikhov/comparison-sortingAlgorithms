#ifndef HEAPSORT
#define HEAPSORT

void checkHeapParent(int* arr, int index)
{
    int parent = (index - 1) / 2;
    if(arr[index] > arr[parent])
    {
        std::swap(arr[index], arr[parent]);
        if(parent > 0)
            checkHeapParent(arr, parent);
    }

}

void checkHeapChild(int* arr, int len, int index)
{
    int child_l = (2 * index) + 1;
    int child_r = (2 * index) + 2;

    if(child_l <= len)
    {
        if(child_r <= len && arr[child_r] > arr[child_l])
        {
            if (arr[child_r] > arr[index])
            {
                std::swap(arr[index], arr[child_r]);

                    checkHeapChild(arr, len, child_r);
            }
        }
        else
        {
            if(arr[child_l] > arr[index])
            {
                std::swap(arr[index], arr[child_l]);

                    checkHeapChild(arr, len, child_l);
            }
        }
    }
}

void constructHeap(int* arr, int len)
{
    for (int i = 1; i < len; ++i)
    {
        checkHeapParent(arr, i);
    }
}

void heap_sort(int* arr, int len)
{
    constructHeap(arr, len);
    for(int i = len - 1; i >= 0; --i)
    {
        std::swap(arr[0], arr[i]);
        checkHeapChild(arr, i - 1, 0);
    }
}

#endif // HEAPSORT
