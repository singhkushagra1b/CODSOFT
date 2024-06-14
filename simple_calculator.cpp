//SIMPLE CALCULATOR


#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;

    cout << "Simple Calculator" << endl;
    cout << "------------------" << endl;
    cout << "Enter two numbers:" << endl;
    cin >> num1 >> num2;

    cout << "Choose an operation (+,-,*,/): ";
    cin >> operation;

    switch(operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if(num2!= 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Error Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid operation!" << endl;
            break;
    }

    return 0;
}
