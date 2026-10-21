#pragma force_active on
typedef int (*Compare)(unsigned int, unsigned int);

extern "C" void fn_801AD9E0(unsigned int* a, unsigned int* b,
                            unsigned int* c, Compare* compare) {
    int first = !(*compare)(*c, *a);
    int second = !(*compare)(*b, *c);

    if (first && second) {
        return;
    }

    if (!first && !second) {
        unsigned int temp = *a;
        *a = *b;
        *b = temp;
    } else {
        if ((*compare)(*b, *a)) {
            unsigned int temp = *a;
            *a = *b;
            *b = temp;
        }

        if (first) {
            unsigned int temp = *b;
            *b = *c;
            *c = temp;
        } else {
            unsigned int temp = *a;
            *a = *c;
            *c = temp;
        }
    }
}
