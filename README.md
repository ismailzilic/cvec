# cvec (or C vector)

My attempt on recreating the std::vector from C++ standard library in C.

## API:

```
cvec(T) -> std::vector<T>
cvec_push(&vector, value) -> std::vector::push_back()
cvec_pop(&vector) -> std::vector::pop_back()
cvec_clear(&vector) -> std::vector::clear()
```
