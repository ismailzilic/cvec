#ifndef CVEC_H
#define CVEC_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CVEC_GROWTH_FACTOR 2

#define cvec(T)          \
    struct               \
    {                    \
        T *data;         \
        size_t size;     \
        size_t capacity; \
    }

#define cvec_init(v)                                            \
    do                                                          \
    {                                                           \
        (v)->data = NULL;                                       \
        (v)->size = 0;                                          \
        (v)->capacity = 0;                                      \
        cvec__init((void **)&(v)->data, sizeof(*(v)->data), 1); \
    } while (0)

#define cvec_push(v, val)                                                          \
    do                                                                             \
    {                                                                              \
        if ((v)->size >= (v)->capacity)                                            \
            cvec__expand((void **)&(v)->data, &(v)->capacity, sizeof(*(v)->data)); \
        (v)->data[(v)->size++] = (val);                                            \
    } while (0)

#define cvec_pop(v)                                        \
    do                                                     \
    {                                                      \
        if ((v)->size > 0)                                 \
            --(v)->size;                                   \
        else                                               \
            fprintf(stderr, "cvec_pop(): empty vector\n"); \
    } while (0)

#define cvec_free(v)       \
    do                     \
    {                      \
        free((v)->data);   \
        (v)->data = NULL;  \
        (v)->size = 0;     \
        (v)->capacity = 0; \
    } while (0)

static int cvec__init(void **data, size_t elem_size, size_t init_cap)
{
    *data = malloc(elem_size * init_cap);

    if (!*data)
    {
        fprintf(stderr, "cvec_init(): malloc failed\n");
        return 1;
    }

    *(size_t *)(data + sizeof(void *)) = init_cap;

    return 0;
}

static int cvec__expand(void **data, size_t *cap, size_t elem_size)
{
    size_t new_cap = (*cap ? *cap : 1) * CVEC_GROWTH_FACTOR;
    void *new_data = realloc(*data, elem_size * new_cap);

    if (!new_data)
    {
        fprintf(stderr, "cvec_expand(): realloc failed\n");
        return 1;
    }

    *data = new_data;
    *cap = new_cap;

    return 0;
}

#undef CVEC_GROWTH_FACTOR

#endif // CVEC_H
