/*Q1:)
#include <iostream>
#define SIZE 5
using namespace std;

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() { return (front == -1); }
    bool isFull() { return (rear == SIZE - 1); }

    // Insert element in queue
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert.\n";
            return;
        }
        if (isEmpty()) front = 0;
        arr[++rear] = x;
        cout << x << " inserted into queue.\n";
    }

    // Remove element from queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Nothing to delete.\n";
            return;
        }
        cout << "Removed element: " << arr[front] << endl;
        if (front == rear) front = rear = -1; // queue becomes empty
        else front++;
    }

    // Show all elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // Show front element
    void peek() {
        if (!isEmpty())
            cout << "Front element is: " << arr[front] << endl;
        else
            cout << "Queue is Empty!\n";
    }
};

int main() {
    Queue q;
    int choice, val;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue (Insert)\n2. Dequeue (Delete)\n3. Check if Empty\n4. Check if Full\n5. Display\n6. Peek (Front Element)\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: cout << (q.isEmpty() ? "Queue is Empty\n" : "Queue is NOT Empty\n"); break;
            case 4: cout << (q.isFull() ? "Queue is Full\n" : "Queue is NOT Full\n"); break;
            case 5: q.display(); break;
            case 6: q.peek(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
Q2:)
#include <iostream>
#define SIZE 5
using namespace std;

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isEmpty() { return (front == -1); }
    bool isFull() { return ((rear + 1) % SIZE == front); }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert.\n";
            return;
        }
        if (isEmpty()) front = rear = 0;
        else rear = (rear + 1) % SIZE;
        arr[rear] = x;
        cout << x << " inserted into circular queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Nothing to delete.\n";
            return;
        }
        cout << "Removed element: " << arr[front] << endl;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % SIZE;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Circular Queue elements are: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }

    void peek() {
        if (!isEmpty())
            cout << "Front element is: " << arr[front] << endl;
        else
            cout << "Queue is Empty!\n";
    }
};

int main() {
    CircularQueue cq;
    int choice, val;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue (Insert)\n2. Dequeue (Delete)\n3. Check if Empty\n4. Check if Full\n5. Display\n6. Peek (Front Element)\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; cq.enqueue(val); break;
            case 2: cq.dequeue(); break;
            case 3: cout << (cq.isEmpty() ? "Queue is Empty\n" : "Queue is NOT Empty\n"); break;
            case 4: cout << (cq.isFull() ? "Queue is Full\n" : "Queue is NOT Full\n"); break;
            case 5: cq.display(); break;
            case 6: cq.peek(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
Q3:)
#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    if (q.size() % 2 != 0) {
        cout << "Queue size must be even for interleaving!" << endl;
        return;
    }

    int n = q.size() / 2;
    queue<int> firstHalf;

    for (int i = 0; i < n; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front()); firstHalf.pop();
        q.push(q.front()); q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(4); q.push(7); q.push(11);
    q.push(20); q.push(5); q.push(9);

    cout << "Original Queue: 4 7 11 20 5 9\n";
    interleaveQueue(q);

    cout << "Queue after interleaving: ";
    while (!q.empty()) { cout << q.front() << " "; q.pop(); }
    cout << endl;

    return 0;
}
Q4:)
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string str) {
    unordered_map<char,int> freq;
    queue<char> q;

    cout << "Processing stream: " << str << endl;
    cout << "First non-repeating at each step: ";

    for (char ch : str) {
        freq[ch]++;
        q.push(ch);

        // Remove repeated characters
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) cout << "-1 ";
        else cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string str = "aabc";
    firstNonRepeating(str);
    return 0;
}
Q5.a)
#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front()); q1.pop();
        }
        swap(q1, q2);
        cout << x << " pushed into stack.\n";
    }

    void pop() {
        if (!q1.empty()) {
            cout << "Popped: " << q1.front() << endl;
            q1.pop();
        } else cout << "Stack Empty!\n";
    }

    int top() {
        return q1.empty() ? -1 : q1.front();
    }

    bool empty() { return q1.empty(); }
};

int main() {
    Stack s;
    s.push(10); s.push(20); s.push(30);
    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "Top after pop: " << s.top() << endl;
    return 0;
}
2:)
#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        // rotate older elements behind the new one
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << x << " pushed into stack.\n";
    }

    void pop() {
        if (!q.empty()) {
            cout << "Popped: " << q.front() << endl;
            q.pop();
        } else cout << "Stack Empty!\n";
    }

    int top() {
        return q.empty() ? -1 : q.front();
    }

    bool empty() { return q.empty(); }
};

int main() {
    Stack s;
    s.push(1); s.push(2); s.push(3);
    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "Top after pop: " << s.top() << endl;
    return 0;
}
*/