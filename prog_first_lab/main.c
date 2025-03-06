#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main() {
    // Создаём список
    struct Item* head = (struct Item*)malloc(sizeof(struct Item));
    if (!head) {
        printf("Ошибка: не удалось выделить память для head\n");
        return 1;
    }
    head->next = NULL;  // Пустой список


    printf("len(head) = %d (ожидается 0)\n", len(head));

    printf("Добавляем элементы: 10, 20, 30\n");
    appendItem(head, 10);
    appendItem(head, 20);
    appendItem(head, 30);
    printItems(head);

    printf("Вставляем 15 на позицию 2\n");
    insertItem(head, 15, 2);
    printItems(head);

    printf("Вставляем 5 на позицию 1\n");
    insertItem(head, 5, 1);
    printItems(head);

    printf("Получаем элементы:\n");
    getData(head, 1);
    getData(head, 2);
    getData(head, 3);
    getData(head, 5);
    
    printf("Адреса элементов:\n");
    getAddress(head, 1);
    getAddress(head, 2);
    getAddress(head, 3);
    getAddress(head, 5);

    printf("Удаляем элемент 2\n");
    deleteItem(head, 2);
    printItems(head);

    printf("Удаляем первый элемент\n");
    deleteItem(head, 1);
    printItems(head);

    printf("Удаляем последний элемент\n");
    popItem(head);
    printItems(head);

    printf("len(head) = %d (ожидается 2)\n", len(head));

    printf("Некорректные вызовы:\n");
    getData(head, 10);  // Неверный индекс
    deleteItem(head, 10); // Удаление несуществующего элемента
    insertItem(head, 100, 10); // Вставка за пределами

    printf("Передача NULL:\n");
    getData(NULL, 1);
    insertItem(NULL, 100, 1);
    appendItem(NULL, 50);
    deleteItem(NULL, 1);
    popItem(NULL);

    // Список для тестирования доп функций
    struct Item* head2 = (struct Item*)malloc(sizeof(struct Item));
    if (!head2) {
        printf("Ошибка: не удалось выделить память для head\n");
        return 1;
    }

    head2 ->next = NULL;
    printf("Добавляем 11 21 31\n");
    appendItem(head2, 11);
    appendItem(head2, 21);
    appendItem(head2, 31);
    printItems(head2);
    printf("Меняем 31 на 9\n");
    replace(head2, 31, 9);
    printItems(head2);
    printf("Добавляем реверсивный список head2 в head\n");
    appendReverse(head, head2);
    printItems(head);
    printf("Некорректные вызовы\n");
    replace(NULL, 32, 21);
    appendReverse(NULL, head);
    appendReverse(head, NULL);

    return 0;
}
