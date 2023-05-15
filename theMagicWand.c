#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long int minCost(int arr[], int N, int query) {
    long long int cost = 0;

    for (int i = 0; i < N; i++) {
        cost += labs(arr[i] - query);
    }

    return cost;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int queries[M];
    for (int i = 0; i < M; i++) {
        scanf("%d", &queries[i]);
    }

    long long int costs[M];
    for (int i = 0; i < M; i++) {
        costs[i] = minCost(arr, N, queries[i]);
    }

    for (int i = 0; i < M; i++) {
        printf("%lld ", costs[i]);
    }
    printf("\n");

    return 0;
}