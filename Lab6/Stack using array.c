#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;


#define MAX_SIZE 25

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        top++;
        arr[top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int StackTop() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void Display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    auto start = high_resolution_clock::now();
    Stack s;
    s.push(8);
    s.push(5);
    s.push(11);
    s.push(23);
    s.push(18);
    s.push(20);
    s.Display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.Display();
    s.push(4);
    s.push(30);
    s.push(1);
    s.Display();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Execution time: " << duration.count() << " nanoseconds" << endl;
    return 0;

}
