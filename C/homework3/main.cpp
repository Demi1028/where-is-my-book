#include <iostream>
#include"linqueue.cpp"

using namespace std;

int main() {
    Queue q;
    InitQueue(&q);


    EnQueue(&q, 'a');
    EnQueue(&q, 'b');
    EnQueue(&q, 'c');
    EnQueue(&q, 'd');
    EnQueue(&q, 'e');
    EnQueue(&q, 'f');

    ReverseQueue(&q);

    printf("Reversed queue:\n");
    while (!QueueEmpty(&q)) {
        printf("%c ", DeQueue(&q));
    }

    return 0;
}
