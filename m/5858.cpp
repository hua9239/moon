#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

int Transfer(char postfix[]) {
    int number[20] = {};
    int top = -1, ansNum;

    for (int i = 0; postfix[i] != '\0'; i++) {

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
            // ?Y?O??r ?????s?J
        default:
            ansNum = postfix[i] - '0';
        }

        number[++top] = ansNum;
    }

    return number[0];
}

int main(int argc, char* argv[]) {
    char itemset[20];
    scanf("%s", itemset);
    cout << Transfer(itemset);
}
