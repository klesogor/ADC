#include "buffer.h"
#include "stdlib.h"
#include "stdio.h"

int *nextPointer(int *start, int size, int *current)
{
    int *next = current + 1;
    if (next >= start + size)
    {
        return start;
    }
    return next;
}

int next(struct Buffer *b)
{
    if (b->disposed)
    {
        return -1;
    }
    b->currentRead = nextPointer(b->array, b->size, b->currentRead);
    return *b->currentRead;
}

void add(struct Buffer *b, int value)
{
    if (b->disposed)
    {
        return;
    }
    *b->currentWrite = value;
    b->currentWrite = nextPointer(b->array, b->size, b->currentWrite);
}

int avg(struct Buffer *b)
{
    if (b->disposed)
    {
        return -1;
    }
    int result = 0;
    for (int i = 0; i < b->size; i++)
    {
        printf("I:%i, V:%i\n",i,b->array[i]);
        result += b->array[i];
    }

    return result / b->size;
}

void dispose(struct Buffer *b)
{
    b->disposed = 1;
    free(b->array);
}

struct Buffer newBuffer(int size)
{
    struct Buffer buf;
    buf.disposed = 0;
    buf.size = size;
    int *array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
    buf.array = array;
    buf.currentRead = array;
    buf.currentWrite = array;
    return buf;
}