#include <stdio.h>
#include <stdlib.h>

#define TYPE int

typedef struct Node{
    TYPE value;
    Node * next;
}Node;

typedef struct LinkedList{
    Node* head;
}LinkedList;

void push_front(LinkedList* list, TYPE value);
void push_back(LinkedList* list, TYPE value);
size_t size(LinkedList * list);
void constructor(LinkedList * list);
void pop_back(LinkedList* list);
void pop_front(LinkedList* list);
Node* find(LinkedList* list, TYPE value);
void clear(LinkedList* list);
void insert(Node* after, TYPE value);
void list_view(LinkedList* list);
void remove(Node* after);


int main(){

}

Node* _allocator(TYPE value){
    Node* tmp = (Node*)malloc(sizeof(Node));
    if(!tmp){
        perror("_allocator error: ");
        return NULL;
    }
    tmp->value = value;
    return tmp;

}

void push_front(LinkedList* list, TYPE value){
    Node*tmp = _allocatvor(value);
    tmp->next = list->head;
    list->head = tmp;

}


void push_back(LinkedList* list, TYPE value){
    Node*newNode = _allocatvor(value);
    if(!list->head){
        list->head = newNode;
        return;
    }
     Node*tmp = list->head;
     while(tmp->next){
        tmp = tmp->next;
     }

     tmp->next = newNode;
}

size_t size(LinkedList * list){
    size_t count = 0;
    Node*tmp = list->head;
    while(tmp){
        ++count;
        tmp = tmp->next;
    }
    return count;
}

void constructor(LinkedList * list){
    list->head = NULL;
}

void pop_front(LinkedList* list){
    if(!list->head){
        return;
    }
    Node* tmp = list->head->next;
    free(list->head);
    list->head = tmp;
}

void pop_back(LinkedList* list){
    if(!list->head){
        return;
    }
    Node* prev = NULL;
    Node* tmp = list->head;
    if(!tmp->next){
        free(list->head);
        list->head = NULL;
    }
    while(tmp->next){
        prev = prev->next;
        tmp = tmp->next;
    }

    free(prev->next);
    prev->next = NULL;

}


Node* find(LinkedList* list, TYPE value){
    if(!list->head) return NULL;
    Node* tmp = list->head;
    while(tmp){
        if(tmp->value == value){
            return tmp;
        }

        tmp = tmp->next;
    }
    return NULL;
}

void clear(inkedList* list){
    Node* tmp = list->head;
    Node* clear;
    while(tmp){
        clear = tmp;
        tmp = tmp->next;
        free(clear);
    }

    list->head = NULL;
}

void insert(Node* after, TYPE value){
    Node* tmp = _allocator(value);
    tmp->next = after->next;
    after->next = tmp

}

void list_view(LinkedList* list){
    Node* tmp =. list->head;
    while(tmp){
        printf("(%d)->", tmp->value);
        tmp = tmp->next;
    }
}

void remove(Node* after){
    if(!after->next) return;

    Node*tmp = after->next;
    after->next = after->next->next;
    free(tmp);
}
