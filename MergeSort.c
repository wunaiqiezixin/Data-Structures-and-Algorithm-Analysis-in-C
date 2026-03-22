typedef int ElementType;

void
MergeSort(ElementType A[], int N)
{
    ElementType* tempArray = (ElementType*)malloc(sizeof(ElementType) * N);
    //todo: tempArray is a nullptr.

    MSort(A, 0, N - 1, tempArray);
    free(tempArray);
}

void
MSort(ElementType A[], int Left, int Right, ElementType tempArray[])
{
    int Center;
    if (Left < Right)
    {
        Center = Left + (Right - Left) / 2;
        MSort(A, Left, Center, tempArray);
        MSort(A, Center + 1, Right, tempArray);
        Merge(A, Left, Right, tempArray);
    }
}

void 
Merge(ElementType A[], int Left, int Right, ElementType tempArray[])
{
    int Center = Left + (Right - Left) / 2;

    int pLeft = Left, pRight = Center + 1;
    int pTemp = 0;

    while (pLeft <= Center && pRight <= Right)
    {
        if (A[pLeft] <= A[pRight])
            tempArray[pTemp++] = A[pLeft++];
        else
            tempArray[pTemp++] = A[pRight++];
    }
    while (pLeft <= Center)
        tempArray[pTemp++] = A[pLeft++];
    while (pRight <= Right)
        tempArray[pTemp++] = A[pRight++];
    
    for (int i = 0; i < pTemp; i++)
        A[Left + i] = tempArray[i];
}
