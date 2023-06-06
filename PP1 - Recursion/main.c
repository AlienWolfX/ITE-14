#include <stdio.h>

int permutation(int n, int k) {
    if (k == 0)
        return 1;
    else
        return n * permutation(n - 1, k - 1);
}

int main() {
    int n = 6, k = 2, p;
    p = permutation(n, k);
    printf("%d\n", p);
    return 0;
}
