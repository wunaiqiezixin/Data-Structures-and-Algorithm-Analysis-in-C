typedef int ElementType;

/* insertion sort */
void
InsertionSort(ElementType A[], int N)
{
    int i, j, Tmp;
    /* ith pass */
    for (i = 1; i < N; i++)
    {
        Tmp = A[i];
        for (j = i; j > 0 && Tmp < A[j - 1]; j--)
            A[j] = A[j - 1];
        A[j] = Tmp;
    }
}
