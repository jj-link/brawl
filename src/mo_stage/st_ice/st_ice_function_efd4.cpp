#pragma force_active on
struct S {
    int a;
    int b;
    unsigned c : 6;
    unsigned d : 1;
    unsigned e : 25;
};

extern "C" unsigned fn_62_EFD4(S* s) {
    return s->d;
}
