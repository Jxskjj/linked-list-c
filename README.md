# Doubly Linked List in C

A clean, educational implementation of a doubly linked list with a comprehensive API.

## Features
- Full doubly linked list implementation
- Clear error handling with enum results
- Wrapper structure with size caching
- Memory-safe operations
- Simple demo interface

## API Overview
```c
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
```

## Run
```bash
cmake -B build
./build/linkedlist 
```
