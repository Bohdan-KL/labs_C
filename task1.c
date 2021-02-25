#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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


unsigned int is_valid_input(int max_value, int is_int, char text[1000]) {
    unsigned int value;
    char expression;
    printf(text);
    if (is_int == 1) {
        while (!scanf("%d%c", &value, &expression) || expression != '\n' || value >= max_value || value < 0) {
            rewind(stdin);
            printf("Error! Please, write without mistakes (0-%d): ", max_value - 1);
            fflush(stdin);
        }
    }
    if (is_int == 0) {
        while (!scanf("%x%c", &value, &expression) || expression != '\n' || value<0 || value>0xFFFF) {
            rewind(stdin);
            printf("Error! Please, write without mistakes: ");
            fflush(stdin);
        }
    }
    return value;
}


unsigned int is_valid_dimensionality() {
    unsigned int dimensionality;
    char expression;
    printf("Write array dimensionality: ");
    while (!scanf("%d%c", &dimensionality, &expression) || expression != '\n' || dimensionality < 0 || dimensionality > 10000) {
        rewind(stdin);
        printf("Error! Dimensionality should be from 1 to 10000\n");
        printf("Please, write without mistakes: ");
        fflush(stdin);
    }
    return dimensionality;
}

void counting() {
    unsigned int size;
    size = is_valid_dimensionality();
    printf("%d",size);
    printf("\n>---------------------------------------------------------------<\n");
}


void sorting() {
    unsigned int O, C, D, N, UnitStateWord;
    UnitStateWord = is_valid_input(0, 0, "Write status code: ");
    O = (UnitStateWord >> 11) & 0x1F;
    C = (UnitStateWord >>  10) & 1;
    D = (UnitStateWord >>  9) & 1;
    N = UnitStateWord & 0x1FF;
    printf("\nOperation code is: %d\n",O);
    printf("Command chain sign is: %d\n",C);
    printf("Data chain sign is: %d\n",D);
    printf("Number of bytes for transmissions is: %d\n",N);
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
