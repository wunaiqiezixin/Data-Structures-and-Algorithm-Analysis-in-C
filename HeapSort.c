typedef int ElementType;

/* percolate down */
#define LeftChild(i) (2 * (i) + 1)
void
percoDown(ElementType A[], int N, int i)
{
    ElementType Tmp;
    int child;

    for (Tmp = A[i]; LeftChild(i) < N; i = child)
    {
        /* find greater child */
        child = LeftChild(i);
        if (child != N - 1 && A[child] < A[child + 1])
            child++;

        if (Tmp < A[child])
            A[i] = A[child];
        else
            break;
    }
    A[i] = Tmp;
}
/* heap sort */
void
HeapSort(ElementType A[], int N)
{
    int i;
    /* build heap */
    for (i = N / 2; i >= 0; i--)
        percoDown(A, N, i);
    /* sort */
    for (i = N - 1; i > 0; i--)
    {
        Swap(&A[i], &A[0]);
        percoDown(A, i, 0);
    }
}
