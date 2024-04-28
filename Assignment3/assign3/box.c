/* Name: Alexander Ogay
 * ID: 6380727
 */
#include <stdio.h>
#include <stdlib.h>
#include "box.h"

void createBox(Box **b, int init_cap) {
    // IMPLEMENT
    if (*b != NULL)
	    return;
    Box *new_box = malloc(sizeof(Box));
    new_box->data = malloc(init_cap * sizeof(int));
    new_box->size = 0;
    new_box->cap = init_cap;
    *b = new_box;
    return;
}

void insert(Box *b, int elem) {
    // IMPLEMENT
    if (b->size != b->cap) {
	    b->data[b->size] = elem;
	    b->size++;
    }
    else {
	    b->data = realloc(b->data, (b->size*2) * sizeof(int));
	    b->cap = b->size*2;
	    insert(b, elem);
    }
    return;
}

void removeAll(Box *b, int elem) {
    // IMPLEMENT
    int *newData = malloc(b->cap*sizeof(int));
    int count = 0;
    int run = b->size;
    for (int i=0; i<run; i++) {
	    if (b->data[i] != elem) {
		    newData[count] = b->data[i];
		    count++;
	    }
	    else
		    b->size += -1;
    }
    b->data = newData;
    return;
}

void printBox(Box *b) {
    // IMPLEMENT
    for (int i=0; i<b->size; i++) {
	    printf("%d\n", b->data[i]);
    }
    return;
}

double getMean(Box *b) {
    // IMPLEMENT
    double ans = 0;
    for (int i=0; i<b->size; i++) {
	    ans += b->data[i];
    }
    return ans/b->size;
}

void dealloc(Box **b) {
    // IMPLEMENT
    free((*b)->data);
    free((*b));
    return;
}

/*
TEST: ./box < test.in
OUTPUT:
AVG = 4.00
box1 size = 10
box2 size = 1
box1 cap = 16
box2 cap = 2
-- b1
11
2
3
4
5
2
3
2
2
6
-- b2
2
--
-- b1 (after remove)
11
3
4
5
3
6
--
-- b2 (after remove)
--
*/
int main(int argc, char **argv)
{
    Box *b1 = NULL;
    Box *b2 = NULL;

    createBox(&b1, 1);
    createBox(&b2, 2);

    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int tmp;
        scanf("%d",&tmp);
        insert(b1, tmp);
    }
    insert(b2, 2);

    printf("AVG = %0.2f\n",getMean(b1));
    printf("box1 size = %d\n",b1->size);
    printf("box2 size = %d\n",b2->size);
    printf("box1 cap = %d\n",b1->cap);
    printf("box2 cap = %d\n",b2->cap);

    printf("-- b1\n");
    printBox(b1);
    printf("-- b2\n");
    printBox(b2);
    printf("--\n");

    removeAll(b1, 2);
    printf("-- b1 (after remove)\n");
    printBox(b1);
    printf("--\n");
    removeAll(b2, 2);
    printf("-- b2 (after remove)\n");
    printBox(b2);
    printf("--\n");

    dealloc(&b1);
    dealloc(&b2);
}
