#include <stdio.h>

void insertionSort(int arr[], int n, int *comparisons) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        (*comparisons)++; // Increment comparison count

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            (*comparisons)++; // Increment comparison count
        }

        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int option;
    int comparisons = 0;
    FILE *inputFile, *outputFile;

    printf("MAIN MENU (INSERTION SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    printf("Enter option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            inputFile = fopen("inAsce.dat", "r");
            outputFile = fopen("outInsAsce.dat", "w");
            break;
        case 2:
            inputFile = fopen("inDesc.dat", "r");
            outputFile = fopen("outInsDesc.dat", "w");
            break;
        case 3:
            inputFile = fopen("inRand.dat", "r");
            outputFile = fopen("outInsRand.dat", "w");
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid option\n");
            return 1;
    }

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    int arr[500]; // Assuming maximum size of 500
    int n = 0;

    while (fscanf(inputFile, "%d", &arr[n]) != EOF) {
        n++;
    }

    fclose(inputFile);

    printf("Before Sorting: ");
    printArray(arr, n);

    insertionSort(arr, n, &comparisons);

    printf("After Sorting: ");
    printArray(arr, n);

    printf("Number of Comparisons: %d\n", comparisons);

    // scenario based on the number of comparisons
    if (comparisons == n - 1) {
        printf("Scenario: Best-case\n");
    } else if (comparisons == (n * (n - 1)) / 2) {
        printf("Scenario: Worst-case\n");
    } else {
        printf("Scenario: Average-case\n");
    }

    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }

    fclose(outputFile);

    return 0;
}
