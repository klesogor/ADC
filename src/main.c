#include "buffer.h"
#include "stdio.h"

void main(){
    struct Buffer buf = newBuffer(8);
    printf("Empty buff avg:%i\n", avg(&buf));
    for(int i = 0; i <= 8; i++){
        add(&buf,i);
    }
    printf("Filled buf avg:%i\n", avg(&buf));
}