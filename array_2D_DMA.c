// Program to create a size X size array using dynamic memory allocation
// size = 3

# include <stdio.h>
# include <stdlib.h>

// Working algo
// calloc returns 1D array memory block
// array of those calloc blocks create a 2D array
# define size 3

int main()
{   
    // create 2D array dynamically
    int *array[size];
    for (int row = 0; row < size; ++row)
    {
        array[row] = (int *)calloc(size, sizeof(int));
    }

    // input values into the array
    printf("Enter elements in 3 X 3 array:\n");
    for(int row = 0; row < size; ++row)
    {
        for(int column = 0; column < size; ++column)
        {
            scanf("%d", (array[row] + column));
        }
    }

    // print the contents of the array
    for(int row = 0; row < size; ++row)
    {
        for(int column = 0; column < size; ++column)
        {
            printf("%d ", *(array[row] + column));
        }
        printf("\n");
        array[row] = realloc(array[row], 0);
    }
    
    return 0;
}