#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int sekv_pret(float V[], int n, float x) {
    for (int i = 0; i < n; i++) {
        if (V[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    time_t  t1, t2;
    srand((unsigned)time(NULL));
    int n = rand() % 1000000;
    float* V = (float*)malloc(n * sizeof(float));
    if (V == NULL) {
        return -1;
    }
    float x = rand() % n;


    for (int i = 0; i < n; i++) {
        V[i] = rand() % n;
    }

    t1 = clock();
    int result = sekv_pret(V, n, x);
    t2 = clock();

    if (result == -1) {
        printf("Element nije pronaden.\n");
    }
    else {
        printf("Element na indexu %d.\n", result);
    }
    printf("Vrijeme trajanja je % ldms\n", t2 - t1);
    printf("broj elemenata %d", n);

    free(V);

    return 0;
}
