#include "../includes/cvec.h"

int main()
{
    cvec(float) vec;
    cvec_init(&vec);

    printf("Initial state: ");
    if (vec.size == 0)
    {
        printf("empty\n");
    }

    cvec_push(&vec, 53.12f);
    cvec_push(&vec, 23.1f);
    cvec_push(&vec, 93325.143f);
    cvec_push(&vec, 6.954f);

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

    cvec_free(&vec);
    return 0;
}
