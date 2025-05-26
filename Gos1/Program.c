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
        printf("�������� ��������:\n");
        printf("1: �������� �������:\n");
        printf("2: ������� ������ �������:\n");
        printf("3: �����:\n");

        int operation;

        printf("->");
        scanf("%d", &operation);

        if (operation == 3) break;
        if (operation == 2) {
            printList(&list);
            continue;
        }

        if (operation != 1) {
            printf("�������� �������� �� 1 �� 3\n");
            continue;
        }

        Device device;
        device.firm = malloc(11 * sizeof(char));
        device.model = malloc(11 * sizeof(char));
        device.series = malloc(11 * sizeof(char));

        printf("������� �������� �����: ");
        scanf("%d", &device.serialNumber);


        printf("������� �����: ");
        scanf("%s", device.firm);

        printf("������� ������: ");
        scanf("%s", device.model);

        printf("������� ��� �������: ");
        scanf("%d", &device.year);

        printf("������� �����: ");
        scanf("%s", device.series);

        add(&list, device);
    }

    return 0;
}