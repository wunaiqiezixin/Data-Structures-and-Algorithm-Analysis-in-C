typedef int ElementType;

/* shell sort with sell increment */
void
ShellSort(ElementType A[], int N)
{
    int Increment;
    int i, j;
    ElementType Tmp;

    for (Increment = N / 2; Increment > 0; Increment /= 2)
    {
        for (i = Increment; i < N; i++)
        {
            Tmp = A[i];
            for (j = i; j >= Increment; j -= Increment)
            {
                if (Tmp < A[j - Increment])
                    A[j] = A[j - Increment];
                else
                    break;
            }
            A[j] = Tmp;
        }
    }
}