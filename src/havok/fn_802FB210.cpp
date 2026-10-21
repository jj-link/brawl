#pragma force_active on
typedef struct Swap3 {
    int f0;
    int f4;
    int f8;
} Swap3;

extern "C" {
void fn_802FB210(Swap3* a, Swap3* b) {
    int t;
    t = a->f0;
    a->f0 = b->f0;
    b->f0 = t;
    t = a->f4;
    a->f4 = b->f4;
    b->f4 = t;
    t = a->f8;
    a->f8 = b->f8;
    b->f8 = t;
}
}
