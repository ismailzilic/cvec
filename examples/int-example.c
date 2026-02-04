#include "../includes/cvec.h"

int main()
{
    cvec(size_t) vec;
    cvec_init(&vec);

    printf("Initial state: ");
    if (vec.size == 0)
    {
        printf("empty\n");
    }

    cvec_push(&vec, 53);
    cvec_push(&vec, 23);
    cvec_push(&vec, 93325);
    cvec_push(&vec, 6);

    printf("After pushing values: ");
    for (size_t i = 0; i < vec.size; ++i)
    {
        if (i != vec.size - 1)
            printf("%d, ", vec.data[i]);
        else
            printf("%d\n", vec.data[i]);
    }

    cvec_pop(&vec);
    cvec_pop(&vec);

    printf("After popping values: ");
    for (size_t i = 0; i < vec.size; ++i)
    {
        if (i != vec.size - 1)
            printf("%d, ", vec.data[i]);
        else
            printf("%d\n", vec.data[i]);
    }

    cvec_free(&vec);
    return 0;
}
