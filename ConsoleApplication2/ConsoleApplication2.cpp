#include <iostream>
using namespace std;

const int MAX = 10;

class Stack {
private:
    int st[MAX];
    int top;

public:
    class Range {};

    Stack() {
        top = -1;
    }

    void push(int var) {
        if (top >= MAX - 1)
            throw Range();
        st[++top] = var;
    }

    int pop() {
        if (top < 0)
            throw Range();
        return st[top--];
    }

    bool is_empty() {
        return top < 0;
    }
};

int main() {
    long decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    Stack binaryStack;

    if (decimalNumber == 0) {
        binaryStack.push(0);
    }
    else {
        while (decimalNumber > 0) {
            binaryStack.push(decimalNumber % 2);
            decimalNumber /= 2;
        }
    }

    cout << "Binary representation: ";

    while (!binaryStack.is_empty()) {
        cout << binaryStack.pop();
    }

    cout << endl;

    return 0;
}
