#pragma once
#include <stdio.h>

#include "Device.h";

typedef struct Node {
	Device value;
	struct Node* next;
} Node;

typedef struct {
	Node* root;
} List;

void add(List* list, Device value) {
	Node* node = malloc(sizeof(Node));
	node->value = value;
	if (list->root == 0) {
		node->next = 0;
		list->root = node;
		return;
	}

	if (list->root->value.serialNumber > value.serialNumber) {
		node->next = list->root;
		list->root = node;
		return;
	}

	Node* curr = list->root;

	while (curr->next != 0 && curr->next->value.serialNumber < value.serialNumber) {
		curr = curr->next;
	}

	node->next = curr->next;
	curr->next = node;
}

void printList(List* list) {
	if (list->root == 0) {
		printf("Список пуст\n");
		return;
	}

	Node* curr = list->root;

	while (curr != 0) {
		printf("{Серийный номер: %d, Фирма: %s, ", curr->value.serialNumber, curr->value.firm);
		printf("Модель: %s, Год выпуска: %d, ", curr->value.model, curr->value.year);
		printf("Серия: %s}\n", curr->value.series);

		curr = curr->next;
	}
}