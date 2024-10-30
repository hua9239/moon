#include <stdio.h>
#include <iostream>
using namespace std;

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
void InfixToPostfix(char infix[], char Postfix[20]) {
    char symbol_temp[10] = {};  // ???I?Ÿ????s??
    int current_infix = -1, symbol_top = -1, postfix_top = -1;

    while (infix[++current_infix]) {
        switch (infix[current_infix]) {
            // ?I?? '(' ?N??????i?hsymbol_temp
            case '(':
                symbol_temp[++symbol_top] = infix[current_infix];
                break;  // case '(':

            // ?I?? '+ - * /' ?N?Q??op?j?p?M?w
            case '+':
            case '-':
            case '*':
            case '/':
                // ?{?b?o?? ?M ??b symbol_temp ???u???v?A?p??N?@????X
                while (Priority(infix[current_infix]) <=
                       Priority(symbol_temp[symbol_top])) {
                    Postfix[++postfix_top] = symbol_temp[symbol_top--];
                }
                // ??{?b????i?h
                symbol_temp[++symbol_top] = infix[current_infix];
                break;  // case '+': case '-': case '*': case '/':

            // ?I?? ')' ?N??X?쪽?? '('????
            case ')':
                while (symbol_temp[symbol_top] != '(')
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
}

int Transfer(char postfix[]) {
    int number[20] = {};
    int top = -1, ansNum;

    for (int i = 0; postfix[i] != '\0'; i++) {
        // 1.?p?G?O?[???
        // 2.?N??e??ӼƦr???X?@?p??
        // 3. ??p??n???Ʀr??^?h??^?h

        switch (postfix[i]) {
            case '+':
                ansNum = number[top - 1] + number[top];
                top -= 2;
                break;
            case '-':
                ansNum = number[top - 1] - number[top];
                top -= 2;
                break;
            case '*':
                ansNum = number[top - 1] * number[top];
                top -= 2;
                break;
            case '/':
                ansNum = number[top - 1] / number[top];
                top -= 2;
                break;
            // ?Y?O?Ʀr ?????s?J
            default:
                ansNum = postfix[i] - '0';
        }

        number[++top] = ansNum;
    }
    return number[0];
}

int Eval(char infix[]) {
    char Postfix[20] = {};  // ?ন??Ǫ?Postfix
    InfixToPostfix(infix, Postfix);
    return Transfer(Postfix);
}

int main(int argc, char* argv[]) {
    char itemset[20];
    scanf("%s", itemset);
    cout << Eval(itemset);
}