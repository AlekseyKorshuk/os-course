/* OS Lab 3
*  Exercise 3
*
*  @author  Aliaksei Korshuk
*  @version 1.0
*  @since   2021-02-09
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Node structure
 */
struct node{
    int data;
    struct node* next;
};

/**
 * Method that prints out the value of each element
 * @param head Head og the LinkedList
 * @param size Size of the LinkedList
 */
void print_list(struct node *head, int *size){
    if (*size == 0) return;

    struct node *current = head;
    for (int i = 0; i < *size; i++){
        printf("%d ", current->data);
        if (current->next != NULL) current = current->next;
    }
    printf("\n");
}

/**
 * Method that inserts a new element after some existing element
 * @param head Head og the LinkedList
 * @param size Size of the LinkedList
 */
void insert_node(struct node *head, int* size, int data){
    if (*size == 0){
        (*size)++;
        head->data = data;
        return;
    }

    struct node *current = head;
    for (int i = 1; i < *size; i++){
        current = current->next;
    }
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    current->next = temp;
    (*size)++;

}

/**
 * Method that deletes a certain element
 * @param head Head og the LinkedList
 * @param size Size of the LinkedList
 */
void delete_node(struct node *head, int* size, int data){
    int index = 0;

    if (head->data == data){
        struct node *current = head;
        *head = *current->next;
    }
    else{
        index = 0;
        struct node *current = head;

        for (int i = 1; i < index - 1; i++){
            if (current->next->data == data) break;
            current = current->next;
            index++;
        }
        if (*size-1 == index){
            current->next = NULL;
        }
        else{
            current->next = current->next->next;
        }
    }
    (*size)--;

}


int main() {
    int* size = malloc(sizeof(int));
    *size = 0;
    struct node *head = malloc(sizeof(struct node));
    head->data = 0;
    head->next = NULL;

    for (int i = 0; i < 10; i++){
        insert_node(head, size, i);
    }
    print_list(head, size);

    for (int i = *size - 3; i >= 1; i--){
        delete_node(head, size, i);
    }
    print_list(head, size);

    delete_node(head, size, 0);
    print_list(head, size);

    delete_node(head, size, 9);
    print_list(head, size);

    insert_node(head, size, 9);
    print_list(head, size);
    return 0;
}
