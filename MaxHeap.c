#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "MaxHeap.h"

MaxHeap * createMaxHeap(int len)
{
    MaxHeap * h = (MaxHeap*)malloc(sizeof(MaxHeap));
    h->len = len;
    h->A = (int*)malloc(sizeof(int) * (len+1));
    h->size = 0;
    return h;
}

void deleteMaxHeap(MaxHeap * h)
{
    if(h == NULL)
    {
        printf("Some logical errors : free a null MaxHeap\n");
        return;
    }

    free(h->A);
    free(h);
}

void insert_to_MaxHeap(MaxHeap * h, int key)
{
    if(h == NULL)
    {
        printf("Some logical errors : insert to a null MaxHeap.\n");
        return;
    }

    if( h->size == h->len )
    {
        printf("The MaxHeap is full.\n");
        return;
    }

    int *A = h->A;

    h->size++;
    A[h->size] = INT_MIN;
    MaxHeap_increase_key(h, h->size, key);
}

int pop_MaxHeap(MaxHeap * h)
{
    if(h == NULL)
    {
        printf("Some logical errors : extract a null MaxHeap.\n");
        return INT_MIN;
    }
    
    if(h->size == 0)
    {
        printf("Some logical errors : extract a MaxHeap with zero size.\n");
        return INT_MIN;
    }

    int *A = h->A;

    int max = A[1];
    
    A[1] = A[h->size];
    h->size--;
    MaxHeapify_downward(h, 1);

    return max;
}

int get_MaxHeap(MaxHeap * h)
{
    if(h == NULL)
    {
        printf("Some logical errors : try to get max key from a null MaxHeap.\n");
        return INT_MIN;
    }
    
    if(h->size == 0)
    {
        printf("Some logical errors : try to get max key from a MaxHeap with zero size.\n");
        return INT_MIN;
    }

    return h->A[1];
}

void MaxHeap_increase_key(MaxHeap * h, int i, int key)
{
    if(h == NULL)
    {
        printf("Some logical errors : MaxHeap_increase_key with a null MaxHeap.\n");
        return;
    }

    if ( i <= 0 || i > h->size)
    {
        printf("Some logical errors : MaxHeap_increase_key with an invalid key.\n");
        return;
    }

    int *A = h->A;

    if ( key < A[i] )
    {
        printf("Some logical errors : new key is smaller than current key.\n");
        return;
    }

    A[i] = key;
    
    MaxHeapify_upward(h, i);
}

void MaxHeapify_upward(MaxHeap * h, int i)
{
    if(h == NULL)
    {
        printf("Some logical errors : MaxHeapify a null MaxHeap.\n");
        return;
    }

    int *A = h->A;
    
    while ( i > 1 && A[i>>1] < A[i] )
    {
        exchange_element( A[i], A[i>>1] );
        i = i >> 1;
    }
}

void MaxHeapify_downward(MaxHeap * h, int i)
{
    if(h == NULL)
    {
        printf("Some logical errors : MaxHeapify a null MaxHeap.\n");
        return;
    }

    int *A = h->A;

    int left_child = i << 1;
    int right_child = left_child + 1;
    int largest = i;

    if (left_child <= h->size && A[left_child] > A[i])
    {
        largest = left_child;
    }

    if (right_child <= h->size && A[right_child] > A[largest])
    {
        largest = right_child;
    }

    if (largest != i)
    {
        exchange_element(A[i], A[largest]);
        MaxHeapify_downward(h, largest);
    }
}

int MaxHeap_delete_key(MaxHeap * h, int root_index, int key)
{
    if(h == NULL)
    {
        printf("Some logical errors : try to delete key from a null MaxHeap.\n");
        return INT_MIN;
    }
    
    if(h->size == 0)
    {
        printf("Some logical errors : try to delete key from a MaxHeap with zero size.\n");
        return INT_MIN;
    }
    
    int *A = h->A;
    
    if (A[root_index] == key)
    {
        A[root_index] = A[h->size];
        h->size--;
        MaxHeapify_upward(h, root_index);
        MaxHeapify_downward(h, root_index);
        return 1;
    }
    
    if (A[root_index] < key)
    {
        return 0;
    }
    
    int left_child = root_index << 1;
    int right_child = left_child + 1;
    
    if (left_child <= h->size && MaxHeap_delete_key(h, left_child, key))
    {
        return 1;
    }
    
    if (right_child <= h->size && MaxHeap_delete_key(h, right_child, key))
    {
        return 1;
    }
    
    return 0;
}

int check_heap(MaxHeap* h, int i)
{
    int *A = h->A;
    int left_child = i << 1;
    int right_child = left_child + 1;
    
    if (left_child <= h->size)
    {
        if (A[left_child] > A[i])
        {
            printf("\nFail. A[left_child] == %d, A[i] == %d\n", A[left_child], A[i]);
            return 0;
        }
        if (check_heap(h, left_child) == 0)
        {
            return 0;
        }
    }
    
    if (right_child <= h->size)
    {
        if (A[right_child] > A[i])
        {
            printf("\nFail. A[right_child] == %d, A[i] == %d\n", A[right_child], A[i]);
            return 0;
        }
        if (check_heap(h, right_child) == 0)
        {
            return 0;
        }
    }
    
    return 1;
}
