#pragma force_active on

struct S {
    float f;
    unsigned short a, b, c, d;
};

typedef int (*Cmp)(S*, S*);

static inline void Swap(S* x, S* y) {
    S t = *x;
    *x = *y;
    *y = t;
}

extern "C" void fn_801A72F0(S* a, S* b, S* c, Cmp* cmp) {
    int first = !(*cmp)(c, a);
    int second = !(*cmp)(b, c);

    if (first && second) {
        return;
    }

    if (!first && !second) {
        Swap(a, b);
    } else {
        if ((*cmp)(b, a)) {
            Swap(a, b);
        }

        if (first) {
            Swap(b, c);
        } else {
            Swap(a, c);
        }
    }
}
