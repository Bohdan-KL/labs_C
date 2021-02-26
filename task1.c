#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void make_title() {
    system("cls||clear");
    printf("\n┌────────────────────────────────────────────────────────────────────────────────────────────────┐");
    printf("\n│                                    Laboratory work №2                                          │");
    printf("\n│                                                                                                │");
    printf("\n│ Theme: 'One-dimensional and two-dimensional arrays'                                            │");
    printf("\n│                                                                                                │");
    printf("\n│      Done by st. of gr. КМ-01                                         Klots B                  │");
    printf("\n│                                                                                                │");
    printf("\n│                                                                                                │");
    printf("\n│                                              2020                                              │");
    printf("\n└────────────────────────────────────────────────────────────────────────────────────────────────┘\n\n");
}


double is_valid_input(char text[1000]) {
    double value;
    char expression;
    printf(text);
    while (!scanf("%lf%c", &value, &expression) || expression != '\n') {
        rewind(stdin);
        printf("Error! Please, write without mistakes: ");
        fflush(stdin);
    }

    return value;
}


unsigned int is_valid_dimensionality() {
    unsigned int dimensionality;
    char expression;
    printf("Write array dimensionality: ");
    while (!scanf("%d%c", &dimensionality, &expression) || expression != '\n' || dimensionality < 0 ||
           dimensionality > 10000) {
        rewind(stdin);
        printf("Error! Dimensionality should be from 1 to 10000\n");
        printf("Please, write without mistakes: ");
        fflush(stdin);
    }
    return dimensionality;
}

int is_keyboard() {
    char expression;
    int reaction;
    printf("Create array(1 - from keyboard, 0 - auto): ");
    while (!scanf("%d%c", &reaction, &expression) || expression != '\n' || (reaction != 0 && reaction != 1)) {
        rewind(stdin);
        printf("Error! Please, write without mistakes(1 - from keyboard, 0 - auto): ");
        fflush(stdin);
    }
    return reaction;
}


void counting() {
    unsigned int n, result = 0, pre_result = 0;
    int how_create_array, i;
    double A[10005];
    srand(time(NULL));
    n = is_valid_dimensionality();
    how_create_array = is_keyboard();
    if (how_create_array == 1) {
        for (i = 0; i < n; i++)
            A[i] = is_valid_input("Write numeric: ");
    }
    if (how_create_array == 0) {
        for (i = 0; i < n - 1; i++)
            A[i] = (rand() % 1001 - 500) / 10.0;
        printf("Generated array: ");
        for (i = 0; i < n - 1; i++)
            printf("%f, ", A[i]);
        A[n - 1] = (rand() % 1001 - 500) / 10.0;
        printf("%f.\n", A[i]);
    }

    for (i = 0; i < n; i++) {
        if (A[i] < 0) pre_result += 1;
        if (A[i] >= 0 & pre_result != 0) {
            if (pre_result > result)
                result = pre_result;
            pre_result = 0;
        }
    }


    printf("\nThe maximum number of negative consecutive elements is: %d", result);
    printf("\n>---------------------------------------------------------------<\n");
}


void sorting() {

    printf(">---------------------------------------------------------------<\n");

}

void continue_or_quit() {
    printf("Do you want to clear console and continue? (yes - 1, no - 0): ");
    int reaction;
    char expression;
    while (!scanf("%d%c", &reaction, &expression) || expression != '\n') {
        rewind(stdin);
        printf("Error! Please, write '1' or '0': ");
        fflush(stdin);
    }
    if (reaction == 1) system("cls");

    if (reaction == 0) {
        printf("Good by!");
        Sleep(4000);
        GenerateConsoleCtrlEvent(CTRL_BREAK_EVENT, 0); // close console
    }

}

int main() {
    starting_menu: // label for goto
    make_title();
    int reaction;
    char expression;
    printf("Welcome to the main menu!\nPlease, choose something.\n");
    printf("┌──────────────────────┐┌──────────────────────┐\n");
    printf("|      What to do      ||      What write      |\n");
    printf("└──────────────────────┘└──────────────────────┘\n");
    printf("┌──────────────────────┐┌──────────────────────┐\n");
    printf("|        Quit          ||           0          |\n");
    printf("| Start first program  ||           1          |\n");
    printf("| Start second program ||           2          |\n");
    printf("└──────────────────────┘└──────────────────────┘\n");
    printf("My choose is: ");

    while (!scanf("%d%c", &reaction, &expression) || expression != '\n' ||
           (reaction != 0 && reaction != 1 && reaction != 2)) {
        rewind(stdin);
        printf("Error! Please, write '0', '1' or '2': ");
        fflush(stdin);
    }
    if (reaction == 0) {
        printf("Good by!");
        Sleep(4000);
    }
    if (reaction == 1) {
        counting();
        continue_or_quit();
        goto starting_menu;
    }
    if (reaction == 2) {
        sorting();
        continue_or_quit();
        goto starting_menu;
    }
    return 0;
}
