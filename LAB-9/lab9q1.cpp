#include <stdio.h>
//Logic implementation
int main() {
    int _TEST;
    scanf("%d", &_TEST); 

    while (_TEST--) {
        int num, queries,firstElement,currentElement;
        scanf("%d %d", &num, &queries);
        scanf("%d", &firstElement);
        for (int i = 1; i < num; i++) {
            scanf("%d", &currentElement);
        }
        while (queries--) {
            scanf("%d", &currentElement);
            // Print the minimum of (x-1) and y
            printf("%d ", (firstElement - 1 < currentElement) ? firstElement - 1 : currentElement);
        }
        printf("\n");
    }

    return 0;
}
