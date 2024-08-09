//  Max and min heap implementation
#include <bits/stdc++.h>
using namespace std;
class Heap
{
public:
    int arr[100];
    int size;
    Heap()
    {
        arr[0] = -1;
        size = 0;
    }
    //      TC --> log(n)
    void insert(int val)
    {
        size += 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            //  max sign < ,  min sign >
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    // Delete heap node   TC --> log(n)
    // heap delete means first node 
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
        void DeleteHeapRoot()
    {
        if (size == 0)
        {
            cout << "No Need to delete " << endl;
            return;
        }
        // step - 1
        arr[1] = arr[size];
        // step - 2 last element delete
        size--;
        // take root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftIdx = 2 * i;
            int rightIdx = 2 * i + 1;
            if (leftIdx < size && arr[i] < arr[leftIdx])
            {
                swap(arr[i], arr[leftIdx]);
                i = leftIdx;
            }
            else if (rightIdx < size && arr[i] < arr[rightIdx])
            {
                swap(arr[i], arr[rightIdx]);
                i = rightIdx;
            }
            else
            {
                return;
            }
        }
    }
    // Deletion in max or min heap
};
int main()
{
    Heap h;
    h.insert(6);
    h.insert(9);
    h.insert(13);
    h.insert(4);
    h.insert(15);
    cout << " insertion of max heap" << endl;
    h.print();
    cout << "            " << endl;
    cout << "Delettion of max heap "<< endl;
    h.DeleteHeapRoot();
    h.print();
    return 0;
}