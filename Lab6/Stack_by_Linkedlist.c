#include <iostream>
using namespace std;

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
        }
};
