#include "Stack.h"
#define STACK_SIZE  10

int first;
int stack[STACK_SIZE];

void stackstart()
{
    first = 0;
}

bool stackpush(int element)
{
    if (first == STACK_SIZE)
        return false;
    else{
    stack[first] = element;
    first++;
    return true;
    }
}

bool stackfull()
{
    return first == STACK_SIZE;
}

bool stackpop(int* element)
{
    if (first == 0)
        return false;
	  else{
    first--;
    *element = stack[first];
    return true;
	}
}

bool stackempty()
{
    return first == 0;
}

