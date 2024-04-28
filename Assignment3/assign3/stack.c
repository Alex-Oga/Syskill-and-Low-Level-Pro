/* Name: Alexander Ogay
 * ID: 6380727
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "stack.h"

// Following the assigment 3 pdf output, instead of the output described here. top to bottom instead of bottom to top

void push(Stack **q, char *word) {
    // IMPLEMENT
    if (*q == NULL) {
	    Stack *new_stack = malloc(sizeof(Stack));
	    new_stack->head = malloc(sizeof(Node));
	    new_stack->head->next = NULL;
	    new_stack->head->data = word;
	    (*q) = new_stack;
	    return;
    }
    Node* new_node = malloc(sizeof(Node));
    new_node->data = word;
    new_node->next = (*q)->head;
    (*q)->head = new_node;
}

char *pop(Stack *q) {
    // IMPLEMENT
    if (q == NULL || q->head == NULL) {
	    return NULL;
    }
    char* str = q->head->data;
    q->head = q->head->next;
    return str;
}

void print(Stack *q) {
    // IMPLEMENT
    if (q == NULL || q->head == NULL) {
	    printf("No items\n");
	    return;
    }
    Node *temp = q->head;
    while (temp != NULL) {
	    printf("%s\n", temp->data);
	    temp = temp->next;
    }
    return;
}

int isEmpty(Stack *q) {
    // IMPLEMENT
    if (q == NULL || q->head == NULL) {
	    return 0;
    }
    return 1;
}

void delete(Stack **q) {
    // IMPLEMENT
    Node *temp = (*q)->head;
    while (temp != NULL) {
	    Node *prev = temp;
	    temp = temp->next;
	    free(prev);
    }
    free(temp);
    (*q) = NULL;
}

/***** Expected output: *****
No items
a
b
c
a
b
c
d
e
f
No items
s = World
t = Hello
*****************************/
int main(int argc, char **argv)
{
    Stack *q = NULL;

    // print the queue
    print(q);

    // push items
    push(&q, "a");
    push(&q, "b");
    push(&q, "c");
    print(q);

    // pop items
    while (isEmpty(q) != 0) {
        char *item = pop(q);
        printf("%s\n", item);
    }

    char *item = pop(q);
    assert(item == NULL);

    // push again
    push(&q, "d");
    push(&q, "e");
    push(&q, "f");
    print(q);

    // destroy the queue
    delete(&q);

    // print again
    print(q);

    // check copy
    char *s = (char *)malloc(10);
    strcpy(s, "Hello");
    push(&q, s);
    strcpy(s, "World");
    char *t = pop(q);
    printf("s = %s\n", s);
    printf("t = %s\n", t);
    free(t);
    free(s);

    // free the queue
    free(q);
}
