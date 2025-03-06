#pragma once
#define LIST_H

// Создание структуры списка
struct Item {
    int value;
    struct Item* next;
};

// Прототипы функций работы со списками 
void insertItem(struct Item* head, int insertValue, int index);
void appendItem(struct Item* head, int toAppend);
void deleteItem(struct Item* head, int index);
void popItem(struct Item* head);
void getData(const struct Item* head, int index);
void getAddress(const struct Item* head, int index);
int len(const struct Item* head);
void printItems(struct Item* head);
struct Item* replace(struct Item* head, int a, int b);
void appendReverse(struct Item* l1, struct Item* l2);