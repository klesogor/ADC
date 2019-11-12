struct Buffer
{
    bool disposed;
    int size;
    int* array;
    int* current;
};

int next(Buffer* b);
void add(Buffer* b);
int avg(Buffer* b);

Buffer newBuffer(int size);
