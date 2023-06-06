#include <stdio.h>

void insertionSort(char *arr, int n) {
    char *i, *j, key;
    for (i = arr + 1; i < arr + n; i++) {
        key = *i;
        j = i - 1;

        while (j >= arr && *j > key) {
            *(j + 1) = *j;
            j--;
        }
        *(j + 1) = key;
    }
}

int main() {
    char arr[100];
    int n, i;

    printf("Enter the number of characters: ");
    scanf("%d", &n);

    printf("Enter the characters:\n");
    for (i = 0; i < n; i++) {
        scanf(" %c", arr + i);
    }

    insertionSort(arr, n);

    printf("Sorted characters in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%c ", *(arr + i));
    }
    printf("\n");

    return 0;
}
