#pragma force_active on
struct S {
    int pad[2];
    int f8;
};

extern "C" void* fn_27_29595C(S* p, int idx) {
    int n = (p->f8 >> 26) + idx;
    if (n >= 31) {
        n -= 31;
    }
    return (char*)p + n * 4 + 12;
}
