#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(long long int *)a - *(long long int *)b);
}

int minimum_energy_level(int N, int X, long long int energy_levels[]) {
    qsort(energy_levels, N, sizeof(long long int), compare); // Sort the energy levels in ascending order

    int low = 1; // Minimum possible energy level
    int high = energy_levels[N - X]; // Maximum possible energy level

    while (low < high) {
        int mid = low + (high - low) / 2; // Calculate the middle energy level
        int count = 0; // Counter to track the number of animals with energy levels greater than or equal to mid

        for (int i = N - X; i < N; i++) {
            if (energy_levels[i] < mid) {
                count++;
            }
        }

        if (count <= X) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low; // Minimum energy level `P` such that exactly `X` animals can be saved
}

int main() {
    int N, X;
    scanf("%d %d", &N, &X);

    long long int energy_levels[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &energy_levels[i]);
    }

    int result = minimum_energy_level(N, X, energy_levels);
    printf("%d\n", result);

    return 0;
}