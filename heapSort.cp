#include <iostream>

using namespace std;

int array[10] = {0};
int heapSize = 0;

void myswap(int *p, int i, int j)
{
    int temp = p[i];
    p[i] = p[j];
    p[j] = temp;
}

void heap_push(int value)
{
    array[heapSize] = value;
    int index = heapSize;
    while ((index-1)/2 >= 0 && array[index] > array[(index-1)/2]) {
        myswap(array, index, (index-1)/2);
        index = (index-1)/2;
    }
    heapSize++;
    
}

void heapify(int* p, int idx, int size)
{
    while (idx*2+1 < size)
    {
        int left = idx*2+1;
        int large, allLarge = idx;
        large = (left+1) < size && p[left+1] > p[left] ? left+1 : left;
        if (p[large] > p[idx])
        {
            allLarge = large;
            myswap(p, large, idx);
        }
        if (allLarge == idx)
            break;
        idx = allLarge;
    } 
}

int main()
{
    int number;
    while (cin >> number)
    {
        heap_push(number);
    }

    for (size_t i = 0; i < 10; ++i)
    {
        cout << array[i] << " ";
    }

    while (heapSize > 0)
    {
        int large = array[0];
        cout << large << endl;
        myswap(array, 0, heapSize-1);
        heapify(array, 0, --heapSize);
    }
    return 0;
}
