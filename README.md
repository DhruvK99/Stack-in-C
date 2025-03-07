Stack Implementation in C

Description:

This project implements a stack data structure in C with enhanced functionality to efficiently track the minimum and maximum elements 
at any given time. A stack is a Last-In-First-Out (LIFO) data structure where elements are added and removed from the same end, 
called the "top" of the stack. This implementation includes standard stack operations such as push, pop, and top, as well as 
additional features to retrieve the smallest and largest elements in constant time.

The stack is implemented using dynamic memory allocation to ensure efficient memory usage. 
It maintains three arrays internally:

arr: Stores the stack elements.
minarr: Keeps track of the minimum element at each stack level.
maxarr: Keeps track of the maximum element at each stack level.

When a new element is pushed, the minarr and maxarr arrays are updated accordingly to ensure that retrieving the minimum or maximum 
value is an O(1) operation. The implementation also includes proper error handling to prevent stack overflow and underflow issues.
This stack implementation can be useful in scenarios where quick access to the minimum and maximum values is required.

Features:

Stack operations: Push, Pop, Top
Gets minimum and maximum elements in constant time.
Handles stack overflow, underflow conditions and prints appropriate error message when stack is empty.
Provides a menu-driven interface for user interaction.

Functions:

Stack *Stackcreate(int size): Creates and initializes a stack of given size.
int isEmpty(Stack *stack): Checks if the stack is empty.
int isFull(Stack *stack): Checks if the stack is full.
void push(Stack *stack, int value): Pushes a value onto the stack and updates min/max arrays.
void pop(Stack *stack): Removes the top element from the stack.
int top(Stack *stack): Returns the top element of the stack.
int getMin(Stack *stack): Retrieves the minimum element in the stack.
int getMax(Stack *stack): Retrieves the maximum element in the stack.
void freeStack(Stack* stack): Frees allocated memory for the stack.