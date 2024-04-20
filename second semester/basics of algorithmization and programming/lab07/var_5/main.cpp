#include "stack.h"
#include <iostream>
#include <Windows.h>

using namespace std;

static void displayMenu() {
    cout << "menu:" << endl;
    cout << "1. add elem in Stack1" << endl;
    cout << "2. del elem from Stack1" << endl;
    cout << "3. add elem in Stack2" << endl;
    cout << "4. del elem from Stack2" << endl;
    cout << "5. show all atacks" << endl;
    cout << "6. clean Stack1" << endl;
    cout << "7. clean Stack2" << endl;
    cout << "8. write to file" << endl;
    cout << "9. load from file" << endl;
    cout << "0. exit" << endl;
    cout << "your choice: ";
}

int main() {
    setlocale(LC_ALL, "Russian");

    Stack* stack1 = createStack();
    Stack* stack2 = createStack();
    Stack* stack = createStack();

    int choice;
    int data;
    do {
        system("cls");

        cout << "Stack1: ";
        printStack(stack1);
        cout << "Stack2: ";
        printStack(stack2);
        cout << "Stack: ";
        printStack(stack, stack1, stack2);
        cout << endl;

        displayMenu();
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "enter elem in Stack1: ";
            cin >> data;
            push(stack1, data);
            system("pause");
            break;
        }
        case 2: {
            if (stack1) {
                cout << "deleted elem from Stack1: " << pop(stack1) << endl;
            }
            else {
                cout << "Stack1 is empty!" << endl;
            }
            system("pause");
            break;
        }
        case 3: {
            cout << "enter elem in Stack2: ";
            cin >> data;
            push(stack2, data);
            system("pause");
            break;
        }
        case 4: {
            if (stack2) {
                cout << "deleted elem from Stack2: " << pop(stack2) << endl;
            }
            else {
                cout << "Stack2 is empty!" << endl;
            }
            system("pause");
            break;
        }
        case 5: {
            cout << "Stack1: ";
            printStack(stack1);
            cout << "Stack2: ";
            printStack(stack2);
            cout << "Stack: ";
            printStack(stack, stack1, stack2);
            system("pause");
            break;
        }
        case 6: {
            clear(stack1);
            cout << "Stack1 очищен." << endl;
            system("pause");
            break;
        }
        case 7: {
            clear(stack2);
            cout << "Stack2 очищен." << endl;
            system("pause");
            break;
        }
        case 8: {
            saveToFile(stack1, "stack1.txt");
            saveToFile(stack2, "stack2.txt");
            system("pause");
            break;
        }
        case 9: {
            loadFromFile(stack1, "stack1.txt");
            loadFromFile(stack2, "stack2.txt");
            system("pause");
            break;
        }
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "uncorrect choice, enter right one." << endl;
            system("pause");
            break;
        }
    } while (choice != 0);
}

