#include "../includes/cvec.h"

int main()
{
    cvec(float) vec;

    printf("Initial state: ");
    if (vec.size == 0)
    {
        printf("empty\n");
    }

    cvec_push(&vec, 53.13267);
    cvec_push(&vec, 23.3);
    cvec_push(&vec, 93325.11);
    cvec_push(&vec, 6.996);

    printf("After pushing values: ");
    for (size_t i = 0; i < vec.size; ++i)
    {
        if (i != vec.size - 1)
            printf("%f, ", vec.data[i]);
        else
            printf("%f\n", vec.data[i]);
    }

    cvec_pop(&vec);
    cvec_pop(&vec);

    printf("After popping values: ");
    for (size_t i = 0; i < vec.size; ++i)
    {
        if (i != vec.size - 1)
            printf("%f, ", vec.data[i]);
        else
            printf("%f\n", vec.data[i]);
    }

    cvec_clear(&vec);

    printf("After clearing: ");
    if (vec.size == 0)
    {
        printf("empty\n");
    }

    return 0;
}
