/* Name: Alexander Ogay
 * ID: 6380727
 */
#include <stdio.h>
#include <stdlib.h>
#include "bubblesort.h"


int compare(const Entry *a, const Entry *b){
    // IMPLEMENT
    return a->data-b->data;
}

void sort(Entry *in, int nL, void *comparator){
	//IMPLEMENT
	int swap = 1;
	while (swap == 1) {
		swap = 0;
		for (int i=0; i<nL-1; i++) {
			Entry *const ptr1 = (in+i);
			Entry *const ptr2 = (in+i+1);
			if (compare(ptr1, ptr2) > 0) {
				swap = 1;
				int one = (in+i)->data;
				char* two = (in+i)->name;
				(in+i)->data = (in+i+1)->data;
				(in+i)->name = (in+i+1)->name;
				(in+i+1)->data = one;
				(in+i+1)->name = two;
			}
		}
	}
}



/*
TEST: ./bubblesort < test.in
OUTPUT:
1 lsdfjl
2 ghijk
3 ksdljf
5 abc
6 def
*/
int main(int argc, char **argv) {
    // IMPLEMENT
    int n;
    scanf("%d", &n);
    Entry *a = malloc(sizeof(Entry)*n);
    for (int i=0; i<n; i++) {
	    (a+i)->name = (char*)malloc(sizeof(char)*30);
	    scanf("%d %s", &(a+i)->data, (a+i)->name);
    }
    sort(a, n, compare);
    for (int i=0; i<n; i++) {
	    printf("%d %s\n", (a+i)->data, (a+i)->name);
    }
    free(a);
    return 0;
}
