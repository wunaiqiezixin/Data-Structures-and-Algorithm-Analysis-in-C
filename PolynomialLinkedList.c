
typedef struct Node* PtrToNode;

struct Node
{
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};

typedef PtrToNode Polynomial; /* Nodes sorted by exponent */

void 
ZeroPolynomial(Polynomial Poly)
{
    Polynomial P;

    P = Poly;
    while (P)
    {
        P->Exponent = 0;
        P->Coefficient = 0;
        P = P->Next;
    }
}

