#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double compute_det(int **a, int n) {
  // implement this
  double total = 0;
  int new_n = n-1;

  if (n == 1) {
	  return (*a)[0];
  }

  for (int k=0; k<n; k++) {
	  int *new_arr = malloc(new_n*new_n*sizeof(int));
	  int count = 0;
	  for (int i=1; i<n; i++) {
		  for (int j=0; j<n; j++) {
			  if (k == j) {
				  continue;
			  }
			  new_arr[count] = (*a)[i*n+j];
			  count++;
		  }
	  }
	  if (k%2 == 0) {
		  total += (*a)[k]*compute_det(&new_arr, new_n);
	  }
	  else {
		  total += -1*(*a)[k]*compute_det(&new_arr, new_n);
	  }
	  free(new_arr);
  }

  return total;
}

/*
TEST: ./det < det.in
OUTPUT:
-105.00000
*/
int main(int argc, char **argv) {
  // implement this
  int n;
  scanf("%d", &n);
  int *arr = malloc((n*n)*sizeof(double));
  for (int i=0; i<n; i++) {
	  for (int j=0; j<n; j++) {
		  int item;
		  scanf("%d", &item);
		  arr[i*n+j] = item;
	  }
  }

  printf("%.5f", compute_det(&arr, n));

  return 0;
}
