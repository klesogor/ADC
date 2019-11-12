struct Buffer
{
    int disposed;
    int size;
    int* array;
    int* currentWrite;
    int* currentRead;
};

int next(Buffer* b);
void add(Buffer* b, int value);
int avg(Buffer* b);
bool dispose(Buffer* b);

Buffer newBuffer(int size);
