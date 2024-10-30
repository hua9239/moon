#include <stdio.h>
#include <iostream>
using namespace std;

// 3-9 ??????e?? //

//?^???u????
int Priority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// ??J???? ?^?ǫ??
void InfixToPrefix(char infix[]) {
    char Postfix[20] = {};      // ?ন??Ǫ?Postfix
    char symbol_temp[10] = {};  // ???I?Ÿ????s??
    int current_infix = 0, symbol_top = -1, postfix_top = -1;

    for (int i = 0; infix[i] != '\0'; i++) {
        current_infix++;
    }

    while (infix[--current_infix]) {
        switch (infix[current_infix]) {
            // ?I?? '(' ?N??????i?hsymbol_temp
            case ')':
                symbol_temp[++symbol_top] = infix[current_infix];
                break;  // case ')':

            // ?I?? '+ - * /' ?N?Q??op?j?p?M?w
            case '+':
            case '-':
            case '*':
            case '/':
                // ?{?b?o?? ?M ??b symbol_temp ???u???v?A?p??N?@????X
                while (Priority(infix[current_infix]) <
                       Priority(symbol_temp[symbol_top])) {
                    Postfix[++postfix_top] = symbol_temp[symbol_top--];
                }
                // ??{?b????i?h
                symbol_temp[++symbol_top] = infix[current_infix];
                break;  // case '+': case '-': case '*': case '/':

            // ?I?? ')' ?N??X?쪽?? '('????
            case '(':
                while (symbol_temp[symbol_top] != ')')
                    Postfix[++postfix_top] = symbol_temp[symbol_top--];
                symbol_top--;
                break;  //  case ')':

            default:
                Postfix[++postfix_top] = infix[current_infix];
        }

    }  // while end

    while (symbol_temp[symbol_top]) {
        Postfix[++postfix_top] = symbol_temp[symbol_top--];
    }

    for (int i = postfix_top; i >= 0; i--)
        cout << Postfix[i];
}

int main(int argc, char* argv[]) {
    char itemset[20];
    scanf("%s", itemset);
    InfixToPrefix(itemset);
}