/*
Name: Juliana Bruno
Title: main_Table_Driven.c
Description: user inputs a string and it is accepted if it is a binary string that is a multiple of 3,
and rejects all other strings using a table driven approach
Date: 4/17/2026
*/


#include <stdio.h>
#include <stdbool.h>

enum State {
    STATE_0,
    STATE_1,
    STATE_2
};

enum Label {
    zero,
    one,
};

enum State current_state = STATE_0;
enum State table [3][2] = {
    {STATE_0, STATE_1}, //STATE_0
    {STATE_2, STATE_0}, //STATE_1
    {STATE_1, STATE_2}  //STATE_2
};
int label;

int main() {
    char ch;
    printf("Table Driven Lex:\n");
    printf("Enter input: \n");

    char user_input[100] = "";
    fflush(stdout);
    scanf("%99s", user_input);
    bool acceptance = true;

    for (size_t i = 0; user_input[i] != '\0'; i++) {
        ch = user_input[i];
        printf("Read symbol: %c\n", ch);

        if (ch != '0' && ch != '1') {
            acceptance = false;
            break;
        } else if (ch == '0') {
            label = zero;
            current_state = table[current_state][label];

        } else if (ch == '1') {
            label = one;
            current_state = table[current_state][label];
        }

    }

    if (current_state == STATE_0 && acceptance == true) {
        printf("String accepted.");
    } else {
        printf("String rejected.");
    }


    return 0;
}
