#include <stdio.h>

/*
struct foo {
    int num;
    double fl;
    char ch;
};

void printVariables(struct foo *f) {
    f->num = 10;
    f->fl = 3.14;
    f->ch = 'A';
    printf("Number: %d\nFloat: %f\nCharacter: %c\n", f->num, f->fl, f->ch);
}

int main() {
    struct foo f;

    printVariables(&f);
    return 0;
}
*/


void assignVariables(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        *(arr + i) = (i + 1) * 10;
    }
}


void reverse(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;

    while(start < end) {
        int tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
}


void findMax(int *arr, int size) {
    int max = *arr;
    int *next = arr;

    for(int i = 0; i < size; i++) {
        if(*next > max) {
            max = *next;
        }
        next++;
    }
    printf("\nMax value: %d\n", max);
    printf("\n");


    int secondMax = -1;
    next = arr;

    for(int i = 0; i < size; i++) {
        if(*next > secondMax && *next < max) {
            secondMax = *next;
        }
        next++;
    }
    printf("Second max value: %d", secondMax);
    printf("\n");
}


void findMin(int *arr, int size) {
    int min = *arr;
    int *next = arr;

    for(int i = 0; i < size; i ++) {
        if(*next < min) {
            min = *next;
        }
        next++;
    }
    printf("\nMin value: %d\n", min);
    printf("\n");
}


double findAverage(int *arr, int size) {
    int sum = 0;
    int *num = arr;

    for(int i = 0; i < size; i++) {
        sum += *num;
        num++;
    }
    return (double)sum / size;
}


void printArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void evenOdd(int *arr, int size) { 
    int even = 0;
    int odd = 0;
    int *num = arr;

    for(int i = 0; i < size; i++) {
        if(*num % 2) {
            odd++;
        } else {
            even++;
        }
        num++;
    }
    printf("Even numbers: %d\n", even);
    printf("Odd numbers: %d\n", odd);
}


void findMedian(int *arr, int size) {
    double median = 0;

    if(size % 2 == 0) {
        median = (*(arr + size / 2) + *(arr + (size / 2) - 1)) / 2.0;
    } else {
        median = *(arr + size / 2);
    }
    printf("Median: %.2f\n", median);
}


void MFE(int *arr, int size) {
    int mfe = -1;
    int maxCount = 0;

    for(int i = 0; i < size; i++) {
        int *ptr = arr;
        int count = 0;
        for(int j = 0; j < size; j++) {
            if(*(ptr + i) == *(ptr + j)) {
                count++;
            }
        }
        if(count > maxCount) {
            maxCount = count;
            mfe = *(ptr + i);
        }
    }
    if (maxCount == 1) {
        printf("Mode: No mode (all numbers are unique)\n");
    } else {
        printf("Mode: %d (appears %d times)\n", mfe, maxCount);
    }
}


void sortArray(int *arr, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}


int main(){
    int arr[5];

    assignVariables(arr, 5);

    printf("\nOriginal array: \n");
    printArray(arr, 5);

    reverse(arr, 5);
    printf("\nNew: array: \n");
    printArray(arr, 5);

    findMax(arr, 5);
    findMin(arr, 5);
    findAverage(arr, 5);

    double average = findAverage(arr, 5);
    printf("Average: %.2f\n", average);

    evenOdd(arr, 5);
    findMedian(arr, 5);
    MFE(arr, 5);

    sortArray(arr, 5);
    printf("\nNew: array: \n");
    printArray(arr, 5);
}