#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void make_title() {
    system("cls||clear");
    printf("Laboratory work №3\n");
    printf("Theme: 'Symbolic data processing'\n");
    printf("Done by st. of gr. КМ-01: Klots Bohdan\n\n");
}


void sorting_sentence() {
    char sentence[250];
    int i, invalid;

    /// Checking is valid sentence
    while (1) {
        printf("Write your sentence(english): ");
        gets(sentence);
        invalid = 0;
        for (i = 0; sentence[i] != '\0'; i++) {
            if ((isalpha(sentence[i]) == 0 && sentence[i] != ' ') || (sentence[i]==' ' && sentence[i+1]==' ')) {
                if (sentence[i + 1] == '\0' &&
                    (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?' || sentence[i] == ';')) break;
                invalid = 1;
                printf("Error! Please, write words only from letters.\n");
                break;
            }
        }
        if (invalid == 0) break;
    }
    /// The end of checking

    /// Creating useful arrays
    int sum_array[254], len_words[254], length, counter_letter=0, counter_word=0;
    length = i;
    sentence[i]=' ';
    sum_array[0]=0;
    len_words[0]=0;
    for (i=0; i<=length; i++){
        if (sentence[i]!=' '){
            counter_letter+=1;
        }
        if (sentence[i]==' '){
            counter_word+=1;
            sum_array[counter_word]= sum_array[counter_word-1]+counter_letter+1;
            len_words[counter_word-1]=counter_letter;
            counter_letter=0;
        }
    }
    /// The end of creating

    /// Sorting and printing
    int repeat = counter_word, remember = 0;
    printf("Result is: ");
    while (repeat!=0){
        int min=260;
        for(i=0; i<counter_word; i++){
            if(min>len_words[i]) {
                min = len_words[i];
                remember = i;
            }}
        len_words[remember]=270;
        for(i=sum_array[remember]; i<sum_array[remember]+min; i++) printf("%c",sentence[i]);
        printf(" ");
        repeat -=1;
    }
    printf("\n>---------------------------------------------------------------<\n");
    /// The end of sorting and printing
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
    printf("| Start first program  ||           1          |\n");
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
        sorting_sentence();
        continue_or_quit();
        goto starting_menu;
    }
    return 0;
}
