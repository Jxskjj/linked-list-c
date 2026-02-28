#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

/**
 * @brief Return codes for list operations
 */
typedef enum 
{
    LIST_OK = 0,        /**< Operation completed successfully */
    LIST_ERR_NULL,       /**< NULL pointer passed to function */
    LIST_ERR_INDEX,      /**< Index out of bounds */
    LIST_ERR_ALLOC,      /**< Memory allocation failed */
    LIST_ERR_EMPTY       /**< List is empty */
} ListResult;

/**
 * @brief Node structure for doubly linked list
 */
typedef struct Node 
{
    int data;           /**< Node value */
    struct Node* next;  /**< Pointer to next node (NULL if last) */
    struct Node* prev;  /**< Pointer to previous node (NULL if first) */
} Node;

/**
 * @brief Main list structure
 */
typedef struct 
{
    Node* head;   /**< Pointer to first element (NULL if empty) */
    size_t size;  /**< Number of elements in list */
} List;

/**
 * @brief Creates a new empty list
 * @return Pointer to created list or NULL if allocation fails
 */
List* list_create(void);

/**
 * @brief Creates a new list with one element
 * @param value Value for the first element
 * @return Pointer to created list or NULL if allocation fails
 */
List* list_create_with_value(int value);

/**
 * @brief Destroys list and frees all memory
 * @param list Pointer to list (if NULL, function does nothing)
 */
void list_destroy(List* list);

/**
 * @brief Adds element to the beginning of the list
 * @param list Pointer to list (must not be NULL)
 * @param value Value to add
 * @return Result code:
 *         - LIST_OK: success
 *         - LIST_ERR_NULL: list is NULL
 *         - LIST_ERR_ALLOC: memory allocation failed
 */
ListResult list_push_front(List* list, int value);

/**
 * @brief Adds element to the end of the list
 * @param list Pointer to list (must not be NULL)
 * @param value Value to add
 * @return Result code:
 *         - LIST_OK: success
 *         - LIST_ERR_NULL: list is NULL
 *         - LIST_ERR_ALLOC: memory allocation failed
 */
ListResult list_push_back(List* list, int value);

/**
 * @brief Inserts element at specified index
 * @param list Pointer to list (must not be NULL)
 * @param index Position to insert (0 to size)
 * @param value Value to insert
 * @return Result code:
 *         - LIST_OK: success
 *         - LIST_ERR_NULL: list is NULL
 *         - LIST_ERR_INDEX: index out of bounds
 *         - LIST_ERR_ALLOC: memory allocation failed
 */
ListResult list_insert_at(List* list, int index, int value);

/**
 * @brief Removes element at specified index
 * @param list Pointer to list (must not be NULL)
 * @param index Index of element to remove (0 to size-1)
 * @param out_value Pointer to store removed value (must not be NULL)
 * @return Result code:
 *         - LIST_OK: success
 *         - LIST_ERR_NULL: list or out_value is NULL
 *         - LIST_ERR_EMPTY: list is empty
 *         - LIST_ERR_INDEX: index out of bounds
 */
ListResult list_remove_at(List* list, int index, int* out_value);

/**
 * @brief Gets element value at specified index without removing
 * @param list Pointer to list (must not be NULL)
 * @param index Index of element (0 to size-1)
 * @param out_value Pointer to store value (must not be NULL)
 * @return Result code:
 *         - LIST_OK: success
 *         - LIST_ERR_NULL: list or out_value is NULL
 *         - LIST_ERR_EMPTY: list is empty
 *         - LIST_ERR_INDEX: index out of bounds
 */
ListResult list_get_at(const List* list, int index, int* out_value);

/**
 * @brief Returns current number of elements in list
 * @param list Pointer to list (can be NULL)
 * @return Number of elements (0 if list is NULL)
 */
size_t list_size(const List* list);

/**
 * @brief Checks if list is empty
 * @param list Pointer to list (can be NULL)
 * @return 1 if empty or NULL, 0 otherwise
 */
int list_is_empty(const List* list);

/**
 * @brief Prints list contents to stdout
 * @param list Pointer to list (prints "[empty]" if NULL or empty)
 */
void list_print(const List* list);

/**
 * @brief Removes all elements from list
 * @param list Pointer to list (if NULL, function does nothing)
 */
void list_clear(List* list);

/**
 * @brief Converts result code to readable string
 * @param result Result code from ListResult enum
 * @return String description of the result
 */
const char* list_result_to_string(ListResult result);

#endif 
