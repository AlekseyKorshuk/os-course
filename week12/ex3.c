#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#define SHORTCUTS_SIZE 3


struct Node{
    int data;
    struct Node *next;
};

struct Shortcut{
    struct Node* data;
    char* message;
    char* description;
};

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int getByIndex(struct Node* head, int index){

    struct Node* current = head;

    int count = 0;
    while (current != NULL) {
        if (count == index)
            return (current->data);
        count++;
        current = current->next;
    }

    return -1;
}

void deleteNodeByValue(struct Node** head_ref, int key){
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;

    prev->next = temp->next;

    free(temp);
}

int getCount(struct Node* head){
    int count = 0;
    struct Node* current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int checkIfExist(struct Node* head_ref, int key){
    struct Node* current = head_ref;
    while (current != NULL) {
        if (current->data == key){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void check(struct Node* head, struct Shortcut shortcuts[], int size){
    int count = getCount(head);
    for(int i = 0; i < size; i++){
        int shortcut_count = getCount(shortcuts[i].data);
        if (count == shortcut_count){
            int flag = 0;
            for(int j = 0; j < shortcut_count; j++){
                if (getByIndex(head, j) != getByIndex(shortcuts[i].data, j)){
                    flag = 1;
                    break;
                }
            }
            if (flag == 0){
                fprintf(stderr, "%s\n", shortcuts[i].message);
            }

        }
    }
}


int main(){
    struct Shortcut shortcuts[SHORTCUTS_SIZE];

    fprintf(stderr, "List of shortcuts:\n");

    shortcuts[0].message = "I passed the Exam!";
    shortcuts[0].description = "P+E";
    shortcuts[0].data = NULL;
    push(&shortcuts[0].data, KEY_P);
    push(&shortcuts[0].data, KEY_E);

    shortcuts[1].message = "Get some cappuccino!";
    shortcuts[1].description = "C+A+P";
    shortcuts[1].data = NULL;
    push(&shortcuts[1].data, KEY_C);
    push(&shortcuts[1].data, KEY_A);
    push(&shortcuts[1].data, KEY_P);

    shortcuts[2].message = "I am sad that I get C for OS Lab :(";
    shortcuts[2].description = "S+A+D";
    shortcuts[2].data = NULL;
    push(&shortcuts[2].data, KEY_S);
    push(&shortcuts[2].data, KEY_A);
    push(&shortcuts[2].data, KEY_D);

    for(int i = 0; i < SHORTCUTS_SIZE; i++)
        fprintf(stderr, "%s -> %s\n", shortcuts[i].message, shortcuts[i].description);

    /* Start with the empty list */
    struct Node* head = NULL;

    char* dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int fd = open(dev, O_RDONLY);
    if (fd < 0) {
        perror("error");
        return 1;
    }
    struct input_event evt;
    // Remove Enter while starting the program
    read(fd, &evt, sizeof(struct input_event));
    read(fd, &evt, sizeof(struct input_event));

    printf("Press Q to exit!\n");
    int counter = 0;
    while(1) {
        read(fd, &evt, sizeof(struct input_event));
        if(evt.type != 4 && evt.code != EV_SYN) {

            if (evt.value == 0){
                deleteNodeByValue(&head, evt.code);
            }
            if (evt.value == 1){
                push(&head, evt.code);
            }
            check(head, shortcuts, SHORTCUTS_SIZE);
            if (evt.code == 16)
                return 0;
        }
    }

    return 0;
}
