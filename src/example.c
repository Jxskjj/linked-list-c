#include "../inc/LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void clear_screen() 
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void wait_for_enter() 
{
    printf("\nPress Enter to continue...");
    while (getchar() != '\n');
    getchar();
}

int main() 
{
    int value, index;
    ListResult result;
    clear_screen();
    printf("=== Doubly Linked List ===\n");
    printf("Enter first element: ");
    if (scanf("%d", &value) != 1) 
    {
        printf("Invalid input\n");
        return 1;
    }
    while (getchar() != '\n');
    
    List* list = list_create_with_value(value);
    if (!list) 
    {
        printf("Failed to create list\n");
        return 1;
    }
    
    while (1) {
        clear_screen();
        
        printf("\nCurrent list: ");
        list_print(list);
        printf("(size: %zu)\n", list_size(list));
        
        printf("\n========== MENU ==========\n");
        printf("1) Push front\n");
        printf("2) Push back\n");
        printf("3) Insert at index\n");
        printf("4) Remove at index\n");
        printf("5) Get at index\n");
        printf("6) Clear list\n");
        printf("7) Exit\n");
        printf("==========================\n");
        printf("Choice: ");
        
        int choice;
        if (scanf("%d", &choice) != 1) 
        {
            printf("\nInvalid input\n");
            while (getchar() != '\n');
            wait_for_enter();
            continue;
        }
        
        printf("\n");
        
        switch (choice) 
        {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1)
                {
                    break;
                }
                result = list_push_front(list, value);
                printf("Result: %s\n", list_result_to_string(result));
                break;
                
            case 2:
                printf("Enter value: ");
                 if (scanf("%d", &value) != 1)
                {
                    break;
                }
                result = list_push_back(list, value);
                printf("Result: %s\n", list_result_to_string(result));
                break;
                
            case 3:
                printf("Enter index: ");
                 if (scanf("%d", &index) != 1)
                {
                    break;
                }
                printf("Enter value: ");
                 if (scanf("%d", &value) != 1)
                {
                    break;
                }
                result = list_insert_at(list, index, value);
                printf("Result: %s\n", list_result_to_string(result));
                break;
                
            case 4:
                printf("Enter index: ");
                if (scanf("%d", &index) != 1)
                {
                    break;
                }
                result = list_remove_at(list, index, &value);
                if (result == LIST_OK) 
                {
                    printf("Removed value: %d\n", value);
                } 
                else 
                {
                    printf("Result: %s\n", list_result_to_string(result));
                }
                break;
                
            case 5:
                printf("Enter index: ");
                if (scanf("%d", &index) != 1)
                {
                    break;
                }
                result = list_get_at(list, index, &value);
                if (result == LIST_OK) 
                {
                    printf("Value at %d: %d\n", index, value);
                } 
                else 
                {
                    printf("Result: %s\n", list_result_to_string(result));
                }
                break;
                
            case 6:
                list_clear(list);
                printf("List cleared\n");
                break;
                
            case 7:
                list_destroy(list);
                printf("Goodbye!\n");
                return 0;
                
            default:
                printf("Invalid choice\n");
        }
        
        wait_for_enter();
    }
    
    return 0;
}
