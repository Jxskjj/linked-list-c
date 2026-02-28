#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef enum {
    LIST_OK = 0,
    LIST_ERR_NULL,
    LIST_ERR_INDEX,
    LIST_ERR_ALLOC,
    LIST_ERR_EMPTY
} ListResult;

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    size_t size;
} List;

List* list_create(void);
List* list_create_with_value(int value);
void list_destroy(List* list);

ListResult list_push_front(List* list, int value);
ListResult list_push_back(List* list, int value);
ListResult list_insert_at(List* list, int index, int value);
ListResult list_remove_at(List* list, int index, int* out_value);
ListResult list_get_at(const List* list, int index, int* out_value);

size_t list_size(const List* list);
int list_is_empty(const List* list);
void list_print(const List* list);
void list_clear(List* list);

const char* list_result_to_string(ListResult result);

#endif
