#include <iostream>

using namespace std;

void reHeapUp( int list[], int newNode)
{   
    int parent;
    if(newNode)
    {
        parent = (newNode-1)/2;

        if( list[newNode] > list[parent])
        {
            int hold;
            hold = list[newNode];
            list[newNode] = list[parent];
            list[parent] = hold;
        }
        reHeapUp(list, parent);
    }
}

void reHeapDown(int list[], int root, int last)
{
    int leftKey;
    int rightKey;
    int largerChild;
    int largerKey;

    if( root*2 + 1 <= last)
    {
        leftKey = list[root*2 + 1];

        if(root*2 + 2 <= last) rightKey= list[root*2 + 2];
        else rightKey = -1;
        
        if( leftKey > rightKey)
        {
            largerChild = leftKey;
            largerKey = root*2 + 1;
        }
        else
        {
            largerChild = rightKey;
            largerKey = root*2 + 2;
        }

        if (largerChild > list[root] )
        {
            int hold;
            hold = list[largerKey];
            list[largerKey] = list[root];
            list[root] = hold;

            reHeapDown(list, largerKey, last);
        }
    }
}

void heapSort(int list[], int last)
{
    int walker;
    int hold;

    for( walker=1 ; walker <= last ; walker++) reHeapUp(list , walker);

    int sorted=last;

    while(sorted > 0)
    {
        hold = list[sorted];
        list[sorted] = list[0];
        list[0] = hold;

        sorted--;
        reHeapDown(list, 0, sorted);
    }
}

int main()
{
    int size;
    cout << "Enter the size of the set :";
    cin >> size;

    int *list= new int[size];

    cout << "Insert Values of the Set :- " << endl;
    
    int i;

    for( i=0 ; i < size ; i++)
    {
        cin >> list[i];
    }

    heapSort( list , size-1);

    cout << "Sorted Set :-" << endl;

    for( i=0 ; i < size ; i++)
    {
        cout << list[i] << " ";
    }

    delete []list;
    return 0;
}