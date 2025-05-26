#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "List.h"

int main(void)
{
    char* locale = setlocale(LC_ALL, "");
    system("chcp 1251");
    List list = { 0 };

    while (1) {
        printf("Выберите операцию:\n");
        printf("1: Добавить технику:\n");
        printf("2: Вывести список техники:\n");
        printf("3: Выход:\n");

        int operation;

        printf("->");
        scanf("%d", &operation);

        if (operation == 3) break;
        if (operation == 2) {
            printList(&list);
            continue;
        }

        if (operation != 1) {
            printf("Выберите операцию от 1 до 3\n");
            continue;
        }

        Device device;
        device.firm = malloc(11 * sizeof(char));
        device.model = malloc(11 * sizeof(char));
        device.series = malloc(11 * sizeof(char));

        printf("Введите серийный номер: ");
        scanf("%d", &device.serialNumber);


        printf("Введите фирму: ");
        scanf("%s", device.firm);

        printf("Введите модель: ");
        scanf("%s", device.model);

        printf("Введите год выпуска: ");
        scanf("%d", &device.year);

        printf("Введите серию: ");
        scanf("%s", device.series);

        add(&list, device);
    }

    return 0;
}