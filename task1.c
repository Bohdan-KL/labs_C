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

void packaging() {
    unsigned int O, C, D, N, UnitStateWord;

    O = is_valid_input(32, 1, "Write operation code(0-31): ");
    C = is_valid_input(2, 1, "Write command chain sign(0-1): ");
    D = is_valid_input(2, 1, "Write data chain sign(0-1): ");
    N = is_valid_input(512, 1, "Write number of bytes for transmissions(0-511): ");

    UnitStateWord = (O & 0x1F) << 11;
    UnitStateWord |= ((unsigned char) C & 1) << 10;
    UnitStateWord |= ((unsigned char) D & 1) << 9;
    UnitStateWord |= N & 0x1FF;
    printf("\nDevice status word: %04x\n", UnitStateWord);
    printf(">---------------------------------------------------------------<\n");
}


void unpackaging() {
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
        packaging();
        continue_or_quit();
        goto starting_menu;
    }
    if (reaction == 2) {
        unpackaging();
        continue_or_quit();
        goto starting_menu;
    }
    return 0;
}
