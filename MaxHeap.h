#ifndef MAX_HEAP
#define MAX_HEAP

#define exchange_element( x, y ) \
{\
    int tmp = (x);\
    (x) = (y);\
    (y) = tmp;\
}

typedef struct {
    int *A;
    int len;
    int size;
} MaxHeap;

MaxHeap * createMaxHeap(int len);
void deleteMaxHeap(MaxHeap * h);
void insert_to_MaxHeap(MaxHeap * h, int value);
int pop_MaxHeap(MaxHeap * h);
int get_MaxHeap(MaxHeap * h);
void MaxHeapify_upward(MaxHeap * h, int i);
void MaxHeapify_downward(MaxHeap * h, int i);
void MaxHeap_increase_key(MaxHeap * h, int i, int key);
int MaxHeap_delete_key(MaxHeap * h, int root_index, int key); /* Return 1 if success; 0 otherwise */
int check_heap(MaxHeap* h, int i);

#endif
