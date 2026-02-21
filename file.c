#include <stdio.h>
#include <stdlib.h>

#define TYPE int

typedef struct Node {
    TYPE value;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

void constructor(LinkedList* list);
Node* _allocator(TYPE value);

void push_front(LinkedList* list, TYPE value);
void push_back(LinkedList* list, TYPE value);

void pop_front(LinkedList* list);
void pop_back(LinkedList* list);

size_t size(LinkedList* list);
Node* find(LinkedList* list, TYPE value);

void insert(Node* after, TYPE value);
void remove_node(Node* after);

void clear(LinkedList* list);
void list_view(LinkedList* list);

int main() {
    return 0;
}

void constructor(LinkedList* list) {
    list->head = NULL;
}

Node* _allocator(TYPE value) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    if (!tmp) {
        perror("Allocation error");
        exit(EXIT_FAILURE);
    }
    tmp->value = value;
    tmp->next = NULL;
    return tmp;
}

void push_front(LinkedList* list, TYPE value) {
    Node* tmp = _allocator(value);
    tmp->next = list->head;
    list->head = tmp;
}

void push_back(LinkedList* list, TYPE value) {
    Node* newNode = _allocator(value);

    if (!list->head) {
        list->head = newNode;
        return;
    }

    Node* tmp = list->head;
    while (tmp->next) {
        tmp = tmp->next;
    }

    tmp->next = newNode;
}

void pop_front(LinkedList* list) {
    if (!list->head)
        return;

    Node* tmp = list->head;
    list->head = tmp->next;
    free(tmp);
}

void pop_back(LinkedList* list) {
    if (!list->head)
        return;

    if (!list->head->next) {
        free(list->head);
        list->head = NULL;
        return;
    }

    Node* prev = NULL;
    Node* tmp = list->head;

    while (tmp->next) {
        prev = tmp;
        tmp = tmp->next;
    }

    free(tmp);
    prev->next = NULL;
}

size_t size(LinkedList* list) {
    size_t count = 0;
    Node* tmp = list->head;

    while (tmp) {
        count++;
        tmp = tmp->next;
    }

    return count;
}

Node* find(LinkedList* list, TYPE value) {
    Node* tmp = list->head;

    while (tmp) {
        if (tmp->value == value)
            return tmp;
        tmp = tmp->next;
    }

    return NULL;
}

void insert(Node* after, TYPE value) {
    if (!after)
        return;

    Node* tmp = _allocator(value);
    tmp->next = after->next;
    after->next = tmp;
}

void remove_node(Node* after) {
    if (!after || !after->next)
        return;

    Node* tmp = after->next;
    after->next = tmp->next;
    free(tmp);
}

void clear(LinkedList* list) {
    Node* tmp = list->head;

    while (tmp) {
        Node* to_free = tmp;
        tmp = tmp->next;
        free(to_free);
    }

    list->head = NULL;
}

void list_view(LinkedList* list) {
    Node* tmp = list->head;

    while (tmp) {
        printf("(%d)->", tmp->value);
        tmp = tmp->next;
    }
    printf("NULL\n");
}
