#include <iostream>
using namespace std;

int main()
{
    char operation;
    double num1, num2;

    cout << "Calculator" << endl;

    cout << "Enter First numbers: ";
    cin >> num1;
    cout << endl;
    cout << "Enter an operation (+, -, *, /): ";
    cin >> operation;
    cout << endl;
    cout << "Enter Second number: ";
    cin >> num2;

    switch (operation)
    {
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
        if (num2 != 0)
        {
            cout << "Result: " << num1 / num2 << endl;
        }
        else
        {
            cout << "Error: Division by zero" << endl;
        }
        break;
    default:
        cout << "Error: Invalid operation" << endl;
    }

    return 0;
}
