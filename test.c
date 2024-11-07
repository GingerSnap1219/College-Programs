/* 
 * hw7-jacksonhoornaert.c
 * Author: Jackson Hoornaert
 * This program creates a linked list based on input from a data file,
 * allowing nodes to be added and deleted as specified.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *name;
    struct node *next;
};
typedef struct node LINK;

/* Function prototypes */
int LIST_SEARCH(char name[], LINK *head);
LINK *LIST_INSERT(char name[], LINK *head);
void LIST_DELETE(char name[], LINK **head);
void LIST_DISPLAY(LINK *head);
LINK *LIST_FREE(LINK *head);
int get_line(char **lineptr, size_t *n, FILE *stream);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("*******************************************\n");
        printf("* You must include a filename to load.    *\n");
        printf("*******************************************\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    LINK *head = NULL;
    char *line = NULL;
    size_t len = 0;
    
    while (get_line(&line, &len, file) != -1) {
        char *name = strtok(line, " \n");
        char *op_code = strtok(NULL, " \n");

        if (name && op_code) {
            if (*op_code == 'a') {
                head = LIST_INSERT(name, head);
            } else if (*op_code == 'd') {
                LIST_DELETE(name, &head);
            }
        }
    }

    free(line);
    fclose(file);

    printf("Linked list contents:\n");
    LIST_DISPLAY(head);

    head = LIST_FREE(head);
    return 0;
}

/* Custom get_line function for Windows compatibility */
int get_line(char **lineptr, size_t *n, FILE *stream) {
    size_t pos;
    int c;

    if (*lineptr == NULL || *n == 0) {
        *n = 128;  // Initial buffer size
        *lineptr = malloc(*n);
        if (*lineptr == NULL) return -1;
    }

    for (pos = 0; (c = fgetc(stream)) != EOF && c != '\n'; pos++) {
        if (pos + 1 >= *n) {
            *n *= 2;  // Double buffer size
            char *new_lineptr = realloc(*lineptr, *n);
            if (new_lineptr == NULL) return -1;
            *lineptr = new_lineptr;
        }
        (*lineptr)[pos] = c;
    }

    if (c == EOF && pos == 0) return -1;
    (*lineptr)[pos] = '\0';
    return pos;
}

/* Search function */
int LIST_SEARCH(char name[], LINK *head) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

/* Insert function */
LINK *LIST_INSERT(char name[], LINK *head) {
    if (LIST_SEARCH(name, head)) return head;

    LINK *new_node = malloc(sizeof(LINK));
    new_node->name = strdup(name);
    new_node->next = NULL;

    if (!head || strcmp(name, head->name) < 0) {
        new_node->next = head;
        return new_node;
    }

    LINK *current = head;
    while (current->next && strcmp(name, current->next->name) > 0) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    
    return head;
}

/* Delete function */
void LIST_DELETE(char name[], LINK **head) {
    if (!*head) return;

    if (strcmp((*head)->name, name) == 0) {
        LINK *temp = *head;
        *head = (*head)->next;
        free(temp->name);
        free(temp);
        return;
    }

    LINK *current = *head;
    while (current->next && strcmp(current->next->name, name) != 0) {
        current = current->next;
    }

    if (current->next) {
        LINK *temp = current->next;
        current->next = current->next->next;
        free(temp->name);
        free(temp);
    }
}

/* Display function */
void LIST_DISPLAY(LINK *head) {
    while (head) {
        printf("%s\n", head->name);
        head = head->next;
    }
}

/* Free function */
LINK *LIST_FREE(LINK *head) {
    while (head) {
        LINK *temp = head;
        head = head->next;
        free(temp->name);
        free(temp);
    }
    return NULL;
}
