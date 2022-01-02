/*  Program to multiply 2 2D arrays (matrices) using dynamic memory allocation
 *
 *  Working algo
 *  calloc returns 1D array memory block
 *  array of those calloc blocks create a 2D array
 */

# include <stdio.h>
# include <stdlib.h>

int row_matrix1 = 0, row_matrix2 = 0, row_matrix3 = 0, column_matrix1 = 0, column_matrix2 = 0, column_matrix3 = 0;

/*  intialize 2 matrices
    takes 2 integer pointer arrays as argument
    returns void */
void initialize_matrices(int *matrix1[row_matrix1], int *matrix2[row_matrix2])
{
    // initialize 1st matrix
    printf("\nEnter elements in %d X %d matrix:\n", row_matrix1, column_matrix1);
    for (int row = 0; row < row_matrix1; ++row)
        for (int column = 0; column < column_matrix1; ++column)
            scanf("%d", (matrix1[row] + column));

    // initialize 2nd matrix
    printf("\nEnter elements in %d X %d matrix:\n", row_matrix2, column_matrix2);
    for (int row = 0; row < row_matrix2; ++row)
        for (int column = 0; column < column_matrix2; ++column)
            scanf("%d", (matrix2[row] + column));
}

/*  display 2 matrices
    takes 2 int pointer arrays as input
    returns void */
void display_matrices(int *matrix1[row_matrix1], int *matrix2[row_matrix2])
{
    printf("\nThe Matrices are:\n");

    // display 1st matrix
    printf("1st Matrix:\n");
    for (int row = 0; row < row_matrix1; ++row)
    {
        for (int column = 0; column < column_matrix1; ++column)
            printf("%d ", *(matrix1[row] + column));
        printf("\n");
    }

    // display 2nd matrix
    printf("2nd Matrix:\n");
    for (int row = 0; row < row_matrix2; ++row)
    {
        for (int column = 0; column < column_matrix2; ++column)
            printf("%d ", *(matrix2[row] + column));
        printf("\n");
    }
}

/*  multiply 2 matrices and store the product in 3rd matrix
    takes 3 integer pointer arrays as argument
    returns void */
void multiply_matrices(int *matrix1[row_matrix1], int *matrix2[row_matrix2], int *matrix3[row_matrix3])
{
    for (int row = 0; row < row_matrix1; ++row)
        for (int column = 0; column < column_matrix2; ++column)
        {
            int sum = 0;
            for (int counter = 0; counter < row_matrix2; ++counter)
                sum += ((*(matrix1[row] + counter)) * (*(matrix2[counter] + column)));
            *(matrix3[row] + column) = sum;
        }
}

int main()
{   
    // take rows and columns
    printf("Matrix 1: \n");
    printf("Number of rows: ");
    scanf("%d", &row_matrix1);
    printf("Number of columns: ");
    scanf("%d", &column_matrix1);
    printf("Matrix 2: \n");
    printf("Number of rows: ");
    scanf("%d", &row_matrix2);
    printf("Number of columns: ");
    scanf("%d", &column_matrix2);

    // check if multiplication possible
    if (column_matrix1 != row_matrix2)
    {
        printf("Multiplication not possible!!");
        return 1;
    }

    row_matrix3 = row_matrix1;
    column_matrix3 = column_matrix2;

    // create arrays
    int *matrix1[row_matrix1], *matrix2[row_matrix2], *matrix3[row_matrix1];

    for (int row = 0; row < row_matrix1; ++row)
        matrix1[row] = (int *)calloc(column_matrix1, sizeof(int));
    for (int row = 0; row < row_matrix2; ++row)
        matrix2[row] = (int *)calloc(column_matrix2, sizeof(int));
    for (int row = 0; row < row_matrix3; ++row)
        matrix3[row] = (int *)calloc(column_matrix3, sizeof(int));

    initialize_matrices(matrix1, matrix2);
    display_matrices(matrix1, matrix2);
    multiply_matrices(matrix1, matrix2, matrix3);

    // display product
    printf("\nProduct of the matrices:\n");
    for(int row = 0; row < row_matrix3; ++row)
    {
        for(int column = 0; column < column_matrix3; ++column)
            printf("%d ", *(matrix3[row] + column));
        printf("\n");
        // free memory
        matrix3[row] = realloc(matrix3[row], 0);
    }

    // free memory
    free(matrix1);
    free(matrix2);

    return 0;
}