#include "Test.h"
#include <iostream>
using namespace std;

int getSmallerValuePos(int leftValue, int rightValue, int leftPos, int rightPos)
{
    return leftValue > rightValue ? rightPos : leftPos;
}

int getReplacedValue(int replaced_value,vector<int> min_heap)
{
     for(int i =0; i<min_heap.size();i++)
        {
                if(min_heap[i] == replaced_value)
                {
                        return i;
                }
        }
}

int getFatherPos(int sonPosition)
{
    if(sonPosition % 2 == 0)
    {
            return (sonPosition - 2) / 2;
    }
    return (sonPosition -1 ) / 2;
}

int rightChild(int fatherPos)
{
    return 2*fatherPos+1;
}


int leftChild(int fatherPos)
{
    return 2*fatherPos;
}

vector<int> replace(vector<int> min_heap, int replaced_value, int replacement)
{
    int replacedValuePos = getReplacedValue(replaced_value,min_heap);
    min_heap[replacedValuePos] = replacement;

    int fatherPos = getFatherPos(replacedValuePos);
    int leftChildPos = leftChild(replacedValuePos);
    int rightChildPos = rightChild(replacedValuePos);

    if(min_heap[replacedValuePos] < min_heap[fatherPos])
    {
        while(fatherPos >= 0 && min_heap[replacedValuePos] < min_heap[fatherPos] )
        {
            int father = min_heap[fatherPos];
            min_heap[fatherPos] = min_heap[replacedValuePos];
            min_heap[replacedValuePos] = father;
            replacedValuePos = fatherPos;
            fatherPos = getFatherPos(replacedValuePos);
        }

    }
    else if(min_heap[replacedValuePos] > min_heap[leftChildPos]  || min_heap[replacedValuePos] > min_heap[rightChildPos])
    {
        while(replacedValuePos < min_heap.size() && (min_heap[replacedValuePos] > min_heap[leftChildPos]  || min_heap[replacedValuePos] > min_heap[rightChildPos]) )
        {
            int smallest = getSmallerValuePos(min_heap[leftChildPos],min_heap[rightChildPos],leftChildPos,rightChildPos);
            int child = min_heap[smallest];
            min_heap[smallest] = min_heap[replacedValuePos];
            min_heap[replacedValuePos] = child;
            replacedValuePos = smallest;
            leftChildPos = leftChild(replacedValuePos);
            rightChildPos = rightChild(replacedValuePos);
        }

    }
    return min_heap;
}

int main ()
{
    test();
    return 0;
}
