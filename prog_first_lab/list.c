#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void insertItem(struct Item* head, int insertItem, int index) {
    if (head == NULL) {
        printf("Ошибка: передан NULL-указатель в insertItem\n");
        return;
    }
    if (index < 1 || index > len(head)){
        printf("Ошибка: недопустимый индекс для вставки элемента в список\n");
        return;
    }
    int counter = 0;
    struct Item* pointer = head;
    struct Item* prev = head;
    struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
    newItem -> value = insertItem;
    if (index == 1) {
        pointer = pointer -> next;
        prev -> next = newItem;
        newItem -> next = pointer;
        return;
    }
    while (counter < index) {
        prev = pointer;
        pointer = pointer -> next; 
        counter++;
    }
    prev -> next = newItem;
    newItem -> next = pointer;
    return;
}

void appendItem(struct Item* head, int toAppend) {
    if (head == NULL) {
        printf("Ошибка: передан NULL-указатель в insertItem\n");
        return;
    }
    struct Item* pointer = head;
    struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
    newItem -> value = toAppend;
    while (pointer -> next != NULL) { 
        pointer = pointer -> next;
    }
    pointer -> next = newItem;
    newItem -> next = NULL;
}


void deleteItem(struct Item* head, int index) {
    if (head == NULL) {
        printf("Ошибка: передан NULL-указатель в insertItem\n");
        return;
    }
    if (index < 1 || index > len(head)) {
        printf("Ошибка: индекс %d вне допустимого диапазона [1, %d]\n", index, len(head));
        return;
    }

    struct Item* prev = head;
    struct Item* toDelete = head->next;

    for (int i = 1; i < index; i++) {
        prev = toDelete;
        toDelete = toDelete->next;
    }

    prev->next = toDelete->next;
    free(toDelete);
}

void popItem(struct Item* head) {
    if (head == NULL) {
        printf("Ошибка: передан NULL-указатель в insertItem\n");
        return;
    }
    if (head->next == NULL) {
        printf("Ошибка: список пуст\n");
        return;
    }
    struct Item* pointer = head;
    struct Item* prev = head;
    while (pointer -> next != NULL) {
            prev = pointer;
            pointer = pointer -> next; 
        }
    prev -> next = NULL;
    free(pointer);
    return;
}

void getData(const struct Item* head, int index) {
    if (head == NULL) {
        printf("Ошибка: передан NULL-указатель в insertItem\n");
        return;
    }
    struct Item* pointer = head;
    int counter = 0;
    if (index == 1) {
        printf("%d\n", head -> next -> value);
        return;
    }
    if (index < 1 || index > len(head)) {
        printf("Ошибка: передан индес за переделами списка\n");
        return;
    }
    while(counter < index) {
        pointer = pointer -> next;
        counter++;
    }
    printf("%d\n", pointer -> value);
    return;
    
}

void getAddress(const struct Item* head, int index) {
    if (head == NULL) {
        printf("Ошибка: передан NULL-указатель в insertItem\n");
        return;
    }
    struct Item* pointer = head;
    int counter = 0;
    if (index == 1) {
        printf("%p\n", head -> next);
        return;
    }
    while(counter < index - 1) {
        pointer = pointer -> next;
        counter++;
    }
    printf("%p\n", pointer -> next);
    return;
}

int len(const struct Item* head) {
    if (head == NULL) {
        printf("Ошибка: передан NULL-указатель в insertItem\n");
        return -1;
    }
    struct Item* pointer = head;
    int len = 0;
    while (pointer -> next != NULL) { 
        pointer = pointer -> next;
        len++;
    }
    return len;
}  
void printItems(struct Item* head) {
    if (head == NULL) {
        printf("Ошибка: передан NULL-указатель в insertItem\n");
        return;
    }
    struct Item* pointer = head;
    while (pointer -> next != NULL) { 
        pointer = pointer -> next;
        printf("%d || ", pointer -> value);
    }
    printf("\n");
}
struct Item* replace(struct Item* head, int a, int b) {
    if (head == NULL) {
        printf("Ошибка: передан NULL-указатель в insertItem\n");
        return NULL;
    }
    struct Item* lastChange = NULL;
    struct Item* pointer;
    pointer = head;
    while (pointer -> next != NULL) {
        pointer = pointer -> next;
        if (pointer -> value == a) {
            pointer -> value = b;
            lastChange = pointer;
        }
    }
    return lastChange;
}
void appendReverse(struct Item* l1, struct Item* l2) { 
    if (l1 == NULL || l2 == NULL) {
        printf("Ошибка: передан NULL-указатель в insertItem\n");
        return;
    }
    struct Item* prev = NULL;
    struct Item* current = l2 -> next;
    struct Item* next = NULL;
    struct Item* pointer = l1;
    //prev - head l2
    while (current != NULL) {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    while (pointer -> next != NULL) {
        pointer = pointer -> next;
    }
    pointer -> next = prev;
}