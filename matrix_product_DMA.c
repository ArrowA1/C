// Program to multiply 2 2D arrays using dynamic memory allocation

# include <stdio.h>
# include <stdlib.h>

// Working algo
// calloc returns 1D array memory block
// array of those calloc blocks create a 2D array

int row_ar1 = 0, row_ar2 = 0, row_ar3 = 0, column_ar1 = 0, column_ar2 = 0, column_ar3 = 0;

void initialize(int *array1[row_ar1], int *array2[row_ar2])
{
    // initialize array 1
    printf("Enter elements in 1st array:\n");
    for (int row = 0; row < row_ar1; ++row)
        for (int column = 0; column < column_ar1; ++column)
            scanf("%d", (array1[row] + column));

    // initialize array 2
    printf("Enter elements in 2nd array:\n");
    for (int row = 0; row < row_ar2; ++row)
        for (int column = 0; column < column_ar2; ++column)
            scanf("%d", (array2[row] + column));
}

void multiply(int *array1[row_ar1], int *array2[row_ar2], int *array3[row_ar3])
{
    for (int row = 0; row < row_ar1; ++row)
        for (int column = 0; column < column_ar2; ++column)
        {
            int sum = 0;
            for (int counter = 0; counter < row_ar2; ++counter)
                sum += ((*(array1[row] + counter)) * (*(array2[counter] + column)));
            *(array3[row] + column) = sum;
        }

}

int main()
{   
    // take rows and columns
    printf("Matrix 1: \n");
    printf("Number of rows: ");
    scanf("%d", &row_ar1);
    printf("Number of columns: ");
    scanf("%d", &column_ar1);
    printf("Matrix 2: \n");
    printf("Number of rows: ");
    scanf("%d", &row_ar2);
    printf("Number of columns: ");
    scanf("%d", &column_ar2);

    // check if multiplication possible
    if (column_ar1 != row_ar2)
    {
        printf("Multiplication not possible!!");
        return 0;
    }
    row_ar3 = row_ar1;
    column_ar3 = column_ar2;

    // create arrays
    int *array1[row_ar1], *array2[row_ar2], *array3[row_ar1];
    for (int row = 0; row < row_ar1; ++row)
        array1[row] = (int *)calloc(column_ar1, sizeof(int));
    for (int row = 0; row < row_ar2; ++row)
        array2[row] = (int *)calloc(column_ar2, sizeof(int));
    for (int row = 0; row < row_ar3; ++row)
        array3[row] = (int *)calloc(column_ar3, sizeof(int));

    initialize(array1, array2);
    multiply(array1, array2, array3);

    // display product
    for(int row = 0; row < row_ar3; ++row)
    {
        for(int column = 0; column < column_ar3; ++column)
            printf("%d ", *(array3[row] + column));
        printf("\n");
        array3[row] = realloc(array3[row], 0);
    }

    // free memory
    free(array1);
    free(array2);

    return 0;
}