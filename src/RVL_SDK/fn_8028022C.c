#pragma force_active on
struct Foo {
    int* array;
    int count;
};

void fn_8028022C(struct Foo** arg) {
    int* end = (*arg)->array + (*arg)->count;
    int* p = (*arg)->array;
    while (p != end) {
        if (*p >= 0) {
            while ((*arg)->array[*p] >= 0) {
                *p = (*arg)->array[*p];
            }
        }
        p++;
    }
}
