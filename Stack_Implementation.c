#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Stack
{
    int *arr;
    int *minarr;
    int *maxarr;
    int top;
    int capacity;
} Stack;

Stack *Stackcreate(int size)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(size * sizeof(int));
    stack->minarr = (int*)malloc(size * sizeof(int));
    stack->maxarr = (int*)malloc(size * sizeof(int));

    if (!stack->arr || !stack->minarr || !stack->maxarr) 
    {
        printf("Memory allocation failed for stack arrays!\n");
        free(stack->arr);
        free(stack->minarr);
        free(stack->maxarr);
        free(stack);
        return NULL;
    }

    stack->top = -1;
    stack->capacity = size;
    return stack;
}

int isEmpty(Stack *stack) 
{
    return stack->top == -1;
}

int isFull(Stack *stack) 
{
    return stack->top == stack->capacity - 1;
}

void push(Stack *stack, int value) 
{
    if (!stack) return; // To Check for Null

    if (isFull(stack)) 
    {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }

    stack->arr[++stack->top] = value;
    printf("Pushed successfully!\n");

    if (stack->top == 0) 
    {
        stack->minarr[stack->top] = value;
        stack->maxarr[stack->top] = value;
    } 
    else 
    {
        stack->minarr[stack->top] = (value < stack->minarr[stack->top - 1]) ? value : stack->minarr[stack->top - 1];
        stack->maxarr[stack->top] = (value > stack->maxarr[stack->top - 1]) ? value : stack->maxarr[stack->top - 1];
    }
}

void pop(Stack *stack)
{
    if (!stack) return; // To Check for Null

    if (isEmpty(stack)) 
    {
        printf("Stack underflow! Cannot pop\n");
        return;
    }
    stack->top--; // Changing the index, not erasing the value
    printf("Popped successfully!\n");
}

int top(Stack *stack) 
{
    if (!stack || isEmpty(stack)) 
    {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->arr[stack->top];
}

int getMin(Stack *stack) 
{
    if (!stack || isEmpty(stack)) 
    {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->minarr[stack->top];
}

int getMax(Stack *stack) 
{
    if (!stack || isEmpty(stack)) 
    {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->maxarr[stack->top];
}

//This function is used to free the stack memory after we are done using it
void freeStack(Stack* stack) 
{
    if (!stack) return; // Null check

    free(stack->arr);
    free(stack->minarr);
    free(stack->maxarr);
    free(stack);
}

int main()
{
    Stack *stack = Stackcreate(100);
    if(!stack) return 1; // This will exit in case memory allocation fails
    int num,chk=1,choice,Top,min,max;
    while(chk!=0)
    {
        printf("1. Push\n2. Pop\n3. Top\n4. Minimum\n5. Maximum\n6. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter number to be pushed:\n");
                scanf("%d",&num);
                push(stack,num);
                printf("\n");
                break;
            case 2:
                pop(stack);
                printf("\n");
                break;
            case 3:
                Top = top(stack);
                if(Top != INT_MIN)
                {
                    printf("The top most element is: %d\n",Top);    
                }
                printf("\n");
                break;
            case 4:
                min = getMin(stack);
                if(min != INT_MIN)
                {
                    printf("The Minimum is: %d\n",min);
                }
                printf("\n");
                break;
            case 5:
                max = getMax(stack);
                if(max != INT_MIN)
                {
                    printf("The Maximum is: %d\n",max);
                }
                printf("\n");
                break;
            case 6:
                chk=0;
                freeStack(stack);
                break;
            default:
                printf("Invalid Choice\n");
                break;    
        }
    }
    return 0;
}