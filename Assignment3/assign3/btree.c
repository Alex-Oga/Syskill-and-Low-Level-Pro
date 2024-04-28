/* Name: Alexander Ogay
 * ID: 6380727
 */
#include <stdlib.h>
#include <stdio.h>
#include "btree.h"

void insert(Node **tree, int val) {
    // IMPLEMENT
    Node *temp = malloc(sizeof(Node));
    temp->data = val;
    temp->right = NULL;
    temp->left = NULL;
    if ((*tree) == NULL) {
	    (*tree) = temp;
	    return;
    }
    if (val < (*tree)->data) {
	    insert(&(*tree)->left, val);
    }
    else {
	    insert(&(*tree)->right, val);
    }
    return;
}

void printTwo(Node *tree, int current) {
	if (tree != NULL) {
		for (int i=0; i<current; i++) {
			printf(" ");
		}
		printf("|-%d\n", tree->data);
		printTwo(tree->left, current+2);
		printTwo(tree->right, current+2);
	}
	return;
}

void print(Node *tree) {
    // IMPLEMENT
    int current = 0;
    if (tree != NULL) {
	    printf("%d\n", tree->data);
	    printTwo(tree->left, current);
	    printTwo(tree->right, current);
    }
    return;
}

void del(Node *tree) {
	if (tree->left != NULL) {
		del(tree->left);
	}
	if (tree->right != NULL) {
		del(tree->right);
	}
	free(tree);
	return;
}

void delete(Node *tree) {
    // IMPLEMENT
    if (tree->left != NULL) {
	    del(tree->left);
    }
    if (tree->right != NULL) {
    	    del(tree->right);
    }
    tree->left = NULL;
    tree->right = NULL;
    return;
}

Node *lookup(Node ** tree, int val) {
    // IMPLEMENT
    if ((*tree) == NULL) {
	    return NULL;
    }
    if ((*tree)->data == val) {
	    return (*tree);
    }
    if ((*tree)->data < val) {
	    return lookup(&(*tree)->right, val);
    }
    else {
	    return lookup(&(*tree)->left, val);
    }
}


/***** Expected output: *****
7
|-2
  |-1
  |-4
|-10
  |-15
    |-12
      |-11
Found
Not Found
 *****************************/
int main(int argc, char **argv)
{
    Node *root = NULL;
    Node *target = NULL;

    // add nodes
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 10);
    insert(&root, 1);
    insert(&root, 15);
    insert(&root, 12);
    insert(&root, 11);

    // Lets see how the tree looks
    print(root);

    // Check if 4 in the tree
    target = lookup(&root, 4);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    // Check if 44 in the tree
    target = lookup(&root, 44);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    // Now let's free up the space
    delete(root);
}
