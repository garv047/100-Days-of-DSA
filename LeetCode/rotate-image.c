void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    int temp;

    // Step 1: Transpose the matrix
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = i + 1; j < matrixSize; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Step 2: Reverse every row
    for (int i = 0; i < matrixSize; i++)
    {
        int left = 0;
        int right = matrixSize - 1;

        while (left < right)
        {
            temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;

            left++;
            right--;
        }
    }
}
