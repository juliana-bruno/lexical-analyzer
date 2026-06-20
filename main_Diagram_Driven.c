/*
Name: Juliana Bruno
Title: main_Diagram_Driven.c
Description: user inputs a string and it is accepted if it is a binary string that is a multiple of 3,
and rejects all other strings using a diagram driven approach
Date: 4/17/2026
*/

#include <stdio.h>
#include <stdbool.h>

enum State {
    STATE_0,
    STATE_1,
    STATE_2
} current_state = STATE_0;


int main() {
    printf("Diagram Driven Lex:\n");
    printf("Enter input: \n");
   

    char user_input[100] = "";
    fflush(stdout);
    scanf("%99s", user_input);
   
    bool acceptance = true;
    char ch = user_input[0];
    
    for (size_t i = 0; user_input[i] != '\0'; i++) {
        ch = user_input[i];
        printf("Read symbol: %c\n", ch);

        if (ch != '0' && ch != '1') {
            acceptance = false;
            break;
        } else {
            switch (current_state){
        case STATE_0:
            if (ch == '0') {
                current_state = STATE_0;
            } else if (ch == '1') {
                current_state = STATE_1;
            } else {
                acceptance = false;
                break;
            }
            break;
        case STATE_1:
            if (ch == '0') {
                current_state = STATE_2;
            } else if (ch == '1') {
                current_state = STATE_0;
            } else {
                acceptance = false;
                break;
            }
            break;
        case STATE_2:
            if (ch == '0') {
                current_state = STATE_1;
            } else if (ch == '1') {
                current_state = STATE_2;
            } else {
                acceptance = false;
                break;
            }
            break;
        default:
            break;
        }
        }
 

    }
        
    if (current_state == STATE_0 && acceptance == true) {
         printf("String accepted.");
      }else {
          printf("String rejected.");
    }

    return 0;
}
