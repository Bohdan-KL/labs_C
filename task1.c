#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void make_title() {
    system("cls||clear");
    printf("\n┌────────────────────────────────────────────────────────────────────────────────────────────────┐");
    printf("\n│                                    Laboratory work №1                                          │");
    printf("\n│                                                                                                │");
    printf("\n│ Theme: 'Base type of data, input-output, operations with bits, operations of bit shifting'     │");
    printf("\n│                                                                                                │");
    printf("\n│      Done by st. of gr. КМ-01                                         Klots B                  │");
    printf("\n│                                                                                                │");
    printf("\n│                                                                                                │");
    printf("\n│                                              2020                                              │");
    printf("\n└────────────────────────────────────────────────────────────────────────────────────────────────┘\n\n");
}


double double_valid_input(char text[1000]) {
    double db;
    char expression;
    printf(text);
    while (!scanf("%lf%c", &db, &expression) || expression != '\n' || db < 100 || db >= 1000) {
        rewind(stdin);
        printf("Error! Please, write without mistakes (for example - 372.2): ");
        fflush(stdin);
    }
    return db;
}

void ten_percent() {
    double number;
    number = double_valid_input("Write the number(100-999): ");
    printf("10%% of the number is: %lf\n", number * 0.1);
    printf(">---------------------------------------------------------------<\n");
}


long long long_long_valid_input(char text[1000]) {
    long long number;
    char expression;
    printf(text);
    while (!scanf("%lld%c", &number, &expression) || expression != '\n') {
        rewind(stdin);
        printf("Error! Please, write without mistakes: ");
        fflush(stdin);
    }
    return number;
}

void second_function() {
    long long a1, a2, a3, a4, a5, b1, b2, b3, b4, b5;

    a1 = long_long_valid_input("Write a1: ");
    a2 = long_long_valid_input("Write a2: ");
    a3 = long_long_valid_input("Write a3: ");
    a4 = long_long_valid_input("Write a4: ");
    a5 = long_long_valid_input("Write a5: ");

    b1 = long_long_valid_input("Write b1: ");
    b2 = long_long_valid_input("Write b2: ");
    b3 = long_long_valid_input("Write b3: ");
    b4 = long_long_valid_input("Write b4: ");
    b5 = long_long_valid_input("Write b5: ");
    printf("The value of the a1*b1+a2*b2+a3*b3+a4*b4+a5*b5 is: %lld\n",
           a1 * b1 + a2 * b2 + a3 * b3 + a4 * b4 + a5 * b5);
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
        ten_percent();
        continue_or_quit();
        goto starting_menu;
    }
    if (reaction == 2) {
        second_function();
        continue_or_quit();
        goto starting_menu;
    }
    return 0;
}

