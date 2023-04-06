#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Node {
    int data;
    Node* next;
};


class Stack {
    private:
        Node* top;

    public:
        Stack() {
            top = NULL;
        }


        bool isEmpty() {
            return top == NULL;
        }


        bool isFull() {
            return false;
        }


        void push(int x) {
            Node* newNode = new Node;
            newNode->data = x;
            newNode->next = top;
            top = newNode;
        }


        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow";
                return -1;
            }
            int x = top->data;
            Node* temp = top;
            top = top->next;
            delete(temp);
            return x;
        }


        int StackTop() {
            if (isEmpty()) {
                cout << "Stack is empty";
                return -1;
            }
            return top->data;
        }


        void Display() {
            if (isEmpty()) {
                cout << "Stack is empty";
                return;
            }
            Node* curr = top;
            while (curr != NULL) {
                cout << curr->data << " ";
                curr = curr->next;
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
