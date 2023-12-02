#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// Структура для элементов списка
struct Node 
{
    int data;
    struct Node* next;
};

Node* InitListWithHeader();
Node* InitListWithoutHeader();
void PushWithHeader(Node* header, int key);
Node* PushWithoutHeader(Node* head, int key);
void DeleteWithHeader(Node* header, int key);
Node* DeleteWithoutHeader(struct Node* head, int key);
Node* SearchWithHeader(Node* header, int key);
Node* SearchWithoutHeader(Node* head, int key);
void ShowListWithHeader(Node* header);
void ShowListWithoutHeader(Node* head);
void FreeMemory(Node* header, Node* headWithoutHeader);