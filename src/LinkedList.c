#include "../inc/LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

static Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node) {
        node->data = value;
        node->next = NULL;
        node->prev = NULL;
    }
    return node;
}

const char* list_result_to_string(ListResult result) {
    switch (result) {
        case LIST_OK: return "Success";
        case LIST_ERR_NULL: return "Null pointer error";
        case LIST_ERR_INDEX: return "Index out of bounds";
        case LIST_ERR_ALLOC: return "Memory allocation failed";
        case LIST_ERR_EMPTY: return "List is empty";
        default: return "Unknown error";
    }
}

List* list_create(void) {
    List* list = (List*)malloc(sizeof(List));
    if (list) {
        list->head = NULL;
        list->size = 0;
    }
    return list;
}

List* list_create_with_value(int value) {
    List* list = list_create();
    if (list) {
        list_push_front(list, value);
    }
    return list;
}

void list_destroy(List* list) {
    if (list) {
        list_clear(list);
        free(list);
    }
}

ListResult list_push_front(List* list, int value) {
    if (!list) return LIST_ERR_NULL;
    
    Node* new_node = create_node(value);
    if (!new_node) return LIST_ERR_ALLOC;
    
    new_node->next = list->head;
    if (list->head) {
        list->head->prev = new_node;
    }
    list->head = new_node;
    list->size++;
    
    return LIST_OK;
}

ListResult list_push_back(List* list, int value) {
    if (!list) return LIST_ERR_NULL;
    
    Node* new_node = create_node(value);
    if (!new_node) return LIST_ERR_ALLOC;
    
    if (!list->head) {
        list->head = new_node;
    } else {
        Node* current = list->head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
    
    list->size++;
    return LIST_OK;
}

ListResult list_insert_at(List* list, int index, int value) {
    if (!list) return LIST_ERR_NULL;
    if (index < 0 || index > list->size) return LIST_ERR_INDEX;
    
    if (index == 0) {
        return list_push_front(list, value);
    }
    
    if (index == list->size) {
        return list_push_back(list, value);
    }
    
    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    Node* new_node = create_node(value);
    if (!new_node) return LIST_ERR_ALLOC;
    
    new_node->next = current;
    new_node->prev = current->prev;
    current->prev->next = new_node;
    current->prev = new_node;
    
    list->size++;
    return LIST_OK;
}

ListResult list_remove_at(List* list, int index, int* out_value) {
    if (!list || !out_value) return LIST_ERR_NULL;
    if (list->size == 0) return LIST_ERR_EMPTY;
    if (index < 0 || index >= list->size) return LIST_ERR_INDEX;
    
    Node* to_remove = list->head;
    for (int i = 0; i < index; i++) {
        to_remove = to_remove->next;
    }
    
    *out_value = to_remove->data;
    
    if (to_remove->prev) {
        to_remove->prev->next = to_remove->next;
    } else {
        list->head = to_remove->next;
    }
    
    if (to_remove->next) {
        to_remove->next->prev = to_remove->prev;
    }
    
    free(to_remove);
    list->size--;
    
    return LIST_OK;
}

ListResult list_get_at(const List* list, int index, int* out_value) {
    if (!list || !out_value) return LIST_ERR_NULL;
    if (list->size == 0) return LIST_ERR_EMPTY;
    if (index < 0 || index >= list->size) return LIST_ERR_INDEX;
    
    const Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    *out_value = current->data;
    return LIST_OK;
}

size_t list_size(const List* list) {
    return list ? list->size : 0;
}

int list_is_empty(const List* list) {
    return list ? (list->size == 0) : 1;
}

void list_print(const List* list) {
    if (!list || !list->head) {
        printf("[empty]");
        return;
    }
    
    const Node* current = list->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
}

void list_clear(List* list) {
    if (!list) return;
    
    Node* current = list->head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    
    list->head = NULL;
    list->size = 0;
}
