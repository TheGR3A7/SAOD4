#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "List.h"


/*10. 
�������� ��������� ��� ���������, ���������� � ������ ��������, ������������������� �������� ������.���������� ��� ��� ������
� ����������, � ����� � ��� ���������.*/

// ������������� ������ � ����������
Node* InitListWithHeader()
{
    Node* header = (Node*)malloc(sizeof(Node));
    header->next = header;
    return header;
}

// ������������� ������ ��� ���������
Node* InitListWithoutHeader()
{
    return NULL;
}


// ������� �������� � ������ key � ������ � ����������
void PushWithHeader(Node* header, int key)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;

    if (header->next == header) {
        // ���� ������ ����, ������ �������� ������� � �������� ��� ��������� �� ����������
        newNode->next = header;
        header->next = newNode;
    }
    else {
        // ����� ������� ��������� ������� � �������� ����� ������� ����� ����
        Node* current = header->next;
        while (current->next != header) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}


// ������� �������� � ������ key � ������ ��� ���������
Node* PushWithoutHeader(Node* head, int key)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;

    if (head == NULL) {
        // ���� ������ ����, ������ �������� ������� � ������� ��� ��� ����� ������ ������
        newNode->next = NULL;
        return newNode;
    }
    else {
        // ����� ������� ��������� ������� � �������� ����� ������� ����� ����
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        newNode->next = NULL;
        current->next = newNode;
        return head;
    }
}



// �������� �������� � ������ key �� ������ � ����������
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

// �������� �������� � ������ key �� ������ ��� ���������
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

// ����� �������� � ������ key � ������ � ����������
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

// ����� �������� � ������ key � ������ ��� ���������
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

// ����������� ������ � ����������
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

// ����������� ������ ��� ���������
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

// ������� ��� ������������ ������, ������� ���� ������
void FreeMemory(Node* header, Node* headWithoutHeader) 
{
    // ����������� ������, ������� � ���������, ��� ������ � ����������
    Node* current = header->next;
    while (current != header) 
    {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(header);

    // ����������� ������ ��� ������ ��� ���������
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
            printf("1 - �������� ������� � ������ � ����������\n"
                "2 - �������� ������� � ������ ��� ���������\n"
                "3 - ������� ������� �� ������ � ����������\n"
                "4 - ������� ������� �� ������ ��� ���������\n"
                "5 - ����� ������� � ������ � ����������\n"
                "6 - ����� ������� � ������ ��� ���������\n"
                "7 - �����\n");
            scanf("%i", &choice);
        } while (choice < 1 || choice > 7);
        system("cls");
        switch (choice)
        {
        case 1:
            printf("������� ��������, ������� ������ �������� � ������ � ����������: ");
            scanf("%d", &value);
            PushWithHeader(listWithHeader, value);
            break;
        case 2:
            printf("������� ��������, ������� ������ �������� � ������ ��� ���������: ");
            scanf("%d", &value);
            listWithoutHeader = PushWithoutHeader(listWithoutHeader, value);
            break;
        case 3:
            printf("������� �������, ������� ������ ������� �� ������ � ����������: ");
            scanf("%d", &value);
            DeleteWithHeader(listWithHeader, value);
            break;
        case 4:
            printf("������� �������, ������� ������ ������� �� ������ ��� ���������: ");
            scanf("%d", &value);
            listWithoutHeader = DeleteWithoutHeader(listWithoutHeader, value);
            break;
        case 5:
            printf("������� �������, ������� ������ ����� � ������ � ����������: ");
            scanf("%d", &value);
            result = SearchWithHeader(listWithHeader, value);
            if (result != NULL)
                printf("������� ������ � ������ � ����������: %d\n", result->data);
            else
                printf("������� �� ������ � ������ � ����������.\n");
            break;
        case 6:
            printf("������� �������, ������� ������ ����� � ������ ��� ���������: ");
            scanf("%d", &value);
            result = SearchWithoutHeader(listWithoutHeader, value);
            if (result != NULL)
                printf("������� ������ � ������ ��� ���������: %d\n", result->data);
            else
                printf("������� �� ������ � ������ ��� ���������.\n");
            break;
        case 7:
            flag = false;
            break;
        }
        printf("������ � ����������: ");
        ShowListWithHeader(listWithHeader);
        printf("������ ��� ���������: ");
        ShowListWithoutHeader(listWithoutHeader);
    }

    FreeMemory(listWithHeader, listWithoutHeader);

    return 0;
}