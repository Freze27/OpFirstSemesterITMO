#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[] = {0,0,0,0};

    for (int i = 0, j = 50; i < 4; i++, j -= 10) {
        arr[i] = j;
    }
    for (int i = 0; i < 4; i++) {
        printf("%d ",i);
        printf("%d\n",*(arr+i));
    }
    printf("\n");
    int *t = malloc(4*sizeof(int));
    for (int i = 0, j = 50; i < 4; i++, j -= 10) {
        *(t+i)=j;
    }
    for (int i = 0; i < 4; i++) {
        printf("%d ",i);
        printf("%d\n",*(t+i));
    }
    free(t);
    return 0;
}
