#include <cstdio> // scanf, printf 사용
using namespace std;

class Stack;
class Node {
private:
    Node* next;
    int data;
public:
    Node(int d) : data(d), next(nullptr) {}
    friend class Stack;
};

class Stack {
private:
    Node* top_node;
    int N;
public:
    Stack();
    void push(int X);
    void pop();
    void size();
    bool emp();
    void top();
    void empty();
};

Stack::Stack() : N(0), top_node(nullptr) {}

void Stack::push(int X) {
    Node* new_node = new Node(X);
    new_node->next = top_node;
    top_node = new_node;
    N++;
}

void Stack::pop() {
    if (emp()) {
        printf("-1\n");
        return;
    }
    Node* erase_node = top_node;
    top_node = top_node->next;
    printf("%d\n", erase_node->data);
    delete erase_node;
    N--;
}

void Stack::empty() {
    if (emp()) {
        printf("1\n");
    } else {
        printf("0\n");
    }
}

void Stack::size() {
    printf("%d\n", N);
}

bool Stack::emp() {
    return (N == 0);
}

void Stack::top() {
    if (emp()) {
        printf("-1\n");
    } else {
        printf("%d\n", top_node->data);
    }
}

int main() {
    int n, num, str;
    scanf("%d", &n);
    Stack stk;

    for (int i = 0; i < n; i++) {
        scanf("%d", &str);
        if (str == 1) {
            scanf("%d", &num);
            stk.push(num);
        } else if (str == 5) {
            stk.top();
        } else if (str == 3) {
            stk.size();
        } else if (str == 2) {
            stk.pop();
        } else if (str == 4) {
            stk.empty();
        }
    }
    return 0;
}

