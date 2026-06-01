
typedef struct Node {
    char value;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* newStack();
bool isEmpty(Stack* stack);
void pushStack(Stack* stack, char value);
Node* popStack(Stack* stack);
void printStack(Stack* stack);
void freeAll(Stack* stack);
