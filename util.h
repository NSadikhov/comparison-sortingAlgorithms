#ifndef UTIL
#define UTIL

void printArr(int *arr, int len) {
    std::cout << "[";
    for (int i = 0 ; i < len ; i ++) {
        std::cout << arr[i];
        if(i != len - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

#endif // UTIL
