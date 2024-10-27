#include <stdio.h>

// pointer function to change the value
void changeValue(int *num) {
    printf("Inside the function, before change:\n");
    printf("number = %d\n", *num);
    
    // lets change it to 15
    *num += 15;
    
    printf("Inside the function, after change:\n");
    printf("number = %d\n", *num);
}

int main() {

    // variable initialized
    int number = 5;
    printf("Before calling the function:\n");
    printf("number = %d\n", number);
    
    // function call
    changeValue(&number);
    
    // print the value after the function call
    printf("After calling the function:\n");
    printf("number = %d\n", number);
    
    // initialize an array
    int array[5] = {10, 20, 30, 40, 50};
    int *ptr = array;
    
    // displas the 5th element in four different ways
    printf("\nAccessing the 5th element:\n");
    printf("Using array[4]: %d\n", array[4]);
    printf("Using *(array + 4): %d\n", *(array + 4));
    printf("Using ptr[4]: %d\n", ptr[4]);
    printf("Using *(ptr + 4): %d\n", *(ptr + 4));
    
    // display the entire array in four different ways
    printf("\nDisplaying the entire array:\n");
    printf("Using array[i]: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    
    printf("\nUsing *(array + i): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(array + i));
    }
    
    printf("\nUsing ptr[i]: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }
    
    printf("\nUsing *(ptr + i): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    
    // print the addresses of each element in the array
    printf("\n\nMemory addresses of each element:\n");
    for (int i = 0; i < 5; i++) {
        printf("&array[%d] = %p\n", i, (void*)&array[i]);
    }
    
    return 0;
}

