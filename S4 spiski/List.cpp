#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "List.h"


/*10. 
Напишите процедуры для включения, исключения и поиска элемента, идентифицированного заданным ключом.Проделайте это для списка
с заголовком, а потом – без заголовка.*/

// Инициализация списка с заголовком
Node* InitListWithHeader()
{
    Node* header = (Node*)malloc(sizeof(Node));
    header->next = header;
    return header;
}

// Инициализация списка без заголовка
Node* InitListWithoutHeader()
{
    return NULL;
}


// Вставка элемента с ключом key в список с заголовком
void PushWithHeader(Node* header, int key)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;

    if (header->next == header) {
        // Если список пуст, просто добавьте элемент и сделайте его следующим за заголовком
        newNode->next = header;
        header->next = newNode;
    }
    else {
        // Иначе найдите последний элемент и добавьте новый элемент после него
        Node* current = header->next;
        while (current->next != header) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}


// Вставка элемента с ключом key в список без заголовка
Node* PushWithoutHeader(Node* head, int key)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;

    if (head == NULL) {
        // Если список пуст, просто добавьте элемент и верните его как новую голову списка
        newNode->next = NULL;
        return newNode;
    }
    else {
        // Иначе найдите последний элемент и добавьте новый элемент после него
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        newNode->next = NULL;
        current->next = newNode;
        return head;
    }
}



// Удаление элемента с ключом key из списка с заголовком
void DeleteWithHeader(Node* header, int key) 
{
    Node* current = header;
    while (current->next != header) 
    {
        if (current->next->data == key) 
        {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            break;
        }
        current = current->next;
    }
}

// Удаление элемента с ключом key из списка без заголовка
Node* DeleteWithoutHeader(struct Node* head, int key) 
{
    Node* current = head;
    Node* prev = NULL;
    while (current != NULL) 
    {
        if (current->data == key) 
        {
            if (prev != NULL)
                prev->next = current->next;
            else
                head = current->next;
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
    return head;
}

// Поиск элемента с ключом key в списке с заголовком
Node* SearchWithHeader(Node* header, int key) 
{
    Node* current = header->next;
    while (current != header) 
    {
        if (current->data == key) 
            return current;
        current = current->next;
    }
    return NULL;
}

// Поиск элемента с ключом key в списке без заголовка
Node* SearchWithoutHeader(Node* head, int key) 
{
    Node* current = head;
    while (current != NULL)
    {
        if (current->data == key) 
            return current;
        current = current->next;
    }
    return NULL;
}

// Отображение списка с заголовком
void ShowListWithHeader(Node* header) 
{
    Node* current = header->next;
    while (current != header) 
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Отображение списка без заголовка
void ShowListWithoutHeader(Node* head) 
{
    Node* current = head;
    while (current != NULL) 
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Функция для освобождения памяти, включая узлы списка
void FreeMemory(Node* header, Node* headWithoutHeader) 
{
    // Освобождаем память, начиная с заголовка, для списка с заголовком
    Node* current = header->next;
    while (current != header) 
    {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(header);

    // Освобождаем память для списка без заголовка
    current = headWithoutHeader;
    while (current != NULL) 
    {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    system("chcp 1251");

    Node* listWithHeader = InitListWithHeader();
    Node* listWithoutHeader = InitListWithoutHeader();
    Node* result = NULL;

    int choice, value, index;
    bool flag = true;
    while (flag)
    {
        do
        {
            printf("1 - добавить элемент в список с заголовком\n"
                "2 - добавить элемент в список без заголовка\n"
                "3 - удалить элемент из списка с заголовком\n"
                "4 - удалить элемент из списка без заголовка\n"
                "5 - найти элемент в списке с заголовком\n"
                "6 - найти элемент в списке без заголовка\n"
                "7 - выйти\n");
            scanf("%i", &choice);
        } while (choice < 1 || choice > 7);
        system("cls");
        switch (choice)
        {
        case 1:
            printf("Введите значение, которое хотите добавить в список с заголовком: ");
            scanf("%d", &value);
            PushWithHeader(listWithHeader, value);
            break;
        case 2:
            printf("Введите значение, которое хотите добавить в список без заголовка: ");
            scanf("%d", &value);
            listWithoutHeader = PushWithoutHeader(listWithoutHeader, value);
            break;
        case 3:
            printf("Введите элемент, который хотите удалить из списка с заголовком: ");
            scanf("%d", &value);
            DeleteWithHeader(listWithHeader, value);
            break;
        case 4:
            printf("Введите элемент, который хотите удалить из списка без заголовка: ");
            scanf("%d", &value);
            listWithoutHeader = DeleteWithoutHeader(listWithoutHeader, value);
            break;
        case 5:
            printf("Введите элемент, который хотите найти в списке с заголовком: ");
            scanf("%d", &value);
            result = SearchWithHeader(listWithHeader, value);
            if (result != NULL)
                printf("Элемент найден в списке с заголовком: %d\n", result->data);
            else
                printf("Элемент не найден в списке с заголовком.\n");
            break;
        case 6:
            printf("Введите элемент, который хотите найти в списке без заголовка: ");
            scanf("%d", &value);
            result = SearchWithoutHeader(listWithoutHeader, value);
            if (result != NULL)
                printf("Элемент найден в списке без заголовка: %d\n", result->data);
            else
                printf("Элемент не найден в списке без заголовка.\n");
            break;
        case 7:
            flag = false;
            break;
        }
        printf("Список с заголовком: ");
        ShowListWithHeader(listWithHeader);
        printf("Список без заголовка: ");
        ShowListWithoutHeader(listWithoutHeader);
    }

    FreeMemory(listWithHeader, listWithoutHeader);

    return 0;
}