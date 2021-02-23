#ifndef MERGESORT
#define MERGESORT

void mergeArr(int* arr, int len)
{
    int len_l = (len + 1) / 2;
    int len_r = (len / 2);

    int* left = new int[len_l];
    int* right = new int[len_r];

    for(int i = 0; i < len_l; ++i)
        left[i] = arr[i];

    for(int i = 0; i < len_r; ++i)
        right[i] = arr[i + len_l];

    int l = 0, r = 0;

    int counter = 0;
    while(counter < len)
    {
        if(l < len_l && r < len_r)
        {
            if(left[l] <= right[r])
            {
                arr[counter] = left[l];
                l++;
            }
            else
            {
                arr[counter] = right[r];
                r++;
            }
        }
        else if(l < len_l)
        {
            arr[counter] = left[l];
            l++;
        }
        else if (r < len_r)
        {
            arr[counter] = right[r];
            r++;
        }

        counter++;
    }

    delete [] left;
    delete [] right;
}

void merge_sort(int* arr, int len)
{
    int m;

    if(len % 2 == 0)
    {
        m = len / 2;
    }
    else
    {
        m = (len + 1) / 2;
    }

    if(len > 2)
    {
        merge_sort(arr, m);
        if(len / 2 > 1)
            merge_sort(arr + m, len / 2);

        mergeArr(arr, len);
    }
    else if(len == 2)
    {
        mergeArr(arr, len);
    }
}

#endif // MERGESORT
