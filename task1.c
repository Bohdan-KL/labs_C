#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void make_title() {
    system("cls||clear");
    printf("Laboratory work №2\n");
    printf("Theme: 'One-dimensional and two-dimensional arrays'\n");
    printf("Done by st. of gr. КМ-01: Klots Bohdan\n\n");
}


double is_double_valid_input(char text[1000], char which_matrix[1000], int i, int j) {
    double value;
    char expression;
    printf("%s%s[%d][%d]: ", text, which_matrix, i + 1, j + 1);

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
    printf("Write matrix dimensionality: ");
    while (!scanf("%d%c", &dimensionality, &expression) || expression != '\n' || dimensionality < 0 ||
           dimensionality > 150) {
        rewind(stdin);
        printf("Error! Dimensionality should be from 1 to 150\n");
        printf("Please, write without mistakes: ");
        fflush(stdin);
    }
    return dimensionality;
}

int is_keyboard(char which_matrix[1000]) {
    char expression;
    int reaction;
    printf("Create matrix %s (1 - from keyboard, 0 - auto): ", which_matrix);
    while (!scanf("%d%c", &reaction, &expression) || expression != '\n' || (reaction != 0 && reaction != 1)) {
        rewind(stdin);
        printf("Error! Please, write without mistakes(1 - from keyboard, 0 - auto): ");
        fflush(stdin);
    }
    return reaction;
}


void counting_matrix() {
    unsigned int n;
    int how_create_matrix, i, j, k;
    double AB, BA;
    double A[150][150], B[150][150], RESULT[150][150];
    srand(time(NULL));
    n = is_valid_dimensionality();

    /// creating matrix A
    how_create_matrix = is_keyboard("A");
    if (how_create_matrix == 1) {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                A[i][j] = is_double_valid_input("Write numeric for ", "A", i, j);
        printf("\nMatrix A:\n");
    }
    if (how_create_matrix == 0) {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                A[i][j] = (rand() % 1001 - 500) / 10.0;

        printf("\nGenerated matrix A:\n");
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%lf ", A[i][j]);
        printf("\n");
    }
    printf("\n");
    /// the end of creating matrix A


    /// creating matrix B
    how_create_matrix = is_keyboard("B");
    if (how_create_matrix == 1) {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                B[i][j] = is_double_valid_input("Write numeric for ", "B", i, j);
        printf("\nMatrix B:\n");
    }
    if (how_create_matrix == 0) {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                B[i][j] = (rand() % 1001 - 500) / 10.0;

        printf("\nGenerated matrix B:\n");
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%lf ", B[i][j]);
        printf("\n");
    }
    printf("\n");
    /// the end of creating matrix B


    /// creating RESULT matrix (AB-BA)
    for (i = 0; i < n; i++)
        for (k = 0; k < n; k++) {
            AB = 0;
            BA = 0;
            for (j = 0; j < n; j++) {
                AB += A[i][j] * B[j][k];
                BA += B[i][j] * A[j][k];
            }
            RESULT[i][k] = AB - BA;
        }

    /// print RESULT matrix
    printf("AB-BA matrix is:\n");
    for (i = 0; i < n; i++) {
        for (k = 0; k < n; k++)
            printf("%lf ", RESULT[i][k]);
        printf("\n");
    }


    printf("\n>---------------------------------------------------------------<\n");
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
        printf("Good by!\n");
        system("pause");
        exit(0);
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
    printf("|  Start the program   ||           1          |\n");
    printf("└──────────────────────┘└──────────────────────┘\n");
    printf("My choose is: ");

    while (!scanf("%d%c", &reaction, &expression) || expression != '\n' ||
           (reaction != 0 && reaction != 1)) {
        rewind(stdin);
        printf("Error! Please, write '0' or '1': ");
        fflush(stdin);
    }
    if (reaction == 0) {
        printf("Good by!\n");
        system("pause");
    }
    if (reaction == 1) {
        counting_matrix();
        continue_or_quit();
        goto starting_menu;
    }
    return 0;
}
