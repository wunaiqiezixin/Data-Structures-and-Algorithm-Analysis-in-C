typedef int ElementType;

ElementType
Median3(ElementType A[], int Left, int Right)
{
    int Center = Left + (Right - Left) / 2;
    if (A[Left] > A[Center])
        Swap(&A[Left], &A[Center]);
    if (A[Left] > A[Right])
        Swap(&A[Left], &A[Right]);
    if (A[Center] > A[Right])
        Swap(&A[Center], &A[Right]);

    /* A[Left] <= A[Center] <= A[Right] */

    Swap(&A[Right - 1], &A[Center]);

    return A[Right - 1];
}

void
QuickSort(ElementType A[], int N)
{
    qSort(A, 0, N - 1);
}

#define CutOff (3)
void 
qSort(ElementType A[], int Left, int Right)
{
    if (Left + CutOff < Right)
    {
        int pivot = Median3(A, Left, Right);
        int i = Left, j = Right - 1;
        
        for (;;)
        {
            while (A[++i] < pivot);
            while (A[--j] > pivot);

            if (i < j)
                Swap(&A[i], &A[j]);
            else
                break;
        }
        /* restore pivot */
        Swap(&A[i], &A[Right - 1]);

        qSort(A, Left, i - 1);
        qSort(A, i + 1, Right);
    }
    else/* Do an insertion sort on the subarray */
        InsertionSort(A + Left, Right - Left + 1);
}