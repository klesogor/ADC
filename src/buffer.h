struct Buffer
{
    int disposed;
    int size;
    int* array;
    int* currentWrite;
    int* currentRead;
};

int next(struct Buffer* b);
void add(struct Buffer* b, int value);
int avg(struct Buffer* b);
void dispose(struct Buffer* b);

struct Buffer newBuffer(int size);
