#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "MaxHeap.h"

#define MAX_SKYLINEPOINT_NUM 10000

typedef struct skyLinePoint {
    int x;
    int y;

    char type;  /* 's' for "start", 'e' for "end" */

} SkyLinePoint;

static int cmp_skyLine_point(const void *p1, const void *p2)
{
    SkyLinePoint * point1 = (SkyLinePoint*)p1;
    SkyLinePoint * point2 = (SkyLinePoint*)p2;

    if ( point1->x < point2->x )
    {
        return -1;
    }
    if ( point1->x > point2->x )
    {
        return 1;
    }

    if ( point1->type == 's' && point2->type == 'e' )
    {
        return -1;
    }

    if ( point1->type == 'e' && point2->type == 's' )
    {
        return 1;
    }
    
    if ( point1->type == 's' && point2->type == 's' )
    {
        if ( point1->y > point2->y )
        {
            return -1;
        }
        
        if ( point1->y < point2->y )
        {
            return 1;
        }
    }
    
    if ( point1->type == 'e' && point2->type == 'e' )
    {
        if ( point1->y > point2->y )
        {
            return 1;
        }
        
        if ( point1->y < point2->y )
        {
            return -1;
        }
    }
    
    return 0;
}

static void sort_skyLine_points(SkyLinePoint *ps, int ps_num)
{
    qsort(ps, ps_num, sizeof(SkyLinePoint), cmp_skyLine_point);
}

int main()
{
    SkyLinePoint ps[MAX_SKYLINEPOINT_NUM];

    int x1, height, x2;
    int ps_num = 0;
    while(scanf("%d%d%d", &x1, &height, &x2) != EOF)
    {
        ps[ps_num].x = x1; 
        ps[ps_num].y = height;
        ps[ps_num].type = 's'; //start
        ps_num ++;
        ps[ps_num].x = x2; 
        ps[ps_num].y = height;
        ps[ps_num].type = 'e'; //end
        ps_num ++;
    }

    sort_skyLine_points(ps, ps_num);

    MaxHeap * heap = createMaxHeap(MAX_SKYLINEPOINT_NUM);
    
    insert_to_MaxHeap(heap, 0);
    insert_to_MaxHeap(heap, ps[0].y);
    printf("%d %d", ps[0].x, ps[0].y);    
    
    for (int i = 1; i < ps_num; i++)
    {
        int key_before = get_MaxHeap(heap);
        
        if (ps[i].type == 's')
        {
            insert_to_MaxHeap(heap, ps[i].y);
            if (check_heap(heap, 1) == 0)
            {
                printf("The heap is invalid after insert_to_MaxHeap with %d\n", ps[i].y);
                exit(0);
            }
        }
        else if (ps[i].type == 'e')
        {
            int res = MaxHeap_delete_key(heap, 1, ps[i].y);
            if (check_heap(heap, 1) == 0)
            {
                printf("\nThe heap is invalid after MaxHeap_delete_key with %d\n", ps[i].y);
                printf("The delete result is %d\n", res);
                exit(0);
            }
        }
        
        int key_after = get_MaxHeap(heap);
        
        if (key_after != key_before)
        {
            printf(" %d %d", ps[i].x, key_after);
        }
    }
    
    printf("\n");
    
    deleteMaxHeap(heap);
        
    return 0;
}

